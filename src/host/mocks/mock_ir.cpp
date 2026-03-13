#include "driver/ir.h"
#include "mock_ir.h"

static bool mock_setup_ir_output = true;
static uint16_t mock_read_ir_output = 32;

void set_mock_setup_ir_output(bool output) { mock_setup_ir_output = output; };
void set_mock_read_ir_output(uint16_t output) { mock_read_ir_output = output; };

bool setup_ir() { return mock_setup_ir_output; };
uint16_t read_ir() { return mock_read_ir_output; };