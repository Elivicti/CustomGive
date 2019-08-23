#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainWindow.h"
#include <qdesktopservices.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <qstandarditemmodel.h>
#include <Windows.h>

#include "AddEnch.h"
#include "NBTstr.h"
#include "SignTranscode.h"


//NBT HideFlag的值，隐藏多个需要把它们的值加起来
#define SELECTAll 63    //隐藏全部
#define ENCHANTMENT 1   //隐藏附魔
#define ATTRIBUTES 2    //隐藏属性（属性修改器）
#define UNBREAKABLE 4   //隐藏“不可破坏”
#define CANDES 8        //隐藏“可以破坏...”
#define CANPLACE 16     //隐藏“可以放置在...”
#define OTHERS 32       //隐藏其他的资料（如药水效果和盾牌的图案信息）

//前缀
#define COMDPREF "/give @p "   //give指令
#define IDPREF "minecraft:"    //物品ID的前缀

#define SETCN(cnstring) QString::fromLocal8Bit(cnstring)  //QT5用settext设置中文乱码，需要用此代码解决


class mainWindow : public QMainWindow
{
	Q_OBJECT

public:
	mainWindow(QWidget *parent = Q_NULLPTR);

	void setEnchNBT(bool isDeled = false);

	void setTableHeader();

	int crtRow;

	
	
private slots:
	void _aboutQt();
	void aboutMC();
	void _about();
	void NBTwiki();
	void IDinfo();
	void commandUpgrade();

	void ColorFix();

	void AddEnchant();
	void DelEnchant();

	void AddLore0();      //黑色
	void AddLore1();      //蓝色
	void AddLore2();      //绿色
	void AddLore3();      //青色
	void AddLore4();      //红色
	void AddLore5();      //品红色
	void AddLore6();      //金色
	void AddLore7();      //浅灰色
	void AddLore8();      //灰色
	void AddLore9();      //蓝紫色
	void AddLore_a();     //浅绿色
	void AddLore_b();     //浅蓝色
	void AddLore_c();     //浅红色
	void AddLore_d();     //粉色
	void AddLore_f();     //白色
	void AddLore_k();     //乱码
	void AddLore_l();     //加粗
	void AddLore_m();     //删除线
	void AddLore_n();     //下划线
	void AddLore_o();     //斜体
	void AddLore_r();     //默认字体颜色（即不附魔不改名时物品名称的样式）
	void DisTip();
	void getDis();

	void hfAll();
	void hfEnch();
	void hfAttri();
	void hfUnbreak();
	void hfCanDes();
	void hfCanPlace();
	void hfOthers();


	void setNBT();
	void Generate();

	void changeLanUS();
	void changeLanCNs();

private:
	void debug();


	int HideFlag = NULL;  //存储NBT HideFlag的值，默认为0
	int amount = 1;       //存储物品数量，默认为1

	QString ItemID;

	QString Command = COMDPREF;

	QStandardItemModel* model_Ench;
	QStandardItemModel* model_Attri;
	Ui::mainWindowClass ui;
	

	int row = 0;            //表格行数（第row行）
	int EnchNum = 0;        //用于mainWindow::setEnchNBT()函数，判断当前附魔数量
	
};
