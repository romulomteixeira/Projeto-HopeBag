// Integration patch between ProjectHopeBackpack and TerjeMedicine.
// This file is written as a normal DayZ config source and should be packed in a small compatibility PBO.

class CfgPatches
{
	class ProjectHopeBackpack_TerjeMedicine_Attachments
	{
		// Unique patch id for this compatibility layer.
		name = "ProjectHopeBackpack + TerjeMedicine Attachments";
		author = "Projeto-HopeBag";

		// We only define config extensions, not new world entities.
		units[] = {};
		weapons[] = {};

		// Load after both original mods so class inheritance and array merging are valid.
		requiredAddons[] =
		{
			"ProjectHopeBackpack",
			"TerjeMedicine_FirstAidKit"
		};
	};
};

class CfgSlots
{
	class Slot_MedicalPouchSlot
	{
		// Internal slot identifier used by inventorySlot[] / attachments[].
		name = "MedicalPouchSlot";

		// UI text shown to players.
		displayName = "Medical Pouch";

		// Optional icon, can be replaced by your own imageset icon.
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
};

class CfgVehicles
{
	class Container_Base;
	class PH_Backpack_01_ColorBase;
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
		// Enable our new custom slot on this backpack variant.
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
		// Keep vanilla/provided slots and append compatibility slots.
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
