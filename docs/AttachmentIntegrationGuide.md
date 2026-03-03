# Diagnóstico e integração: ProjectHopeBackpack + TerjeMedicine

## 1) Diagnóstico atual do projeto

### Mochilas no código raiz
- A classe `PH_Backpack_01_ColorBase` estende `Clothing` e já possui lógica de attachment para os slots `Shoulder` e `Melee`, incluindo filtro por tipo de item (`Weapon_Base`).
- As variantes `SurvivorBackpack_*` herdam diretamente dessa classe base.

### Restrições de compatibilidade já implementadas
- Em `CanReceiveAttachment`, o slot `Shoulder` só aceita armas (`Weapon_Base`), e o slot `Melee` só aceita itens que **não** sejam `Weapon_Base`.
- Isso mostra o padrão de validação script-side no projeto: primeiro filtra por nome do slot, depois por herança/tipo do item.

### Sistema TerjeMedicine (bolsas de remédio)
- As classes `TerjeFirstAidKit*` herdam de `Container_Base`.
- O conteúdo interno das bolsas é restringido via `CanReceiveItemIntoCargo` e `CanLoadItemIntoCargo`, usando flag de config `medicalItem` em `CfgVehicles`.
- Ou seja: existe validação de **cargo** (conteúdo interno), mas não existe validação explícita de **attachment em mochila** nesses scripts.

## 2) Mapeamento das dependências (Slots -> Itens -> Containers -> Bases)

1. **Slot (CfgSlots / nome do slot)**
   - Exemplo existente no projeto: `Shoulder`, `Melee`, `FirstAidKit` (inferido pelos proxies e strings de config).
   - Exemplo novo proposto: `MedicalPouchSlot`.

2. **Container receptor (CfgVehicles -> mochila)**
   - A mochila precisa listar o slot no array `attachments[]`.
   - Sem isso, o item nunca encaixa no receptor.

3. **Item anexável (CfgVehicles -> item médico)**
   - O item precisa listar o slot no array `inventorySlot[]`.
   - Sem isso, o item não é reconhecido como compatível com o slot do receptor.

4. **Classes base e filtros de script**
   - Mesmo com `attachments[]` e `inventorySlot[]` corretos, filtros em script (ex.: `CanReceiveAttachment`) podem bloquear o attachment.
   - No caso atual, os bloqueios explícitos estão focados em `Shoulder` e `Melee`; slots médicos não são bloqueados por esse script.

## 3) Fluxo de validação de attachment no engine (visão prática)

1. Jogador tenta anexar item no container.
2. Engine checa se o receptor tem o slot em `attachments[]`.
3. Engine checa se o item declara o mesmo slot em `inventorySlot[]`.
4. Engine executa validações de runtime (`CanReceiveAttachment`, `CanPutAsAttachment`, bloqueios de estado/ruína/etc.).
5. Se tudo passar, o attachment acontece e callbacks (`EEItemAttached`) são disparados.

## 4) Pontos de modificação no seu projeto

Para permitir anexar kits médicos Terje nas mochilas principais:

1. **CfgVehicles (mochilas)**
   - Acrescentar `MedicalPouchSlot` em `attachments[]` das `SurvivorBackpack_*`.

2. **CfgVehicles (kits médicos)**
   - Acrescentar `FirstAidKit` e `MedicalPouchSlot` em `inventorySlot[]` das classes `TerjeFirstAidKit*`.

3. **CfgSlots**
   - Criar `Slot_MedicalPouchSlot` com `name = "MedicalPouchSlot"`.

4. **Script C (opcional)**
   - Só necessário se você quiser regra extra por tipo/item (ex.: só aceitar classes médicas específicas em determinado slot).

## 5) Código ajustado

Arquivo: `TerjeMedicine/Compatibility/ProjectHopeBackpack_TerjeMedicine_Attachments.cpp`

- Define patch de compatibilidade.
- Cria `Slot_MedicalPouchSlot`.
- Anexa esse slot às mochilas `SurvivorBackpack_*`.
- Permite que `TerjeFirstAidKit*` usem `FirstAidKit` e `MedicalPouchSlot`.

## 6) Guia para novos itens (camisa, calça, cinto, bota e outros)

Use sempre o mesmo padrão estrutural:

1. Criar classe base em `CfgVehicles` herdando da categoria correta (`Clothing`, `Container_Base`, etc.).
2. Definir propriedades físicas/visuais (model, hiddenSelections, cargo, peso, etc.).
3. Se for anexável, declarar `inventorySlot[]` no item.
4. No receptor (roupa/mochila/colete), declarar `attachments[]` com os slots aceitos.
5. Criar slot novo em `CfgSlots` quando não existir um adequado.
6. Só depois adicionar validação em script quando a regra não puder ser expressa apenas em config.

Regra prática: **compatibilidade de inventário em DayZ é “interseção de slot” + “regras de script”**.
