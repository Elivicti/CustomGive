#include "Attri.h"

QString nameStr = "";
QString slotStr = "";

void SetAttri();

Attri::Attri(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnAddAttri, SIGNAL(clicked()), this, SLOT(addAttri()));
	connect(ui.chbInfinity, SIGNAL(clicked()), this, SLOT(setInfinity()));

	
}

void Attri::addAttri()
{
	//判断计算方式（Operation）
	if (ui.rbtnAddi->isChecked() == true)
	{
		//加算
		NBTstr::AttriOperation = "0";
	}
	else 
	{
		//乘算
		NBTstr::AttriOperation = "1";
	}
	NBTstr::AttriNameShow = ui.cbbAttriName->currentText();     //获取显示用的Attribute名称
	NBTstr::AttriNameIndex = ui.cbbAttriName->currentIndex();   //获取Attribute名称的索引

	NBTstr::AttriSlotShow = ui.cbbAttriSlot->currentText();     //获取先使用的Attribute槽位
	NBTstr::AttriSlotIndex = ui.cbbAttriSlot->currentIndex();   //获取Attribute槽位的索引

	//判断Infinity的CheckBox是否被勾选
	if (ui.chbInfinity->isChecked() == false)
	{
		//获取Attribute的数值 -> 转化为QString格式
		NBTstr::AttriAmount = QString::number(ui.dspbAmount->value());
	}
	else
	{
		//设置Attribute的数值为无限
		NBTstr::AttriAmount = "Infinity";
	}

	SetAttri();

	this->accept();  //让exec()返回1
}

void Attri::setInfinity()
{
	//判断Infinity的CheckBox是否被勾选
	if (ui.chbInfinity->isChecked() == true)
	{
		//禁用输入数值SpinBox
		ui.dspbAmount->setDisabled(true);
	}
	else
	{
		//启用用输入数值SpinBox
		ui.dspbAmount->setDisabled(false);
	}
}


void Attri::setLang(int lan)
{
	if (lan == ENGUS)
	{
		ui.lbITEM->setText("Item: ");
		ui.lbAttriName->setText("Attribute Name");
		ui.lbSlot->setText("Slot");
		ui.lbAmount->setText("Amount");

		ui.gbAttriEditor->setTitle("Attribute Editor");
		ui.gbNumValue->setTitle("Numerical Value");

		ui.rbtnAddi->setText("Additive");
		ui.rbtnMulti->setText("Multiplicative");
		ui.btnAddAttri->setText("Add");
		ui.btnCancel->setText("Cancel");

		ui.chbInfinity->setText("Infinity");

		ui.cbbAttriName->setItemText(0, "Attack Damage");
		ui.cbbAttriName->setItemText(1, "Attack Speed");
		ui.cbbAttriName->setItemText(2, "Armor");
		ui.cbbAttriName->setItemText(3, "Armor Toughness");
		ui.cbbAttriName->setItemText(4, "Luck");
		ui.cbbAttriName->setItemText(5, "Reach Distance");
		ui.cbbAttriName->setItemText(6, "Flying Speed");
		ui.cbbAttriName->setItemText(7, "Max Health");
		ui.cbbAttriName->setItemText(8, "Mob Follow Range");
		ui.cbbAttriName->setItemText(9, "Knockback Resistance");
		ui.cbbAttriName->setItemText(10, "Movement Speed");

		ui.cbbAttriSlot->setItemText(0, "MainHand");
		ui.cbbAttriSlot->setItemText(1, "OffHand");
		ui.cbbAttriSlot->setItemText(2, "Head");
		ui.cbbAttriSlot->setItemText(3, "Chest");
		ui.cbbAttriSlot->setItemText(4, "Legs");
		ui.cbbAttriSlot->setItemText(5, "Feet");
	}
	else if (lan == CNSIMP)
	{

		ui.lbITEM->setText(SETCN("物品: "));
		ui.lbAttriName->setText(SETCN("属性名称"));
		ui.lbSlot->setText(SETCN("槽位"));
		ui.lbAmount->setText(SETCN("数值"));

		ui.gbAttriEditor->setTitle(SETCN("属性编辑"));
		ui.gbNumValue->setTitle(SETCN("数值编辑"));

		ui.rbtnAddi->setText(SETCN("加算"));
		ui.rbtnMulti->setText(SETCN("乘算"));
		ui.btnAddAttri->setText(SETCN("添加"));
		ui.btnCancel->setText(SETCN("取消"));

		ui.chbInfinity->setText(SETCN("无限"));

		ui.cbbAttriName->setItemText(0, SETCN("攻击伤害"));
		ui.cbbAttriName->setItemText(1, SETCN("攻击速度"));
		ui.cbbAttriName->setItemText(2, SETCN("盔甲"));
		ui.cbbAttriName->setItemText(3, SETCN("盔甲韧性"));
		ui.cbbAttriName->setItemText(4, SETCN("幸运"));
		ui.cbbAttriName->setItemText(5, SETCN("触及半径"));
		ui.cbbAttriName->setItemText(6, SETCN("飞行速度"));
		ui.cbbAttriName->setItemText(7, SETCN("最大生命值"));
		ui.cbbAttriName->setItemText(8, SETCN("生物跟随距离"));
		ui.cbbAttriName->setItemText(9, SETCN("击退抗性"));
		ui.cbbAttriName->setItemText(10, SETCN("移动速度"));

		ui.cbbAttriSlot->setItemText(0, SETCN("主手"));
		ui.cbbAttriSlot->setItemText(1, SETCN("副手"));
		ui.cbbAttriSlot->setItemText(2, SETCN("头部"));
		ui.cbbAttriSlot->setItemText(3, SETCN("胸部"));
		ui.cbbAttriSlot->setItemText(4, SETCN("腿部"));
		ui.cbbAttriSlot->setItemText(5, SETCN("脚"));
	}
}

