#pragma once

#ifndef ARDUINO

#include <stdio.h>

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