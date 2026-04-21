# TECHNICAL_BASELINE.md

## Objetivo

Documentar a arquitetura técnica atual para que evolução de código e documentação
siga um baseline comum entre host e hardware alvo.

## Estrutura técnica atual

- `src/app/`: orquestração de fluxo da aplicação e regra de negócio.
- `src/driver/`: integração com periférico/sensor.
- `src/hal/`: abstrações de logging e infraestrutura de baixo nível.
- `src/host/`: execução nativa e mocks para substituir hardware.
- `test/host/unit/`: testes unitários em host.

## Perfis de execução

### Hardware alvo

- Entrada: `src/main.cpp`.
- Usa implementações reais de `driver/` e `hal/`.
- Objetivo: validar comportamento em microcontrolador e periféricos.

### Host (native)

- Entrada: `src/host/main.cpp`.
- Substitui hardware por mocks (`src/host/mocks/`).
- Objetivo: feedback rápido, determinístico e automatizado.

## Contratos de fronteira

- `driver/ir.h`: contrato de inicialização e leitura do sensor.
- `hal/log.h`: contrato de inicialização e saída de logs.
- `app/` consome contratos, não detalhes concretos de dispositivo.

## Regras de evolução

1. Novo acesso a periférico deve entrar por `driver/` ou `hal/`.
2. Regra de negócio deve permanecer em `app/`.
3. Toda funcionalidade nova deve ter estratégia de teste em host.
4. Mudanças de pinagem exigem atualização de `FIRMWARE_GPIO_MAP.md`.
