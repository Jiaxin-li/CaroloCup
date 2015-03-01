/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <map>

#include "core/base/ConferenceClientModule.h"
#include "core/data/Container.h"
#include "core/data/TimeStamp.h"


namespace msv {

    using namespace std;
    using namespace core::data;

    /**
     * This class wraps the software/hardware interface board.
     */
    class Logger : public core::base::ConferenceClientModule{
        private:
            /**
             * "Forbidden" copy constructor. Goal: The compiler should warn
             * already at compile time for unwanted bugs caused by any misuse
             * of the copy constructor.
             *
             * @param obj Reference to an object of this class.
             */
            Logger(const Logger &/*obj*/);

            /**
             * "Forbidden" assignment operator. Goal: The compiler should warn
             * already at compile time for unwanted bugs caused by any misuse
             * of the assignment operator.
             *
             * @param obj Reference to an object of this class.
             * @return Reference to this instance.
             */
            Logger& operator=(const Logger &/*obj*/);

        public:
            /**
             * Constructor.
             *
             * @param argc Number of command line arguments.
             * @param argv Command line arguments.
             */
            Logger(const int32_t &argc, char **argv);

            virtual ~Logger();

            core::base::ModuleState::MODULE_EXITCODE body();

           
        private:
            virtual void setUp();

            virtual void tearDown();

    };

} // msv

#endif /*Logger_H_*/
