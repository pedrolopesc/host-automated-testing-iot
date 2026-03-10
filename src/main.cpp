#include "app/app.h"

#ifndef PIO_UNIT_TESTING

void setup() {
    setup_app();
}

void loop() {
    loop_app();
}

#endif // not TEST

#ifndef ARDUINO

#ifndef PIO_UNIT_TESTING
extern "C" int main() {
    // Função dummy for HOST compilation only
    return 0;
}
#endif // HOST & not TEST

#endif // not ARDUINO