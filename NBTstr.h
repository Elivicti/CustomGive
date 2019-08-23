#pragma once

#include <qstring.h>


class NBTstr
{
private:
	NBTstr();


public:

	static QString NBTfull;    //储存完整的NBT

	static QString disNbt;     //显示NBT

	static QString EnchStr;    //储存QString类型的附魔名称
	static QString EnchNBT;    //储存指令使用的NBT格式 - 附魔
	static QString EnchShow;   //用于在表格(TableView)中显示附魔名称  
	static int EnchIndex;      //储存附魔（enum中的）
	static int Enchlvl;        //储存附魔等级


};

