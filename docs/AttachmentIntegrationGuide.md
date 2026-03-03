# Compat addon pronto para gerar PBO direto

Este repositório agora inclui um addon de compatibilidade com estrutura pronta para empacotar:

```text
addons/
  ProjectHopeBackpack_TerjeMedicine_Attachments/
    config.cpp
    scripts/
      4_World/
        Entities/
          ItemBase/
            Clothing/
              PH_Backpack_01_ColorBase.c
```

## Como compilar para PBO

1. Use **a pasta `addons/ProjectHopeBackpack_TerjeMedicine_Attachments` como raiz do pack**.
2. O `config.cpp` já define:
   - `CfgPatches` com `requiredAddons` para `ProjectHopeBackpack` e `TerjeMedicine_FirstAidKit`;
   - `CfgSlots` com `MedicalPouchSlot`;
   - extensões em `CfgVehicles` para mochilas `SurvivorBackpack_*` e kits `TerjeFirstAidKit*`.
3. O script `modded class PH_Backpack_01_ColorBase` roda via `CfgMods`/`worldScriptModule` e libera attachment médico apenas para classes `TerjeFirstAidKit*` nos slots `MedicalPouchSlot`/`FirstAidKit`.

## Observações importantes

- O arquivo base do mod original `scripts/4_World/Entities/ItemBase/Clothing/PH_Backpack_01_ColorBase.c` foi restaurado.
- A lógica de compatibilidade agora está isolada no addon de compat, evitando edição direta do mod principal.
- O arquivo legado `TerjeMedicine/Compatibility/ProjectHopeBackpack_TerjeMedicine_Attachments.cpp` foi removido para não gerar ambiguidade de build.
