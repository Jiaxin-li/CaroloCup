/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef OPENDAVINCI_CORE_BASE_REALTIMESERVICE_H_
#define OPENDAVINCI_CORE_BASE_REALTIMESERVICE_H_

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"

#include "core/SharedPointer.h"
#include "core/base/Mutex.h"
#include "core/exceptions/Exceptions.h"
#include "core/wrapper/Thread.h"
#include "core/wrapper/RealtimeRunnable.h"

namespace core {
    namespace base {

        /**
         * This class combines wrapper::RealtimeRunnable and wrapper::Thread
         * for convenience. A binary using RealtimeService MUST be run
         * with super user privileges!
         *
         * It can be used as follows:
         *
         * @code
         * class MyRealtimeService : public RealtimeService {
         *     MyRealtimeService(long periodInMicroseconds) :
         *         RealtimeService(long periodInMicroseconds)
         *     {}
         *
         *     void nextTimeSlice() {
         *         // Do something.
         *     }
         * };
         *
         * int32_t main(int32_t argc, char **argv) {
         *     MyService s(periodInMicroseconds);
         *     s.start();
         *     s.stop();
         * }
         * @endcode
         */
        class OPENDAVINCI_API RealtimeService : public wrapper::RealtimeRunnable {
            private:
                // Internal constants.
                enum {
                    ONEMICROSECOND = 1,
                    THOUSANDMICROSECONDS = 1000 * ONEMICROSECOND
                };

                enum REALTIMESERVICE_STATE {
                    INITIALIZED,
                    RUNNING,
                    STOPPED
                };

            private:
                /**
                 * "Forbidden" copy constructor. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the copy constructor.
                 */
                RealtimeService(const RealtimeService &);

                /**
                 * "Forbidden" assignment operator. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the assignment operator.
                 */
                RealtimeService& operator=(const RealtimeService &);

            public:
                enum PERIOD {
                    ONEMILLISECOND      = 1 * THOUSANDMICROSECONDS,
                    TENMILLISECONDS     = 10 * ONEMILLISECOND,
                    TWENTYMILLISECONDS  = 20 * ONEMILLISECOND,
                    FIFTYMILLISECONDS   = 50 * ONEMILLISECOND,
                    HUNDREDMILLISECONDS = 100 * ONEMILLISECOND,
                    ONESECOND           = 1000 * ONEMILLISECOND,
                    TWOSECONDS          = 2 * ONESECOND,
                    FIVESECONDS         = 5 * ONESECOND
                };

                /**
                 * Constructor.
                 *
                 * @param period Duration for the slice.
                 * @throws ThreadException if the thread can not be created.
                 */
                RealtimeService(const enum PERIOD &period) throw (exceptions::ThreadException);

                virtual ~RealtimeService();

                /**
                 * This method starts the service.
                 */
                void start();

                /**
                 * This method stops the service.
                 * A stopped service CANNOT get restarted.
                 */
                void stop();

            protected:
                virtual void nextTimeSlice() = 0;

                virtual bool isRunning();

            private:
                SharedPointer<wrapper::Thread> m_thread;

                Mutex m_realtimeServiceStateMutex;
                REALTIMESERVICE_STATE m_realtimeServiceState;
        };

    }
} // core::base

#endif /*OPENDAVINCI_CORE_BASE_REALTIMESERVICE_H_*/
