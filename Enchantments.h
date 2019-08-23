#pragma once


enum _Ench
{
	/**����λ�ø�ħ**/
	Protection,           //����
	FireProt,             //���汣��
	FeatherFalling,       //ˤ�䱣��
	BlastProt,            //��ը����
	ProjectileProt,       //�����ﱣ��
	Respiration,          //ˮ�º���
	AquaAffinity,         //ˮ���پ�
	Thorns,               //����
	DepthStrider,         //�̽����
	FrostWalker,          //��˪����

	CurseOfBinding,       ///������

	/*///ռλ��
	ph11,
	ph12,
	ph13,
	ph14,
	ph15,
	*/

	/**�ֳ���Ʒ��ħ**/
	
	//���฽ħ��ǰ���������ڸ�ͷ��
	Sharpness,            //����
	Smite,                //����ɱ��
	BaneOfArthropods,     //��֫ɱ��
	KnockBack,            //����
	FireAspect,           //���渽��
	Looting,              //����
	SweepingEdge,         //��ɨ֮��

	/*///ռλ��
	ph23,
	ph24,
	ph25,
	ph26,
	ph27,
	ph28,
	ph29,
	ph30,
	ph31,
	*/

	//�����฽ħ
	Efficiency,           //Ч��
	SilkTouch,            //��׼�ɼ�
	Unbreaking,           //�;�
	Fortune,              //ʱ��
	
	/*///ռλ��
	ph36,
	ph37,
	ph38,
	ph39,
	ph40,
	ph41,
	ph42,
	ph43,
	ph44,
	ph45,
	ph46,
	ph47,
	*/

	//����ħ
	Power,                //����
	Punch,                //���
	Flame,                //��ʸ
	Infinity,             //����

	/*///ռλ��
	ph52,
	ph53,
	ph54,
	ph55,
	ph56,
	ph57,
	ph58,
	ph59,
	ph60,
	*/

	//���͸�ħ
	LuckOfTheSea,         //����
	Lure,                 //����

	/*///ռλ��
	ph63,
	ph64,
	*/

	//����ꪸ�ħ(1.13+)
	Loyalty,              //�ҳ�
	Impaling,             //����
	Riptide,              //����
	Channeling,           //����
	
    /*///ռλ��
	ph69,
	*/

	Mending,              //�����޲�

	CurseOfVanishing,     ///��ʧ����

	//ʮ�ֹ���ħ��1.14+��*�˺�ħû������ID
	Multishot,            //�������
	Piercing,             //��͸
	QuickCharge           //����װ��

} Ench_em;             //��ħ ö��


QString setEnch(int ench__) //��enum�е�ֵת��Ϊ��Ӧ��QString���͵ĸ�ħ����
{
	switch (ench__)
	{
	case Protection:
		return "protection";
	case FireProt:
		return "fire_protection";
	case FeatherFalling:
		return "feather_falling";
	case BlastProt:
		return "blast_protection";
	case ProjectileProt:
		return "projectile_protection";
	case Respiration:
		return "respiration";
	case AquaAffinity:
		return "aqua_affinity";
	case Thorns:
		return "thorns";
	case DepthStrider:
		return "depth_strider";
	case FrostWalker:
		return "frost_walker";
	case CurseOfBinding:
		return "binding_curse";
	case Sharpness:
		return "sharpness";
	case Smite:
		return "smite";
	case BaneOfArthropods:
		return "bane_of_arthropods";
	case KnockBack:
		return "knockback";
	case FireAspect:
		return "fire_aspect";
	case Looting:
		return "looting";
	case SweepingEdge:
		return "sweeping";
	case Efficiency:
		return "efficiency";
	case SilkTouch:
		return "silk_touch";
	case Unbreaking:
		return "unbreaking";
	case Fortune:
		return "fortune";
	case Power:
		return "power";
	case Punch:
		return "punch";
	case Flame:
		return "flame";
	case Infinity:
		return "infinity";
	case LuckOfTheSea:
		return "luck_of_the_sea";
	case Lure:
		return "lure";
	case Loyalty:
		return "loyalty";
	case Impaling:
		return "impaling";
	case Riptide:
		return "riptide";
	case Channeling:
		return "channeling";
	case Mending:
		return "mending";
	case CurseOfVanishing:
		return "vanishing_curse";
	case Multishot:
		return "multishot";
	case Piercing:
		return "piercing";
	case QuickCharge:
		return "quick_charge";

	default:
		return "Error";
	}
}

