# FIRMWARE_GPIO_MAP.md

## Objetivo
Documentar o mapeamento de GPIOs do firmware e registrar explicitamente quando a pinagem
não está fixa no código-fonte.

## Microcontrolador alvo atual
- Modelo: **Seeed XIAO ESP32C3** (`board = seeed_xiao_esp32c3` em `platformio.ini`)
- Família: **ESP32-C3**

## Situação atual do projeto (2026-04-21)

Até o momento, o código não define pinos explicitamente com `pinMode(...)`, `digitalWrite(...)`
ou inicialização manual de barramento com pinos fixos.

- Sensor VL53L0X é usado pelo driver (`driver/ir.cpp`) via biblioteca, sem pinagem declarada no código.
- Portanto, a pinagem efetiva depende da configuração padrão da placa/framework.

## Tabela de GPIOs

| GPIO | Direção | Função | Módulo/Periférico | Observações |
|---|---|---|---|---|
| `N/D no código` | `N/D` | Barramento I2C do sensor VL53L0X | `driver/ir.cpp` + lib Adafruit_VL53L0X | Pinagem física não declarada explicitamente no repositório; depende do board/framework padrão. |
| `N/D no código` | `Saída` | Log serial (`log_info`) | `hal/log.cpp` | Saída serial depende da configuração padrão da plataforma (sem definição explícita de pinos). |

## Regras operacionais

1. Todo GPIO explicitamente usado no firmware deve constar nesta tabela.
2. Mudanças de pinagem exigem atualização deste documento no mesmo commit.
3. Informar conflitos de multiplexação quando houver.
4. Em PRs sem alteração de pinagem, registrar explicitamente: **"Sem mudança de GPIO"**.
