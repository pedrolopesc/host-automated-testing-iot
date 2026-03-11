
#include "app/app.h"

extern "C" int main() {
    setup_app();

    while (1) {
        loop_app();
    }
    return 0;
}