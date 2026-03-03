modded class PH_Backpack_01_ColorBase
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		string slot_name = InventorySlots.GetSlotName(slotId);

		if (slot_name == "MedicalPouchSlot" || slot_name == "FirstAidKit")
		{
			string attachmentType = attachment.GetType();

			if (attachmentType.Contains("TerjeFirstAidKit"))
				return true;
		}

		return super.CanReceiveAttachment(attachment, slotId);
	}
};
