![CI](https://github.com/pedrolopesc/host-automated-testing-iot/actions/workflows/tests.yml/badge.svg)


# Host-Based Testing for Embedded Firmware

This repository demonstrates a simple and practical approach to **host-based testing for embedded systems**.
The goal is to show how firmware logic can be tested **without running on the microcontroller**, improving development speed, reliability, and code quality.

The project uses a layered architecture where **hardware-dependent code can be replaced with mocks**, allowing the firmware logic to run on a standard host machine.

---

# Why Host-Based Testing?

Traditional embedded development requires flashing the firmware to a microcontroller for every test cycle.

Typical workflow: