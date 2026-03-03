modded class AreaExposureMdfr
{
	override void BleedingSourceCreateCheck(PlayerBase player)
	{
		bool biohazardSkinIrritation = false;
		if (GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_BIOHAZARD_SKIN_IRRITATION, biohazardSkinIrritation) && biohazardSkinIrritation)
		{
			super.BleedingSourceCreateCheck(player);
		}
	}
	
	override void ApplyAgentsToBleedingSources(PlayerBase player, float deltaT)
	{
		super.ApplyAgentsToBleedingSources(player, deltaT);
		
		if (player && player.GetTerjeStats())
		{
			int openWounds = player.GetTerjeStats().GetStubWounds();
			if (openWounds > 0)
			{
				player.InsertAgent(eAgents.CHEMICAL_POISON, openWounds * deltaT);
			}
		}
	}
}
