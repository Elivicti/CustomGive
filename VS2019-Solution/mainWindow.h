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
	
private slots:
	//�˵�
	void _aboutQt();        //����Qt
	void aboutMC();         //����Minecraft
	void _about();          //����
	void NBTwiki();         //NBT��wikiҳ��
	void IDinfo();          //��ƷID�������Ϣ
	void commandUpgrade();  //����ָ��(һ���ǳ����õ�С���ߣ�����Github)

	void ColorFix();        //�޸���ʽ����

	//��ħ
	void AddEnchant();
	void DelEnchant();

	//���Ա༭��
	void AddAttri();
	void DelAttri();
	
	//display��ǩ
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
	void DisTip();        //������ʽ�������ʾ

	//����NBT��ǩ��ʾ
	void hfAll();
	void hfEnch();
	void hfAttri();
	void hfUnbreak();
	void hfCanDes();
	void hfCanPlace();
	void hfOthers();

	//������
	void setNBT();
	void Generate();

	//��������
	void changeLanUS();
	void changeLanCNs();

private:

	void debug();           //������

	void setTableHeader(QString str);   //���ñ�ͷ�����������ж����ø�ħ��Attribute�ı�ͷ

	int crtRow;             //��ǰ�û�ѡ�еı��ĵڼ���
	int row = 0;            //�����������row�У�
	int amount = 1;         //�洢��Ʒ������Ĭ��Ϊ1


	int HideFlag = NULL;    //�洢NBT HideFlag��ֵ��Ĭ��Ϊ0

	void getDis();          //��ȡDisplay

	//��ħ
	int EnchNum = 0;        //����mainWindow::setEnchNBT()�������жϵ�ǰ��ħ����
	void setEnchNBT(bool ifDel = false);

	//Attribute
	int AttriNum = 0;       //��¼Attribute������
	void setAttriNBT(bool ifDel = false);

	QString ItemID;                //��ƷID
	QString Command = COMDPREF;    //���������ָ��


	QStandardItemModel* model_Ench;   //tableView��model - ��ħ
	QStandardItemModel* model_Attri;  //tableView��model - Attribute

	Ui::mainWindowClass ui;		
};
