#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainWindow.h"
#include <qdesktopservices.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <qstandarditemmodel.h>
#include <Windows.h>

#include "AddEnch.h"
#include "Attri.h"
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
	
private slots:
	//菜单
	void _aboutQt();        //关于Qt
	void aboutMC();         //关于Minecraft
	void _about();          //关于
	void NBTwiki();         //NBT的wiki页面
	void IDinfo();          //物品ID的相关信息
	void commandUpgrade();  //升级指令(一个非常好用的小工具，来自Github)

	void ColorFix();        //修复样式代码

	//附魔
	void AddEnchant();
	void DelEnchant();

	//属性编辑器
	void AddAttri();
	void DelAttri();
	
	//display标签
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
	void DisTip();        //关于样式代码的提示

	//隐藏NBT标签显示
	void hfAll();
	void hfEnch();
	void hfAttri();
	void hfUnbreak();
	void hfCanDes();
	void hfCanPlace();
	void hfOthers();

	//总生成
	void setNBT();
	void Generate();

	//设置语言
	void changeLanUS();
	void changeLanCNs();

private:

	void debug();           //调试用

	void setTableHeader(QString str);   //设置表头，参数用于判断设置附魔或Attribute的表头

	int crtRow;             //当前用户选中的表格的第几行
	int row = 0;            //表格行数（第row行）
	int amount = 1;         //存储物品数量，默认为1


	int HideFlag = NULL;    //存储NBT HideFlag的值，默认为0

	void getDis();          //获取Display

	//附魔
	int EnchNum = 0;        //用于mainWindow::setEnchNBT()函数，判断当前附魔数量
	void setEnchNBT(bool ifDel = false);

	//Attribute
	int AttriNum = 0;       //记录Attribute的数量
	void setAttriNBT(bool ifDel = false);

	QString ItemID;                //物品ID
	QString Command = COMDPREF;    //最终输出的指令


	QStandardItemModel* model_Ench;   //tableView的model - 附魔
	QStandardItemModel* model_Attri;  //tableView的model - Attribute

	Ui::mainWindowClass ui;		
};
