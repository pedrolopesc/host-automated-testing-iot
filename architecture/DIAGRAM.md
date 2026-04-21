# DIAGRAM.md — Fluxo de Engenharia + Arquitetura Lógica

Este documento foi atualizado para refletir o estado **real** do repositório
(implementação já existente antes da adoção do agente), mantendo o fluxo de
estados exigido e adicionando a visão técnica de execução em **host** e em
**hardware alvo**.

## 1) Fluxo de estados (governança de execução)

```mermaid
stateDiagram-v2
    [*] --> SolicitacaoDeDesenvolvimento

    SolicitacaoDeDesenvolvimento --> RevisaoDoDiagrama
    RevisaoDoDiagrama --> PropostaDeEscopo
    PropostaDeEscopo --> AprovacaoDoEscopo

    AprovacaoDoEscopo --> PlanejamentoDeTestes
    PlanejamentoDeTestes --> Implementacao
    Implementacao --> Validacao
    Validacao --> Entrega

    Entrega --> [*]
```

## 2) Arquitetura lógica do firmware (estado atual)

```mermaid
flowchart LR
    subgraph App[Camada de Aplicação]
        APP[app/app.cpp\nsetup_app + loop_app]
        FILTER[app/filter/filter.cpp\nhalf_value]
    end

    subgraph Driver[Camada de Driver]
        IR[driver/ir.cpp\nsetup_ir + read_ir]
    end

    subgraph HAL[Camada HAL]
        LOG[hal/log.cpp\nlog_init + log_info]
    end

    subgraph Host[Execução Host]
        HMAIN[src/host/main.cpp]
        MIR[host/mocks/mock_ir.cpp]
        MLOG[host/mocks/mock_log.cpp]
        TESTS[test/host/unit/*]
    end

    subgraph Target[Execução Hardware]
        TMAIN[src/main.cpp]
        SENSOR[VL53L0X]
        UART[Serial]
    end

    APP --> FILTER
    APP --> IR
    APP --> LOG

    IR --> SENSOR
    LOG --> UART

    HMAIN --> APP
    TESTS --> APP
    TESTS --> FILTER
    TESTS -. substitui .-> MIR
    TESTS -. substitui .-> MLOG

    TMAIN --> APP
```

## 3) Regras arquiteturais derivadas

- A camada `app/` concentra regra de negócio e deve permanecer testável em host.
- Dependências de hardware ficam isoladas em `driver/` e `hal/`.
- Mocks em `src/host/mocks/` devem manter a mesma interface pública das
  dependências reais para viabilizar testes determinísticos.
- Qualquer mudança estrutural de fluxo ou camadas deve ser refletida primeiro
  neste arquivo.

## 4) Mapeamento para artefatos técnicos

- Fluxo de estados formal: `governance/01..08-*.md`.
- Detalhamento técnico complementar: `architecture/TECHNICAL_BASELINE.md`.
- Pinagem e observações de GPIO: `FIRMWARE_GPIO_MAP.md`.
