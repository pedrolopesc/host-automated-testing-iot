# TECHNICAL_BASELINE.md

## Objetivo

Registrar a baseline técnica da arquitetura atual para orientar futuras
mudanças sem conflitar com o fluxo de governança.

## Visão de módulos

- `src/app/`
  - Orquestra o ciclo da aplicação (`setup_app`, `loop_app`).
  - Aplica regras de negócio (`half_value`).
- `src/driver/`
  - Integração com sensor IR (VL53L0X).
- `src/hal/`
  - Inicialização e saída de logs.
- `src/host/`
  - Entrypoint para execução nativa e mocks para testes host-based.
- `test/host/unit/`
  - Testes unitários de comportamento da aplicação e regras puras.

## Perfis de execução

### Hardware alvo

- Entrada principal: `src/main.cpp`.
- Usa `driver/ir.cpp` real com dependência de biblioteca de sensor.
- Usa `hal/log.cpp` para observabilidade em runtime.

### Host (native)

- Entrada principal: `src/host/main.cpp`.
- Substitui dependências de hardware com mocks em `src/host/mocks/`.
- Executa suíte unitária em `test/host/unit/`.

## Contratos de fronteira

Para preservar testabilidade e baixo acoplamento:

- `driver/ir.h` define contrato de leitura e setup do sensor.
- `hal/log.h` define contrato de logging.
- `app/` depende dos contratos e não de detalhes concretos de hardware.

## Critérios de evolução arquitetural

1. Novas integrações de hardware devem entrar por `driver/` ou `hal/`.
2. Regras de negócio devem ficar em `app/` (ou submódulos de `app/`).
3. Toda funcionalidade nova deve ter caminho testável em host.
4. Alteração de pinagem deve atualizar `FIRMWARE_GPIO_MAP.md`.
