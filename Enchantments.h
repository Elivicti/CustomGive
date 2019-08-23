#pragma once


enum _Ench
{
	/**盔甲位置附魔**/
	Protection,           //保护
	FireProt,             //火焰保护
	FeatherFalling,       //摔落保护
	BlastProt,            //爆炸保护
	ProjectileProt,       //弹射物保护
	Respiration,          //水下呼吸
	AquaAffinity,         //水下速掘
	Thorns,               //荆棘
	DepthStrider,         //深海探索者
	FrostWalker,          //冰霜行者

	CurseOfBinding,       ///绑定诅咒

	/*///占位符
	ph11,
	ph12,
	ph13,
	ph14,
	ph15,
	*/

	/**手持物品附魔**/
	
	//剑类附魔（前三个可用于斧头）
	Sharpness,            //锋利
	Smite,                //亡灵杀手
	BaneOfArthropods,     //节肢杀手
	KnockBack,            //击退
	FireAspect,           //火焰附加
	Looting,              //抢夺
	SweepingEdge,         //横扫之刃

	/*///占位符
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

	//工具类附魔
	Efficiency,           //效率
	SilkTouch,            //精准采集
	Unbreaking,           //耐久
	Fortune,              //时运
	
	/*///占位符
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

	//弓附魔
	Power,                //力量
	Punch,                //冲击
	Flame,                //火矢
	Infinity,             //无限

	/*///占位符
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

	//钓竿附魔
	LuckOfTheSea,         //深海眷顾
	Lure,                 //钓饵

	/*///占位符
	ph63,
	ph64,
	*/

	//三叉戟附魔(1.13+)
	Loyalty,              //忠诚
	Impaling,             //穿刺
	Riptide,              //激流
	Channeling,           //引雷
	
    /*///占位符
	ph69,
	*/

	Mending,              //经验修补

	CurseOfVanishing,     ///消失诅咒

	//十字弓附魔（1.14+）*此后附魔没有数字ID
	Multishot,            //多重射击
	Piercing,             //穿透
	QuickCharge           //快速装填

} Ench_em;             //附魔 枚举


QString setEnch(int ench__) //把enum中的值转化为相应的QString类型的附魔名称
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
		//以上附魔由于替换字符串关键词与保护附魔有重复，需先行替换
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
	*多重射击    multishot
	*穿透        piercing
	*快速装填    quick_charge
	*
	*此三项附魔没有数字编号
	*
	************************/
}