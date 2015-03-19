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
		ConferenceClientModule(argc, argv, "logger"),
		loggerStream(),
		initTimestamp(){

}

Logger::~Logger() {
}

void Logger::setUp() {
	// This method will be call automatically _before_ running body().

	stringstream loggerName;
	loggerName<<"Logging_"<<TimeStamp().getYYYYMMDD_HHMMSS()<<".log";
	loggerStream.open(loggerName.str().c_str(),ios::out | ios::app);

}

void Logger::tearDown() {
	// This method will be call automatically _after_ return from body().
	//log("TearDown.");
	loggerStream.close();
}

// This method will do the main data processing job.
ModuleState::MODULE_EXITCODE Logger::body() {
	FIFOQueue m_fifo;
	addDataStoreFor(m_fifo);
	while (getModuleState() == ModuleState::RUNNING) {

		while (!m_fifo.isEmpty()) {
		    Container c = m_fifo.leave();
		    if (c.getDataType()==USER_DATA_9) {
				c.getData<>();
			}
		}
	}

	return ModuleState::OKAY;
}
} // msv

