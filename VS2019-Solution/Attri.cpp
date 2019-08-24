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
	//�жϼ��㷽ʽ��Operation��
	if (ui.rbtnAddi->isChecked() == true)
	{
		//����
		NBTstr::AttriOperation = "0";
	}
	else 
	{
		//����
		NBTstr::AttriOperation = "1";
	}
	NBTstr::AttriNameShow = ui.cbbAttriName->currentText();     //��ȡ��ʾ�õ�Attribute����
	NBTstr::AttriNameIndex = ui.cbbAttriName->currentIndex();   //��ȡAttribute���Ƶ�����

	NBTstr::AttriSlotShow = ui.cbbAttriSlot->currentText();     //��ȡ��ʹ�õ�Attribute��λ
	NBTstr::AttriSlotIndex = ui.cbbAttriSlot->currentIndex();   //��ȡAttribute��λ������

	//�ж�Infinity��CheckBox�Ƿ񱻹�ѡ
	if (ui.chbInfinity->isChecked() == false)
	{
		//��ȡAttribute����ֵ -> ת��ΪQString��ʽ
		NBTstr::AttriAmount = QString::number(ui.dspbAmount->value());
	}
	else
	{
		//����Attribute����ֵΪ����
		NBTstr::AttriAmount = "Infinity";
	}

	SetAttri();

	this->accept();  //��exec()����1
}

void Attri::setInfinity()
{
	//�ж�Infinity��CheckBox�Ƿ񱻹�ѡ
	if (ui.chbInfinity->isChecked() == true)
	{
		//����������ֵSpinBox
		ui.dspbAmount->setDisabled(true);
	}
	else
	{
		//������������ֵSpinBox
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

		ui.lbITEM->setText(SETCN("��Ʒ: "));
		ui.lbAttriName->setText(SETCN("��������"));
		ui.lbSlot->setText(SETCN("��λ"));
		ui.lbAmount->setText(SETCN("��ֵ"));

		ui.gbAttriEditor->setTitle(SETCN("���Ա༭"));
		ui.gbNumValue->setTitle(SETCN("��ֵ�༭"));

		ui.rbtnAddi->setText(SETCN("����"));
		ui.rbtnMulti->setText(SETCN("����"));
		ui.btnAddAttri->setText(SETCN("���"));
		ui.btnCancel->setText(SETCN("ȡ��"));

		ui.chbInfinity->setText(SETCN("����"));

		ui.cbbAttriName->setItemText(0, SETCN("�����˺�"));
		ui.cbbAttriName->setItemText(1, SETCN("�����ٶ�"));
		ui.cbbAttriName->setItemText(2, SETCN("����"));
		ui.cbbAttriName->setItemText(3, SETCN("��������"));
		ui.cbbAttriName->setItemText(4, SETCN("����"));
		ui.cbbAttriName->setItemText(5, SETCN("�����뾶"));
		ui.cbbAttriName->setItemText(6, SETCN("�����ٶ�"));
		ui.cbbAttriName->setItemText(7, SETCN("�������ֵ"));
		ui.cbbAttriName->setItemText(8, SETCN("����������"));
		ui.cbbAttriName->setItemText(9, SETCN("���˿���"));
		ui.cbbAttriName->setItemText(10, SETCN("�ƶ��ٶ�"));

		ui.cbbAttriSlot->setItemText(0, SETCN("����"));
		ui.cbbAttriSlot->setItemText(1, SETCN("����"));
		ui.cbbAttriSlot->setItemText(2, SETCN("ͷ��"));
		ui.cbbAttriSlot->setItemText(3, SETCN("�ز�"));
		ui.cbbAttriSlot->setItemText(4, SETCN("�Ȳ�"));
		ui.cbbAttriSlot->setItemText(5, SETCN("��"));
	}
}

void Attri::setItemID(QString ID_)
{
	ui.lbItmID->setText(ID_);
}

enum AttributeName_
{
	AttackDamage,            //�����˺�
	AttackSpeed,             //�����ٶ�
	Armor,                   //����
	ArmorToughness,          //��������
	Luck,                    //����
	ReachDistance,           //�����뾶
	FlyingSpeed,             //�����ٶ�
	MaxHealth,               //�������ֵ
	MobFollowRange,          //����������
	KnockbackResistance,     //���˿���
	MovementSpeed              //�ƶ��ٶ�
};

enum AttributeSlot_
{
	MainHand,                //����
	OffHand,                 //����
	Head,                    //ͷ
	Chest,                   //��
	Legs,                    //��
	Feet                     //��
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