void Attri::setItemID(QString ID_)
{
	ui.lbItmID->setText(ID_);
}

enum AttributeName_
{
	AttackDamage,            //攻击伤害
	AttackSpeed,             //攻击速度
	Armor,                   //盔甲
	ArmorToughness,          //盔甲韧性
	Luck,                    //幸运
	ReachDistance,           //触及半径
	FlyingSpeed,             //飞行速度
	MaxHealth,               //最大生命值
	MobFollowRange,          //生物跟随距离
	KnockbackResistance,     //击退抗性
	MovementSpeed              //移动速度
};

enum AttributeSlot_
{
	MainHand,                //主手
	OffHand,                 //副手
	Head,                    //头
	Chest,                   //胸
	Legs,                    //腿
	Feet                     //脚
};

void SetAttri()
{
	switch (NBTstr::AttriNameIndex)
	{
	case AttackDamage:
		nameStr = "\"generic.attackDamage\"";
		break;
	case AttackSpeed:
		nameStr = "\"generic.attackSpeed\"";
		break;
	case Armor:
		nameStr = "\"generic.armor\"";
		break;
	case ArmorToughness:
		nameStr = "\"generic.armorToughness\"";
		break;
	case Luck:
		nameStr = "\"generic.luck\"";
		break;
	case ReachDistance:
		nameStr = "\"generic.reachDistance\"";
		break;
	case FlyingSpeed:
		nameStr = "\"generic.flyingSpeed\"";
		break;
	case MaxHealth:
		nameStr = "\"generic.maxHealth\"";
		break;
	case MobFollowRange:
		nameStr = "\"eneric.followRange\"";
		break;
	case KnockbackResistance:
		nameStr = "\"generic.knockbackResistance\"";
		break;
	case MovementSpeed:
		nameStr = "\"generic.movementSpeed\"";
		break;
	}


	switch (NBTstr::AttriSlotIndex)
	{
	case MainHand:
		slotStr = "\"mainhand\"";
		break;
	case OffHand:
		slotStr = "\"offhand\"";
		break;
	case Head:
		slotStr = "\"head\"";
		break;
	case Chest:
		slotStr = "\"chest\"";
		break;
	case Legs:
		slotStr = "\"legs\"";
		break;
	case Feet:
		slotStr = "\"feet\"";
		break;
	}
}

QString Attri::SetAttriStr(int UUID)
{
	
	QString AttriNBT_Model = "{UUIDMost:%d,UUIDLeast:%d,Amount:%amount,Slot:%slot,AttributeName:%name,Operation:%opera,Name:%name}";
	AttriNBT_Model.replace("%d", QString::number(UUID));
	AttriNBT_Model.replace("%amount", NBTstr::AttriAmount);
	AttriNBT_Model.replace("%slot", slotStr);
	AttriNBT_Model.replace("%name", nameStr);
	AttriNBT_Model.replace("%opera", NBTstr::AttriOperation);

	return AttriNBT_Model;
}