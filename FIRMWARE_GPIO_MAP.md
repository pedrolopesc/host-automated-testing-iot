# FIRMWARE_GPIO_MAP.md

Use este arquivo para documentar os GPIOs do microcontrolador em projetos de firmware.

## Microcontrolador
- Modelo: `<preencher>`
- Família: `<preencher>`

## Tabela de GPIOs

| GPIO | Direção | Função | Módulo/Periférico | Observações |
|---|---|---|---|---|
| `<ex: PA0>` | `<Entrada/Saída>` | `<ex: Botão usuário>` | `<ex: GPIO/EXTI>` | `<pull-up, nível ativo, etc.>` |

## Regras

1. Todo GPIO usado no firmware deve constar nesta tabela.
2. Mudanças de pinagem exigem atualização deste documento.
3. Informar conflitos de multiplexação quando houver.
4. Referenciar este arquivo nas revisões de escopo e validação.
