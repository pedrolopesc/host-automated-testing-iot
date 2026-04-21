# AGENTS.md

Este é o arquivo padrão para orientar ações do Codex neste repositório.
As regras abaixo são a fonte primária de execução para automações e agentes.

## Estrutura obrigatória do repositório

```text
.
├── AGENTS.md
├── README.md
├── architecture/
│   ├── DIAGRAM.md
│   └── <artefatos técnicos de arquitetura quando necessário>
├── governance/
│   └── <arquivos de estados 01..08>
├── src/
└── tests/
```

## Fluxo obrigatório de execução

1. Iniciar por uma solicitação de desenvolvimento.
2. Verificar `architecture/DIAGRAM.md` (criar se não existir).
3. Criar/atualizar apenas artefatos técnicos necessários em `architecture/`.
4. Propor escopo e registrar estados e evolução formal em `governance/`.
5. Aguardar aprovação explícita para alterações em governança.
6. Iniciar implementação com testes primeiro.
7. Implementar seguindo boas práticas (incluindo SOLID quando aplicável).
8. Validar e registrar resultados.

## Regras de arquitetura e governança

- `architecture/` contém o diagrama e os artefatos técnicos necessários de arquitetura.
- `governance/` contém os arquivos de estado (01..08), o registro formal de progresso e aprovações.
- Alterações em `governance/` exigem aprovação explícita do solicitante.
- Mudanças estruturais de processo devem ser refletidas primeiro em `architecture/DIAGRAM.md`.

## Regras específicas para firmware

- O projeto deve permitir teste em host e em hardware alvo.
- O arquivo `FIRMWARE_GPIO_MAP.md` deve existir e ser atualizado sempre que a pinagem mudar.
- O mapeamento de GPIO deve incluir pino, direção, função, periférico e observações.
