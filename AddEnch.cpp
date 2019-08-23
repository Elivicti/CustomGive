#include "AddEnch.h"

#define _SETCN(cnstring) QString::fromLocal8Bit(cnstring)  //QT5用settext设置中文乱码，需要用此代码解决


AddEnch::AddEnch(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	connect(ui.btnAddEnch, SIGNAL(clicked()), this, SLOT(EnchAdd()));

}

void AddEnch::setLanCNs()
{
	this->setWindowTitle(_SETCN("添加附魔"));

	ui.btnAddEnch->setText(_SETCN("添加"));
	ui.btnCancel->setText(_SETCN("取消"));
	ui.lbITEM->setText(_SETCN("物品: "));
	ui.lbEnch->setText(_SETCN("附魔"));
	ui.lbLvl->setText(_SETCN("等级"));
	ui.groupBox->setTitle(_SETCN("附魔设定"));

	ui.cbbEnchantments->setItemText(0, _SETCN("保护"));
	ui.cbbEnchantments->setItemText(1, _SETCN("火焰保护"));
	ui.cbbEnchantments->setItemText(2, _SETCN("摔落保护"));
	ui.cbbEnchantments->setItemText(3, _SETCN("爆炸保护"));
	ui.cbbEnchantments->setItemText(4, _SETCN("弹射物保护"));
	ui.cbbEnchantments->setItemText(5, _SETCN("水下呼吸"));
	ui.cbbEnchantments->setItemText(6, _SETCN("水下速掘"));
	ui.cbbEnchantments->setItemText(7, _SETCN("荆棘"));
	ui.cbbEnchantments->setItemText(8, _SETCN("深海探索者"));
	ui.cbbEnchantments->setItemText(9, _SETCN("冰霜行者"));
	ui.cbbEnchantments->setItemText(10, _SETCN("绑定诅咒"));
	ui.cbbEnchantments->setItemText(11, _SETCN("锋利"));
	ui.cbbEnchantments->setItemText(12, _SETCN("亡灵杀手"));
	ui.cbbEnchantments->setItemText(13, _SETCN("节肢杀手"));
	ui.cbbEnchantments->setItemText(14, _SETCN("击退"));
	ui.cbbEnchantments->setItemText(15, _SETCN("火焰附加"));
	ui.cbbEnchantments->setItemText(16, _SETCN("抢夺"));
	ui.cbbEnchantments->setItemText(17, _SETCN("横扫之刃"));
	ui.cbbEnchantments->setItemText(18, _SETCN("效率"));
	ui.cbbEnchantments->setItemText(19, _SETCN("精准采集"));
	ui.cbbEnchantments->setItemText(20, _SETCN("耐久"));
	ui.cbbEnchantments->setItemText(21, _SETCN("时运"));
	ui.cbbEnchantments->setItemText(22, _SETCN("力量"));
	ui.cbbEnchantments->setItemText(23, _SETCN("冲击"));
	ui.cbbEnchantments->setItemText(24, _SETCN("火矢"));
	ui.cbbEnchantments->setItemText(25, _SETCN("无限"));
	ui.cbbEnchantments->setItemText(26, _SETCN("海之眷顾"));
	ui.cbbEnchantments->setItemText(27, _SETCN("饵钓"));
	ui.cbbEnchantments->setItemText(28, _SETCN("忠诚(1.13+)"));
	ui.cbbEnchantments->setItemText(29, _SETCN("穿刺(1.13+)"));
	ui.cbbEnchantments->setItemText(30, _SETCN("激流(1.13+)"));
	ui.cbbEnchantments->setItemText(31, _SETCN("引雷(1.13+)"));
	ui.cbbEnchantments->setItemText(32, _SETCN("经验修补"));
	ui.cbbEnchantments->setItemText(33, _SETCN("消失诅咒"));
	ui.cbbEnchantments->setItemText(34, _SETCN("多重射击(1.14+)"));
	ui.cbbEnchantments->setItemText(35, _SETCN("穿透(1.14+)"));
	ui.cbbEnchantments->setItemText(36, _SETCN("快速装填(1.14+)"));
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

