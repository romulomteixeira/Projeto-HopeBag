class CfgPatches
{
	class ProjectHopeBackpack_TerjeMedicine_Attachments
	{
		name = "ProjectHopeBackpack + TerjeMedicine Attachments";
		author = "Projeto-HopeBag";
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"ProjectHopeBackpack",
			"TerjeMedicine_FirstAidKit"
		};
	};
};

class CfgMods
{
	class ProjectHopeBackpack_TerjeMedicine_Attachments
	{
		type = "mod";

		class defs
		{
			class worldScriptModule
			{
				files[] =
				{
					"ProjectHopeBackpack_TerjeMedicine_Attachments/scripts/4_World"
				};
			};
		};
	};
};

class CfgSlots
{
	class Slot_MedicalPouchSlot
	{
		name = "MedicalPouchSlot";
		displayName = "Medical Pouch";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
};

class CfgVehicles
{
	class SurvivorBackpack_Black;
	class SurvivorBackpack_Blue;
	class SurvivorBackpack_Green;
	class SurvivorBackpack_Pink;
	class SurvivorBackpack_Red;
	class SurvivorBackpack_Yellow;
	class TerjeFirstAidKitAdvancedBase;
	class TerjeFirstAidKitIndividualBase;
	class TerjeFirstAidKitMedium;
	class TerjeFirstAidKitLarge;

	class SurvivorBackpack_Black: SurvivorBackpack_Black
	{
		attachments[] += { "MedicalPouchSlot" };
	};

	class SurvivorBackpack_Blue: SurvivorBackpack_Blue
	{
		attachments[] += { "MedicalPouchSlot" };
	};

	class SurvivorBackpack_Green: SurvivorBackpack_Green
	{
		attachments[] += { "MedicalPouchSlot" };
	};

	class SurvivorBackpack_Pink: SurvivorBackpack_Pink
	{
		attachments[] += { "MedicalPouchSlot" };
	};

	class SurvivorBackpack_Red: SurvivorBackpack_Red
	{
		attachments[] += { "MedicalPouchSlot" };
	};

	class SurvivorBackpack_Yellow: SurvivorBackpack_Yellow
	{
		attachments[] += { "MedicalPouchSlot" };
	};

	class TerjeFirstAidKitAdvancedBase: TerjeFirstAidKitAdvancedBase
	{
		inventorySlot[] += { "FirstAidKit", "MedicalPouchSlot" };
	};

	class TerjeFirstAidKitIndividualBase: TerjeFirstAidKitIndividualBase
	{
		inventorySlot[] += { "FirstAidKit", "MedicalPouchSlot" };
	};

	class TerjeFirstAidKitMedium: TerjeFirstAidKitMedium
	{
		inventorySlot[] += { "FirstAidKit", "MedicalPouchSlot" };
	};

	class TerjeFirstAidKitLarge: TerjeFirstAidKitLarge
	{
		inventorySlot[] += { "FirstAidKit", "MedicalPouchSlot" };
	};
};
