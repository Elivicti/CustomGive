#pragma once

#include <qstring.h>


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


};

