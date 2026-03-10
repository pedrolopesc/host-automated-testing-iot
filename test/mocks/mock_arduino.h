#pragma once

#ifndef ARDUINO

#include <stdio.h>

    #ifndef uint8_t
    typedef unsigned char uint8_t;
    #endif
    #ifndef uint16_t
    typedef unsigned short uint16_t;
    #endif
    #ifndef uint32_t
    typedef unsigned int uint32_t;
    #endif

inline void delay(uint32_t ms) {};

class MockSerial {
public:
    void begin(unsigned long) {};

    operator bool() const { return true; }

    template<typename T>
    void print(const T& v) { printf("%d", v); }

    template<typename T>
    void println(const T& v) { printf("%d\n", v); }

};

inline MockSerial Serial;

#endif // ADRDUINO