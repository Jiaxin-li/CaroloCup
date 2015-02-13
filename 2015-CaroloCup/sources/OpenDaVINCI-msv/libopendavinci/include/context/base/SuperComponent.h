/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef CONTEXT_BASE_SUPERCOMPONENT_H_
#define CONTEXT_BASE_SUPERCOMPONENT_H_

#include <string>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"
#include "core/base/KeyValueConfiguration.h"
#include "core/io/ContainerConference.h"
#include "core/dmcp/ModuleConfigurationProvider.h"
#include "core/dmcp/ModuleStateListener.h"
#include "core/dmcp/connection/ConnectionHandler.h"
#include "core/dmcp/connection/ModuleConnection.h"
#include "core/dmcp/connection/Server.h"
#include "core/dmcp/discoverer/Server.h"

namespace context {
    namespace base {

        using namespace std;

        /**
         * This class provides supercomponent functionality.
         */
        class OPENDAVINCI_API SuperComponent : protected core::dmcp::connection::ConnectionHandler,
                                            protected core::dmcp::ModuleStateListener,
                                            public core::dmcp::ModuleConfigurationProvider {
            private:
                /**
                 * "Forbidden" copy constructor. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the copy constructor.
                 */
                SuperComponent(const SuperComponent&);

                /**
                 * "Forbidden" assignment operator. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the assignment operator.
                 */
                SuperComponent& operator=(const SuperComponent&);

            public:
                /**
                 * Constructor for constructing a supercomponent using REAL UDP/TCP
                 * for the given CID and the given configuration.
                 *
                 * @param multicastGroup Multicast group to create supercomponent for.
                 * @param cid CID for the supercomponent.
                 * @param configuration Global configuration.
                 */
                SuperComponent(const string &multicastGroup, const uint32_t &CID, const core::base::KeyValueConfiguration &configuration);

                virtual ~SuperComponent();

                /**
                 * This method returns the real UDPMulticastClientConference.
                 *
                 * @return UDPMulticastClientConference.
                 */
                core::io::ContainerConference& getContainerConference();

            protected:
                virtual core::base::KeyValueConfiguration getConfiguration(const core::data::dmcp::ModuleDescriptor& md);

                virtual core::base::KeyValueConfiguration getGlobalConfiguration() const;

                virtual void onNewModule(core::dmcp::connection::ModuleConnection *mc);

                virtual void handleChangeState(const core::data::dmcp::ModuleDescriptor& md,
                                               const core::base::ModuleState::MODULE_STATE &ms);

                virtual void handleExitCode(const core::data::dmcp::ModuleDescriptor& md,
                                            const core::base::ModuleState::MODULE_EXITCODE &me);

                virtual void handleRuntimeStatistics(const core::data::dmcp::ModuleDescriptor& md,
                                                     const core::data::RuntimeStatistic& rs);

                virtual void handleConnectionLost(const core::data::dmcp::ModuleDescriptor& md);

                virtual void handleUnkownContainer(const core::data::dmcp::ModuleDescriptor& md,
                                                   const core::data::Container& container);

            private:
                core::base::Mutex m_configurationMutex;
                core::base::KeyValueConfiguration m_configuration;

                core::dmcp::discoverer::Server* m_discovererServer;
                core::dmcp::connection::Server* m_connectionServer;

                core::io::ContainerConference *m_conference;
        };

    }
} // context::base

#endif /*CONTEXT_BASE_SUPERCOMPONENT_H_*/
