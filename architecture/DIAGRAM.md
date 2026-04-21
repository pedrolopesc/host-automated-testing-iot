# DIAGRAM.md — Fluxo oficial e visão arquitetural do projeto

Este diagrama consolida:

1. **Fluxo oficial de execução** exigido pelo processo (estados 01..08 em `governance/`).
2. **Visão técnica atual** do firmware para host-based testing e hardware alvo.

## 1) Fluxo oficial de execução (governança)

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

## 2) Arquitetura lógica atual (código existente)

```mermaid
flowchart LR
    subgraph APP[Camada de Aplicação]
        APP_MAIN[app/app.cpp\nsetup_app + loop_app]
        FILTER[app/filter/filter.cpp\nhalf_value]
    end

    subgraph DRV[Camada de Driver]
        IR[driver/ir.cpp\nsetup_ir + read_ir]
    end

    subgraph HAL[Camada HAL]
        LOG[hal/log.cpp\nlog_init + log_info]
    end

    subgraph HOST[Execução Host]
        HMAIN[src/host/main.cpp]
        MOCK_IR[src/host/mocks/mock_ir.cpp]
        MOCK_LOG[src/host/mocks/mock_log.cpp]
        T_HOST[test/host/unit/*]
    end

    subgraph TARGET[Execução Hardware]
        TMAIN[src/main.cpp]
        SENSOR[VL53L0X]
        SERIAL[Serial]
    end

    APP_MAIN --> FILTER
    APP_MAIN --> IR
    APP_MAIN --> LOG

    IR --> SENSOR
    LOG --> SERIAL

    HMAIN --> APP_MAIN
    T_HOST --> APP_MAIN
    T_HOST --> FILTER

    TMAIN --> APP_MAIN
```

## 3) Regras arquiteturais

- Regras de negócio ficam na camada `app/` e devem ser testáveis em host.
- Dependências de hardware ficam isoladas em `driver/` e `hal/`.
- Mocks de host devem manter o mesmo contrato público dos módulos reais.
- Mudanças estruturais de processo devem atualizar este documento antes dos demais.

## 4) Mapeamento obrigatório de documentos

- Fluxo formal de estados: `governance/01-SolicitacaoDeDesenvolvimento.md` até `governance/08-Entrega.md`.
- Baseline técnica do código atual: `architecture/TECHNICAL_BASELINE.md`.
- Pinagem de firmware: `FIRMWARE_GPIO_MAP.md`.
