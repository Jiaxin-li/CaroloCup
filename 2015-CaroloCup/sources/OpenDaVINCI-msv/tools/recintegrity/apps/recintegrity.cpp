/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include "RecIntegrity.h"

int32_t main(int32_t argc, char **argv) {
    recintegrity::RecIntegrity ri(argc, argv);
    return ri.runModule();
}
