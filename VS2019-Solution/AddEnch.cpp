#include "AddEnch.h"

#define _SETCN(cnstring) QString::fromLocal8Bit(cnstring)  //QT5��settext�����������룬��Ҫ�ô˴�����


AddEnch::AddEnch(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	connect(ui.btnAddEnch, SIGNAL(clicked()), this, SLOT(EnchAdd()));

}

void AddEnch::setLanCNs()
{
	this->setWindowTitle(SETCN("��Ӹ�ħ"));

	ui.btnAddEnch->setText(SETCN("���"));
	ui.btnCancel->setText(SETCN("ȡ��"));
	ui.lbITEM->setText(SETCN("��Ʒ: "));
	ui.lbEnch->setText(SETCN("��ħ"));
	ui.lbLvl->setText(SETCN("�ȼ�"));
	ui.groupBox->setTitle(SETCN("��ħ�趨"));

	ui.cbbEnchantments->setItemText(0, SETCN("����"));
	ui.cbbEnchantments->setItemText(1, SETCN("���汣��"));
	ui.cbbEnchantments->setItemText(2, SETCN("ˤ�䱣��"));
	ui.cbbEnchantments->setItemText(3, SETCN("��ը����"));
	ui.cbbEnchantments->setItemText(4, SETCN("�����ﱣ��"));
	ui.cbbEnchantments->setItemText(5, SETCN("ˮ�º���"));
	ui.cbbEnchantments->setItemText(6, SETCN("ˮ���پ�"));
	ui.cbbEnchantments->setItemText(7, SETCN("����"));
	ui.cbbEnchantments->setItemText(8, SETCN("�̽����"));
	ui.cbbEnchantments->setItemText(9, SETCN("��˪����"));
	ui.cbbEnchantments->setItemText(10, SETCN("������"));
	ui.cbbEnchantments->setItemText(11, SETCN("����"));
	ui.cbbEnchantments->setItemText(12, SETCN("����ɱ��"));
	ui.cbbEnchantments->setItemText(13, SETCN("��֫ɱ��"));
	ui.cbbEnchantments->setItemText(14, SETCN("����"));
	ui.cbbEnchantments->setItemText(15, SETCN("���渽��"));
	ui.cbbEnchantments->setItemText(16, SETCN("����"));
	ui.cbbEnchantments->setItemText(17, SETCN("��ɨ֮��"));
	ui.cbbEnchantments->setItemText(18, SETCN("Ч��"));
	ui.cbbEnchantments->setItemText(19, SETCN("��׼�ɼ�"));
	ui.cbbEnchantments->setItemText(20, SETCN("�;�"));
	ui.cbbEnchantments->setItemText(21, SETCN("ʱ��"));
	ui.cbbEnchantments->setItemText(22, SETCN("����"));
	ui.cbbEnchantments->setItemText(23, SETCN("���"));
	ui.cbbEnchantments->setItemText(24, SETCN("��ʸ"));
	ui.cbbEnchantments->setItemText(25, SETCN("����"));
	ui.cbbEnchantments->setItemText(26, SETCN("��֮���"));
	ui.cbbEnchantments->setItemText(27, SETCN("����"));
	ui.cbbEnchantments->setItemText(28, SETCN("�ҳ�(1.13+)"));
	ui.cbbEnchantments->setItemText(29, SETCN("����(1.13+)"));
	ui.cbbEnchantments->setItemText(30, SETCN("����(1.13+)"));
	ui.cbbEnchantments->setItemText(31, SETCN("����(1.13+)"));
	ui.cbbEnchantments->setItemText(32, SETCN("�����޲�"));
	ui.cbbEnchantments->setItemText(33, SETCN("��ʧ����"));
	ui.cbbEnchantments->setItemText(34, SETCN("�������(1.14+)"));
	ui.cbbEnchantments->setItemText(35, SETCN("��͸(1.14+)"));
	ui.cbbEnchantments->setItemText(36, SETCN("����װ��(1.14+)"));
}

void AddEnch::setLanUS()
{
	this->setWindowTitle("AddEnchantment");

	ui.btnAddEnch->setText("Add");
	ui.btnCancel->setText("Cancel");
	ui.lbITEM->setText("Item: ");
	ui.lbEnch->setText("Enchantment");
	ui.lbLvl->setText("Level");
	ui.groupBox->setTitle("Enchantment Settings");

	ui.cbbEnchantments->setItemText(0, "Protection");
	ui.cbbEnchantments->setItemText(1, "Fire Protection");
	ui.cbbEnchantments->setItemText(2, "Feather Falling");
	ui.cbbEnchantments->setItemText(3, "Blast Protection");
	ui.cbbEnchantments->setItemText(4, "Projectile Protection");
	ui.cbbEnchantments->setItemText(5, "Respiration");
	ui.cbbEnchantments->setItemText(6, "AquaAffinity");
	ui.cbbEnchantments->setItemText(7, "Thorns");
	ui.cbbEnchantments->setItemText(8, "Depth Strider");
	ui.cbbEnchantments->setItemText(9, "Frost Walker");
	ui.cbbEnchantments->setItemText(10, "Curse Of Binding");
	ui.cbbEnchantments->setItemText(11, "Sharpness");
	ui.cbbEnchantments->setItemText(12, "Smite");
	ui.cbbEnchantments->setItemText(13, "Bane Of Arthropods");
	ui.cbbEnchantments->setItemText(14, "KnockBack");
	ui.cbbEnchantments->setItemText(15, "Fire Aspect");
	ui.cbbEnchantments->setItemText(16, "Looting");
	ui.cbbEnchantments->setItemText(17, "Sweeping Edge");
	ui.cbbEnchantments->setItemText(18, "Efficiency");
	ui.cbbEnchantments->setItemText(19, "Silk Touch");
	ui.cbbEnchantments->setItemText(20, "Unbreaking");
	ui.cbbEnchantments->setItemText(21, "Fortune");
	ui.cbbEnchantments->setItemText(22, "Power");
	ui.cbbEnchantments->setItemText(23, "Punch");
	ui.cbbEnchantments->setItemText(24, "Flame");
	ui.cbbEnchantments->setItemText(25, "Infinity");
	ui.cbbEnchantments->setItemText(26, "Luck Of The Sea");
	ui.cbbEnchantments->setItemText(27, "Lure");
	ui.cbbEnchantments->setItemText(28, "Loyalty(1.13+)");
	ui.cbbEnchantments->setItemText(29, "Impaling(1.13+)");
	ui.cbbEnchantments->setItemText(30, "Riptide(1.13+)");
	ui.cbbEnchantments->setItemText(31, "Channeling(1.13+)");
	ui.cbbEnchantments->setItemText(32, "Mending");
	ui.cbbEnchantments->setItemText(33, "Curse Of Vanishing");
	ui.cbbEnchantments->setItemText(34, "Multishot(1.14+)");
	ui.cbbEnchantments->setItemText(35, "Piercing(1.14+)");
	ui.cbbEnchantments->setItemText(36, "Quick Charge(1.14+)");
}

AddEnch::~AddEnch()
{
}

void AddEnch::EnchAdd()
{
	NBTstr::EnchIndex = ui.cbbEnchantments->currentIndex();
	NBTstr::Enchlvl = ui.spbLvl->value();
	NBTstr::EnchShow = ui.cbbEnchantments->currentText();

	this->accept();
}

