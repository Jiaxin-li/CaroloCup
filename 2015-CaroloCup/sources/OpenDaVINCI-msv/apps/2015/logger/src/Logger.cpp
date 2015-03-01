/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <ctype.h>
#include <cstring>
#include <cmath>
#include <string>

#include "core/base/Thread.h"
#include "core/base/KeyValueConfiguration.h"
#include "core/data/Container.h"
#include "core/data/TimeStamp.h"
#include "core/data/control/VehicleControl.h"
#include "core/base/LIFOQueue.h"
#include "core/wrapper/SerialPortFactory.h"
#include "core/wrapper/SerialPort.h"
#include "core/base/Lock.h"
#include "core/base/Mutex.h"


#include "Logger.h"



namespace msv {

using namespace std;
using namespace core::base;
using namespace core::data;
using namespace core::data::control;


Logger::Logger(const int32_t &argc, char **argv) :
		ConferenceClientModule(argc, argv, "logger")
		{

}

Logger::~Logger() {
}

void Logger::setUp() {
	// This method will be call automatically _before_ running body().
	if (getFrequency() < 20) {
		cerr << endl << endl
				<< "Logger: WARNING! Running Logger with a LOW frequency (consequence: data updates are too seldom and will influence your algorithms in a negative manner!) --> suggestions: --freq=20 or higher! Current frequency: "
				<< getFrequency() << " Hz." << endl << endl << endl;
	}
	

}


void Logger::tearDown() {
	// This method will be call automatically _after_ return from body().
	
}




// This method will do the main data processing job.
ModuleState::MODULE_EXITCODE Logger::body() {




	

	while (getModuleState() == ModuleState::RUNNING) {
		// Capture frame.
		
	}

	
	return ModuleState::OKAY;
}
} // msv

