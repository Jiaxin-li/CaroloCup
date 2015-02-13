/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef OPENDAVINCI_CORE_WRAPPER_ABSTRACTPROTOCOL_H_
#define OPENDAVINCI_CORE_WRAPPER_ABSTRACTPROTOCOL_H_

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"

#include <sstream>

#include "core/wrapper/Mutex.h"
#include "core/wrapper/PartialStringReceiver.h"
#include "core/wrapper/StringObserver.h"
#include "core/wrapper/StringSender.h"

namespace core {
    namespace wrapper {

        using namespace std;

        class OPENDAVINCI_API AbstractProtocol : public PartialStringReceiver {
            private:
                /**
                 * "Forbidden" copy constructor. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the copy constructor.
                 */
                AbstractProtocol(const AbstractProtocol &);

                /**
                 * "Forbidden" assignment operator. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the assignment operator.
                 */
                AbstractProtocol& operator=(const AbstractProtocol &);

            protected:
                /**
                 * Protected constructor to enforce subclasses.
                 */
                AbstractProtocol();

            public:
                virtual ~AbstractProtocol();

                /**
                 * This method sets the StringSender (implemented by a connection like SerialPort)
                 * that can actually send the data.
                 *
                 * @param sender StringSender that will send the data.
                 */
                void setStringSender(StringSender* sender);

                /**
                 * This method needs to be called by subclasses to actually send
                 * some data according to the implemented protocol.
                 *
                 * @param data Data to be sent.
                 */
                void sendByStringSender(const string &data);

            private:
                std::auto_ptr<Mutex> m_stringSenderMutex;
                StringSender *m_stringSender;
        };
    }
}

#endif /* OPENDAVINCI_CORE_WRAPPER_ABSTRACTPROTOCOL_H_ */