void EnchSwitchForm(QString* ench_, bool isUnder12 = false)
{
	if (isUnder12 == true)
	{


		ench_->replace("blast_protection", "3");
		ench_->replace("projectile_protection", "4");
		ench_->replace("fire_protection", "1");
		//���ϸ�ħ�����滻�ַ����ؼ����뱣����ħ���ظ����������滻
		ench_->replace("protection", "0");
		ench_->replace("feather_falling", "2");

		ench_->replace("respiration", "5");
		ench_->replace("aqua_affinity", "6");
		ench_->replace("thorns", "7");
		ench_->replace("depth_strider", "8");
		ench_->replace("frost_walker", "9");
		ench_->replace("binding_curse", "10");

		ench_->replace("sharpness", "16");
		ench_->replace("smite", "17");
		ench_->replace("bane_of_arthropods", "18");
		ench_->replace("knockback", "19");
		ench_->replace("fire_aspect", "20");
		ench_->replace("looting", "21");
		ench_->replace("sweeping", "22");

		ench_->replace("efficiency", "32");
		ench_->replace("silk_touch", "33");
		ench_->replace("unbreaking", "34");
		ench_->replace("fortune", "35");

		ench_->replace("power", "48");
		ench_->replace("punch", "49");
		ench_->replace("flame", "50");
		ench_->replace("infinity", "51");

		ench_->replace("luck_of_the_sea", "61");
		ench_->replace("lure", "62");

		ench_->replace("loyalty", "65");
		ench_->replace("impaling", "66");
		ench_->replace("riptide", "67");
		ench_->replace("channeling", "68");

		ench_->replace("mending", "70");
		ench_->replace("vanishing_curse", "71");
	}
	else if (isUnder12 == false)
	{
		ench_->replace("id:0", "id:protection");
		ench_->replace("id:1", "id:fire_protection");
		ench_->replace("id:2", "id:feather_falling");
		ench_->replace("id:3", "id:blast_protection");
		ench_->replace("id:4", "id:projectile_protection");
		ench_->replace("id:5", "id:respiration");
		ench_->replace("id:6", "id:aqua_affinity");
		ench_->replace("id:7", "id:thorns");
		ench_->replace("id:8", "id:depth_strider");
		ench_->replace("id:9", "id:frost_walker");
		ench_->replace("id:10", "id:binding_curse");

		ench_->replace("id:16", "id:sharpness");
		ench_->replace("id:17", "id:smite");
		ench_->replace("id:18", "id:bane_of_arthropods");
		ench_->replace("id:19", "id:knockback");
		ench_->replace("id:20", "id:fire_aspect");
		ench_->replace("id:21", "id:looting");
		ench_->replace("id:22", "id:sweeping");

		ench_->replace("id:32", "id:efficiency");
		ench_->replace("id:33", "id:silk_touch");
		ench_->replace("id:34", "id:unbreaking");
		ench_->replace("id:35", "id:fortune");

		ench_->replace("id:48", "id:power");
		ench_->replace("id:49", "id:punch");
		ench_->replace("id:50", "id:flame");
		ench_->replace("id:51", "id:infinity");

		ench_->replace("id:61", "id:luck_of_the_sea");
		ench_->replace("id:62", "id:lure");

		ench_->replace("id:65", "id:loyalty");
		ench_->replace("id:66", "id:impaling");
		ench_->replace("id:67", "id:riptide");
		ench_->replace("id:68", "id:channeling");

		ench_->replace("id:70", "id:mending");
		ench_->replace("id:71", "id:vanishing_curse");
	}

	/************************
	*
	*�������    multishot
	*��͸        piercing
	*����װ��    quick_charge
	*
	*�����ħû�����ֱ��
	*
	************************/
}