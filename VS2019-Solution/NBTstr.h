#pragma once

#include <qstring.h>

//����״̬
#define ENGUS 0   //Ӣ�������
#define CNSIMP 1  //��������

//QT5��settext�����������룬��Ҫ�ô˴�����
#define SETCN(cnstring) QString::fromLocal8Bit(cnstring)  

class NBTstr
{
private:
	NBTstr();


public:
	

	static QString NBTfull;    //����������NBT

	static QString disNbt;     //��ʾNBT

	static QString EnchStr;    //����QString���͵ĸ�ħ����
	static QString EnchNBT;    //����ָ��ʹ�õ�NBT��ʽ - ��ħ
	static QString EnchShow;   //�����ڱ��(TableView)����ʾ��ħ����  
	static int EnchIndex;      //���渽ħ��enum�еģ�
	static int Enchlvl;        //���渽ħ�ȼ�

	static QString AttriStr;          //����QString���͵�Attribute����
	static QString AttriNBT;          //����Attribute��NBT
	static QString AttriNameShow;     //�����ڱ��(TableView)����ʾAttribute����
	static QString AttriSlotShow;     //�����ڱ��(TableView)����ʾAttribute��λ
	static QString AttriOperation;    //����Attribute�ļ��㷽ʽ������ or ���㣩
	static QString AttriAmount;       //����Attribute����ֵ
	static int AttriSlotIndex;        //Attribute�Ĳ�λ������
	static int AttriNameIndex;        //Attribute�����Ƶ�����
	
};

