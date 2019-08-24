#pragma once

#include <qstring.h>

//语言状态
#define ENGUS 0   //英语（美国）
#define CNSIMP 1  //简体中文

//QT5用settext设置中文乱码，需要用此代码解决
#define SETCN(cnstring) QString::fromLocal8Bit(cnstring)  

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

	static QString AttriStr;          //储存QString类型的Attribute名称
	static QString AttriNBT;          //储存Attribute的NBT
	static QString AttriNameShow;     //用于在表格(TableView)中显示Attribute名称
	static QString AttriSlotShow;     //用于在表格(TableView)中显示Attribute槽位
	static QString AttriOperation;    //储存Attribute的计算方式（加算 or 乘算）
	static QString AttriAmount;       //储存Attribute的数值
	static int AttriSlotIndex;        //Attribute的槽位的索引
	static int AttriNameIndex;        //Attribute的名称的索引
	
};

