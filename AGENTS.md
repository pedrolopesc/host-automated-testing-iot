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

## Checklist obrigatório para TODA solicitação

Antes de concluir qualquer tarefa, o agente deve validar e registrar:

1. **Arquitetura**
   - `architecture/DIAGRAM.md` foi verificado.
   - Artefatos técnicos de arquitetura foram atualizados quando necessário.

2. **Governança**
   - Estados 01..08 foram revisados para refletir evolução formal quando aplicável.
   - Se houver mudança em `governance/`, confirmar aprovação explícita do solicitante.

3. **Firmware GPIO map (obrigatório)**
   - `FIRMWARE_GPIO_MAP.md` foi revisado em toda solicitação.
   - Se houve mudança de pinagem: atualizar tabela no mesmo commit.
   - Se NÃO houve mudança de pinagem: registrar explicitamente no PR e/ou validação
     a frase **"Sem mudança de GPIO"**.

4. **Validação final**
   - Resultado de testes/checks executados.
   - Limitações de ambiente (quando houver).
