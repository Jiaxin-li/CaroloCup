/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef OPENDAVINCI_CORE_WRAPPER_WIN32IMPL_SERIALPORT_H_
#define OPENDAVINCI_CORE_WRAPPER_WIN32IMPL_SERIALPORT_H_

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"

#include "core/wrapper/Runnable.h"
#include "core/wrapper/SerialPort.h"
#include "core/wrapper/Thread.h"
#include "core/wrapper/Mutex.h"

namespace core {
    namespace wrapper {
        namespace WIN32Impl {

            class WIN32SerialPort : public SerialPort, public Runnable {
                private:
                    /**
                     * "Forbidden" copy constructor. Goal: The compiler should warn
                     * already at compile time for unwanted bugs caused by any misuse
                     * of the copy constructor.
                     */
                    WIN32SerialPort(const WIN32SerialPort &);

                    /**
                     * "Forbidden" assignment operator. Goal: The compiler should warn
                     * already at compile time for unwanted bugs caused by any misuse
                     * of the assignment operator.
                     */
                    WIN32SerialPort& operator=(const WIN32SerialPort &);

                public:
                    WIN32SerialPort(const std::string &port, const uint32_t &baudRate, const SerialPortSettings &settings = SerialPortSettings());

                    virtual ~WIN32SerialPort();

                    virtual void sendImplementation(const std::string& data);

                    virtual void start();
                    virtual void stop();

                    virtual bool isRunning();
                    virtual void run();

                protected:
                    void initialize();

                    bool openPort(const std::string &port, const uint32_t &baudRate, const SerialPortSettings &settings);
                    void closePort();
                    bool isOpen();
                    bool setBaudrate(const uint32_t &baudRate);
                    bool setDataBits(const SerialPortSettings::SerialPortDataBits &dataBits);
                    bool setStopBits(const SerialPortSettings::SerialPortStopBits &stopBits);
                    bool setParity(const SerialPortSettings::SerialPortParity &parity);

                    std::auto_ptr<Thread> m_thread;

                    std::auto_ptr<Mutex> m_socketMutex;
                    int32_t m_fileDescriptor;

                    enum { BUFFER_SIZE = 2048 };
                    char m_buffer[BUFFER_SIZE];
                    std::string m_port;
                    uint32_t m_baudRate;

                    bool m_open;
            };
        }
    }
}
#endif /* OPENDAVINCI_CORE_WRAPPER_WIN32IMPL_WIN32SERIALPORT_H_ */
