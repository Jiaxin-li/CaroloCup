/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <iostream>

#include "core/base/KeyValueConfiguration.h"
#include "core/data/Container.h"
#include "core/data/image/SharedImage.h"
#include "core/wrapper/SharedMemoryFactory.h"

#include "VCR.h"

namespace msv {

    using namespace std;
    using namespace core::base;
    using namespace core::data;
    using namespace core::data::image;

    VCR::VCR(const int32_t &argc, char **argv) : ConferenceClientModule(argc, argv, "VCR"),
	    m_hasAttachedToSharedImageMemory(false),
        m_sharedImageMemory(),
	    m_image(NULL),
        m_cameraId(-1),
        m_debug(false),
        m_writer(NULL) {}

    VCR::~VCR() {}

    void VCR::setUp() {
	    // This method will be call automatically _before_ running body().

	    if (m_debug) {
		    // Create an OpenCV-window.
		    cvNamedWindow("WindowShowImage", CV_WINDOW_AUTOSIZE);
		    cvMoveWindow("WindowShowImage", 300, 100);
	    }
    }

    void VCR::tearDown() {
	    // This method will be call automatically _after_ return from body().

	    if (m_image != NULL) {
		    cvReleaseImage(&m_image);
	    }
	    if (m_writer != NULL) {
		    cvReleaseVideoWriter(&m_writer);
	    }
	    if (m_debug) {
		    cvDestroyWindow("WindowShowImage");
	    }
    }

    bool VCR::readSharedImage(Container &c) {
	    bool retVal = false;

	    if (c.getDataType() == Container::SHARED_IMAGE) {
		    SharedImage si = c.getData<SharedImage> ();

		    // Check if we have already attached to the shared memory.
		    if (!m_hasAttachedToSharedImageMemory) {
			    m_sharedImageMemory
					    = core::wrapper::SharedMemoryFactory::attachToSharedMemory(
							    si.getName());
		    }

		    // Check if we could successfully attach to the shared memory.
		    if (m_sharedImageMemory->isValid()) {
			    //cerr << "Got image: LOG 0.2 " << si.toString() << endl;

			    // Lock the memory region to gain exclusive access. REMEMBER!!! DO NOT FAIL WITHIN lock() / unlock(), otherwise, the image producing process would fail.
			    m_sharedImageMemory->lock();
			    {
				    // Here, do something with the image. For example, we simply show the image.

				    const uint32_t numberOfChannels = 3;
				    // For example, simply show the image.
				    if (m_image == NULL) {
					    m_image = cvCreateImage(cvSize(si.getWidth(),
							    si.getHeight()), IPL_DEPTH_8U, numberOfChannels);
				    }

				    // Copying the image data is very expensive...
				    if (m_image != NULL) {
					    memcpy(m_image->imageData,
							    m_sharedImageMemory->getSharedMemory(),
							    si.getWidth() * si.getHeight() * numberOfChannels);
				    }
			    }

			    // Release the memory region so that the image produce (i.e. the camera for example) can provide the next raw image data.
			    m_sharedImageMemory->unlock();

			    // Mirror the image.
			    cvFlip(m_image, 0, -1);

			    retVal = true;
		    }
	    }
	    return retVal;
    }

    void VCR::processImage() {
	    if (m_debug) {
		    // Show the image
		    if (m_image != NULL) {
			    cvShowImage("WindowShowImage", m_image);
			    cvWaitKey(10);

	            if (m_writer != NULL) {
		            cvWriteFrame(m_writer, m_image);
	            }
		    }
	    }
    }

    // This method will do the main data processing job.
    ModuleState::MODULE_EXITCODE VCR::body() {
	    // Get configuration data.
	    KeyValueConfiguration kv = getKeyValueConfiguration();
	    m_cameraId = kv.getValue<int32_t> ("VCR.camera_id");
	    m_debug = kv.getValue<int32_t> ("VCR.debug") == 1;

	    bool use_real_camera = true;

	    // Try to open the camera device.
	    CvCapture *capture = cvCaptureFromCAM(m_cameraId);
	    if (!capture) {
		    cerr << "Could not open real camera; falling back to SHARED_IMAGE."
				    << endl;
		    use_real_camera = false;
	    }

	    while (getModuleState() == ModuleState::RUNNING) {
		    bool has_next_frame = false;

		    // Use the shared memory image.
		    if (!use_real_camera) {
			    // Get the most recent available container for a SHARED_IMAGE.
			    Container c = getKeyValueDataStore().get(Container::SHARED_IMAGE);

			    if (c.getDataType() == Container::SHARED_IMAGE) {
				    // Example for processing the received container.
				    has_next_frame = readSharedImage(c);
			    }
		    } else {
			    // Use the real camera.
			    if (cvGrabFrame(capture)) {
				    m_image = cvRetrieveFrame(capture);
				    has_next_frame = true;
			    }
		    }

		    // Process the read image.
		    if ( (true == has_next_frame) && (m_writer == NULL) ) {
                double fps = getFrequency();
                CvSize size = cvSize(m_image->width, m_image->height);
                m_writer = cvCreateVideoWriter("video.mpg", CV_FOURCC('P','I','M','1'), fps, size);
                if (m_writer != NULL) {
                    cerr << "VideoWriter created." << endl;
                }
                else {
                    cerr << "Failed to create VideoWriter." << endl;
                }
		    }

		    // Process the read image.
		    if (true == has_next_frame) {
			    processImage();
		    }

		    if (use_real_camera) {
			    // Unset m_image only for the real camera to avoid memory leaks.
			    m_image = NULL;
		    }
	    }

	    if (capture != NULL) {
		    cvReleaseCapture(&capture);
	    }

	    return ModuleState::OKAY;
    }

} // msv

