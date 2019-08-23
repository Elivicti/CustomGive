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


//NBT HideFlag��ֵ�����ض����Ҫ�����ǵ�ֵ������
#define SELECTAll 63    //����ȫ��
#define ENCHANTMENT 1   //���ظ�ħ
#define ATTRIBUTES 2    //�������ԣ������޸�����
#define UNBREAKABLE 4   //���ء������ƻ���
#define CANDES 8        //���ء������ƻ�...��
#define CANPLACE 16     //���ء����Է�����...��
#define OTHERS 32       //�������������ϣ���ҩˮЧ���Ͷ��Ƶ�ͼ����Ϣ��

//ǰ׺
#define COMDPREF "/give @p "   //giveָ��
#define IDPREF "minecraft:"    //��ƷID��ǰ׺

#define SETCN(cnstring) QString::fromLocal8Bit(cnstring)  //QT5��settext�����������룬��Ҫ�ô˴�����


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

	void AddLore0();      //��ɫ
	void AddLore1();      //��ɫ
	void AddLore2();      //��ɫ
	void AddLore3();      //��ɫ
	void AddLore4();      //��ɫ
	void AddLore5();      //Ʒ��ɫ
	void AddLore6();      //��ɫ
	void AddLore7();      //ǳ��ɫ
	void AddLore8();      //��ɫ
	void AddLore9();      //����ɫ
	void AddLore_a();     //ǳ��ɫ
	void AddLore_b();     //ǳ��ɫ
	void AddLore_c();     //ǳ��ɫ
	void AddLore_d();     //��ɫ
	void AddLore_f();     //��ɫ
	void AddLore_k();     //����
	void AddLore_l();     //�Ӵ�
	void AddLore_m();     //ɾ����
	void AddLore_n();     //�»���
	void AddLore_o();     //б��
	void AddLore_r();     //Ĭ��������ɫ��������ħ������ʱ��Ʒ���Ƶ���ʽ��
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


	int HideFlag = NULL;  //�洢NBT HideFlag��ֵ��Ĭ��Ϊ0
	int amount = 1;       //�洢��Ʒ������Ĭ��Ϊ1

	QString ItemID;

	QString Command = COMDPREF;

	QStandardItemModel* model_Ench;
	QStandardItemModel* model_Attri;
	Ui::mainWindowClass ui;
	

	int row = 0;            //�����������row�У�
	int EnchNum = 0;        //����mainWindow::setEnchNBT()�������жϵ�ǰ��ħ����
	
};
