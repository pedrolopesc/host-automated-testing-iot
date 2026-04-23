# FIRMWARE_GPIO_MAP.md

Use este arquivo para documentar os GPIOs do microcontrolador em projetos de firmware.

## Microcontrolador
- Modelo: `ESP32-C3 (Seeed XIAO ESP32C3)`
- Família: `Espressif ESP32`

## Tabela de GPIOs

| GPIO | Direção | Função | Módulo/Periférico | Observações |
|---|---|---|---|---|
| `D4` | Bidirecional | SDA do barramento de sensores | `I2C/Wire` | Barramento compartilhado entre VL53L0X e QMC6500 |
| `D5` | Saída | SCL do barramento de sensores | `I2C/Wire` | Clock do barramento I2C |
| `D3` | Entrada | Interrupção de vibração do QMC6500 | `GPIO/EXTI` | Configurado com `INPUT_PULLUP`, borda de descida (`FALLING`) |

## Regras

1. Todo GPIO usado no firmware deve constar nesta tabela.
2. Mudanças de pinagem exigem atualização deste documento.
3. Informar conflitos de multiplexação quando houver.
4. Referenciar este arquivo nas revisões de escopo e validação.
