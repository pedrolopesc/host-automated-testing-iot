
#include "app/app.h"

#ifndef PIO_UNIT_TESTING

extern "C" int main() {
    setup_app();

    while (1) {
        loop_app();
    }
    return 0;
}

#endif