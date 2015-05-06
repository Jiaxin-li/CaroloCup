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
#include "core/data/logger/LogMessageData.h"

#include "tools/logger/Logger.h"

namespace tools {
	namespace logger{



		using namespace std;
		using namespace core::base;
		using namespace core::data;
		using namespace core::data::logger;

		Logger::Logger(const int32_t &argc, char **argv) :
				ConferenceClientModule(argc, argv, "logger"), loggerStream(), initTimestamp() {
			stringstream loggerName;
			loggerName << "Logging_" << TimeStamp().getYYYYMMDD_HHMMSS() << ".log";
			loggerStream.open(loggerName.str().c_str(), ios::out | ios::app);
			log("Begin Logging",TimeStamp());
		}

		Logger::~Logger() {
			log("TearDown.",TimeStamp());
			loggerStream.close();
		}

		void Logger::setUp() {
			// This method will be call automatically _before_ running body().


		}

		void Logger::tearDown() {
			// This method will be call automatically _after_ return from body().

		}

		// This method will do the main data processing job.
		ModuleState::MODULE_EXITCODE Logger::body() {
			FIFOQueue m_fifo;
			addDataStoreFor(m_fifo);
			while (getModuleState() == ModuleState::RUNNING) {

				while (!m_fifo.isEmpty()) {
					Container c = m_fifo.leave();
					if (c.getDataType() == Container::LOGGER) {
						LogMessageData logMessageData = c.getData<LogMessageData>();
						{
							stringstream logs;
							logs << logMessageData.getComponent() << ";"
									<< logMessageData.getLoglevel() << ";" << logMessageData.getMsg()<<";" << endl;

							log(logs.str(),c.getSentTimeStamp());
						}
					}
				}
			}

			return ModuleState::OKAY;
		}

		void Logger::log(const string &s, TimeStamp timeSent) {
			TimeStamp time = timeSent - initTimestamp;
			loggerStream << 
			time.getSeconds() << "." << time.getFractionalMicroseconds() << ";" << s << endl;
			if(loggerStream!=NULL){
				loggerStream.flush();
			}
		}
	} // logger
} // tools

