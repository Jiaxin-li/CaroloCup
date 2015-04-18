/**
 * Component - <Description>
 * Copyright (C) 2012 - 2015 Christian Berger
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <stdio.h>
#include <math.h>

#include "core/io/ContainerConference.h"
#include "core/data/Container.h"
#include "core/data/Constants.h"


#include "GeneratedHeaders_Data.h"

#include "Component.h"

namespace nameSpace {

        using namespace std;
        using namespace core::base;
        using namespace core::data;


        Component::Component(const int32_t &argc, char **argv) :
	        ConferenceClientModule(argc, argv, "Component") {
        }

        Component::~Component() {}

        void Component::setUp() {
	        // This method will be call automatically _before_ running body().
        }

        void Component::tearDown() {
	        // This method will be call automatically _after_ return from body().
        }

        // This method will do the main data processing job.
        ModuleState::MODULE_EXITCODE Component::body() {

	        while (getModuleState() == ModuleState::RUNNING) {
                // In the following, you find example for the various data sources that are available:

               
	        }

	        return ModuleState::OKAY;
        }
} // nameSpace

