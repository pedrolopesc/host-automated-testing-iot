#include "imu.h"

#include <Arduino.h>
#include <Wire.h>

namespace {
constexpr uint8_t QMC6500_I2C_ADDR = 0x0D;
constexpr uint8_t REG_CTRL1 = 0x09;
constexpr uint8_t REG_CTRL2 = 0x0A;
constexpr uint8_t REG_INT_STATUS = 0x0D;
constexpr uint8_t REG_THRESHOLD = 0x0E;
constexpr uint8_t REG_RESET = 0x0B;
constexpr uint8_t CTRL1_CONTINUOUS_200HZ_2G = 0x1D;
constexpr uint8_t CTRL2_INT_ENABLE = 0x01;
constexpr uint8_t INT_STATUS_VIBRATION = 0x01;
constexpr uint8_t DEFAULT_VIBRATION_THRESHOLD = 0x12;
constexpr uint8_t QMC6500_INT_PIN = D3;

volatile bool g_vibration_irq = false;

void write_register(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(QMC6500_I2C_ADDR);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

uint8_t read_register(uint8_t reg) {
    Wire.beginTransmission(QMC6500_I2C_ADDR);
    Wire.write(reg);
    if (Wire.endTransmission(false) != 0) {
        return 0;
    }

    if (Wire.requestFrom(QMC6500_I2C_ADDR, static_cast<uint8_t>(1)) != 1) {
        return 0;
    }

    return Wire.read();
}

void IRAM_ATTR on_vibration_interrupt() {
    g_vibration_irq = true;
}
}  // namespace

bool setup_imu() {
    Wire.begin();

    write_register(REG_RESET, 0x01);
    delay(2);

    write_register(REG_THRESHOLD, DEFAULT_VIBRATION_THRESHOLD);
    write_register(REG_CTRL1, CTRL1_CONTINUOUS_200HZ_2G);
    write_register(REG_CTRL2, CTRL2_INT_ENABLE);

    pinMode(QMC6500_INT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(QMC6500_INT_PIN), on_vibration_interrupt, FALLING);

    return true;
}

bool imu_has_vibration_event() {
    if (!g_vibration_irq) {
        return false;
    }

    noInterrupts();
    g_vibration_irq = false;
    interrupts();

    const uint8_t status = read_register(REG_INT_STATUS);
    return (status & INT_STATUS_VIBRATION) != 0;
}
