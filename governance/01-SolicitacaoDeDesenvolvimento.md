# Estado: SolicitaçãoDeDesenvolvimento

## Objetivo
Registrar a demanda inicial e alinhar entendimento do problema.

## Entradas
- Requisito de negócio/técnico: Alinhar estrutura do repositório com as regras definidas em `AGENTS.md`, especificamente renomeando a pasta de testes para `tests/`.
- Restrições iniciais: Manter compatibilidade com PlatformIO configurando `test_dir = tests` no `platformio.ini`.

## Saídas
- Contexto mínimo documentado para iniciar análise.

## Critério de conclusão
- Solicitação compreendida e registrada para revisão de fluxo. [x]

## Comunicação e periféricos
- Não aplicável por padrão.
- Em firmware, já identificar se há impacto em interfaces externas (UART/I2C/SPI/CAN etc.): Sem impacto em hardware ou periféricos, mudança puramente estrutural/arquitetural.
