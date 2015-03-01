/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include "Logger.h"

int32_t main(int32_t argc, char **argv) {
    msv::Logger p(argc, argv);
    return p.runModule();
}
