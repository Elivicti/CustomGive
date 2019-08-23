#include "mainWindow.h"
#include "Enchantments.h"

#define SETCN(cnstring) QString::fromLocal8Bit(cnstring)  //QT5用settext设置中文乱码，需要用此代码解决

//语言状态
#define ENGUS 0   //英语（美国）
#define CNSIMP 1  //简体中文
int crtLang = ENGUS;




int presentLan = SUBLANGID(GetSystemDefaultLangID());   //程序当前使用的语言，默认为系统语言

void mainWindow::debug()
{
	this->ui.teItemLore->textCursor().insertText("123");
}


mainWindow::mainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//信息
	connect(ui.actionAboutMinecraft, SIGNAL(triggered()), this, SLOT(aboutMC()));
	connect(ui.actionAboutQt, SIGNAL(triggered()), this, SLOT(_aboutQt()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(_about()));
	connect(ui.actionNBT_Wiki, SIGNAL(triggered()), this, SLOT(NBTwiki()));
	connect(ui.actionEng, SIGNAL(triggered()), this, SLOT(changeLanUS()));
	connect(ui.actionCNs, SIGNAL(triggered()), this, SLOT(changeLanCNs()));
	connect(ui.btnInfo, SIGNAL(clicked()), this, SLOT(IDinfo()));

	//工具
	connect(ui.actionUpgradeCommand, SIGNAL(triggered()), this, SLOT(commandUpgrade()));
	connect(ui.actionSign_Transcoder, SIGNAL(triggered()), this, SLOT(ColorFix()));

	//显示（display）
	connect(ui.btn0, SIGNAL(clicked()), this, SLOT(AddLore0()));
	connect(ui.btn1, SIGNAL(clicked()), this, SLOT(AddLore1()));
	connect(ui.btn2, SIGNAL(clicked()), this, SLOT(AddLore2()));
	connect(ui.btn3, SIGNAL(clicked()), this, SLOT(AddLore3()));
	connect(ui.btn4, SIGNAL(clicked()), this, SLOT(AddLore4()));
	connect(ui.btn5, SIGNAL(clicked()), this, SLOT(AddLore5()));
	connect(ui.btn6, SIGNAL(clicked()), this, SLOT(AddLore6()));
	connect(ui.btn7, SIGNAL(clicked()), this, SLOT(AddLore7()));
	connect(ui.btn8, SIGNAL(clicked()), this, SLOT(AddLore8()));
	connect(ui.btn9, SIGNAL(clicked()), this, SLOT(AddLore9()));
	connect(ui.btn_a, SIGNAL(clicked()), this, SLOT(AddLore_a()));
	connect(ui.btn_b, SIGNAL(clicked()), this, SLOT(AddLore_b()));
	connect(ui.btn_c, SIGNAL(clicked()), this, SLOT(AddLore_c()));
	connect(ui.btn_d, SIGNAL(clicked()), this, SLOT(AddLore_d()));
	connect(ui.btn_f, SIGNAL(clicked()), this, SLOT(AddLore_f()));
	connect(ui.btn_k, SIGNAL(clicked()), this, SLOT(AddLore_k()));
	connect(ui.btn_l, SIGNAL(clicked()), this, SLOT(AddLore_l()));
	connect(ui.btn_m, SIGNAL(clicked()), this, SLOT(AddLore_m()));
	connect(ui.btn_n, SIGNAL(clicked()), this, SLOT(AddLore_n()));
	connect(ui.btn_o, SIGNAL(clicked()), this, SLOT(AddLore_o()));
	connect(ui.btn_r, SIGNAL(clicked()), this, SLOT(AddLore_r()));

	connect(ui.btnDisTip, SIGNAL(clicked()), this, SLOT(DisTip()));

	//附魔
	connect(ui.btnAdd, SIGNAL(clicked()), this, SLOT(AddEnchant()));
	connect(ui.btnDel, SIGNAL(clicked()), this, SLOT(DelEnchant()));

	//隐藏属性
	connect(ui.chbSelectAll, SIGNAL(clicked()), this, SLOT(hfAll()));
	connect(ui.chbEnch, SIGNAL(clicked()), this, SLOT(hfEnch()));
	connect(ui.chbAttri, SIGNAL(clicked()), this, SLOT(hfAttri()));
	connect(ui.chbUnbreak_hf, SIGNAL(clicked()), this, SLOT(hfUnbreak()));
	connect(ui.chbCanDes, SIGNAL(clicked()), this, SLOT(hfCanDes()));
	connect(ui.chbCanPlace, SIGNAL(clicked()), this, SLOT(hfCanPlace()));
	connect(ui.chbOthers, SIGNAL(clicked()), this, SLOT(hfOthers()));


	connect(ui.btnGenerate, SIGNAL(clicked()), this, SLOT(Generate()));


	this->model_Ench = new QStandardItemModel();
	model_Ench->setHorizontalHeaderItem(0, new QStandardItem("Enchantments"));
	model_Ench->setHorizontalHeaderItem(1, new QStandardItem("Level"));
	ui.tbvEnch->setModel(model_Ench);
	ui.tbvEnch->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	setTableHeader();
	
	NBTstr::EnchNBT = "";

	WORD PriLan = PRIMARYLANGID(GetSystemDefaultLangID());

	if (PriLan == LANG_CHINESE)                               //系统是中文 
	{
		if (presentLan == SUBLANG_CHINESE_SIMPLIFIED)             //系统是简体中文 
		{
			mainWindow::changeLanCNs();
		}
	}
}

void mainWindow::setTableHeader()
{
	if (row >= 8)  //保持表头的格式（不出现横向的滚动）
	{
		ui.tbvEnch->setColumnWidth(0, 270);
		ui.tbvEnch->setColumnWidth(1, 118);
	}
	else
	{
		ui.tbvEnch->setColumnWidth(0, 270);
		ui.tbvEnch->setColumnWidth(1, 139);
	}
}

//显示（display）
void mainWindow::AddLore0()//黑色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn0->text());
}
void mainWindow::AddLore1()//蓝色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn1->text());
}
void mainWindow::AddLore2()//绿色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn2->text());
}
void mainWindow::AddLore3()//青色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn3->text());
}
void mainWindow::AddLore4()//红色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn4->text());
}
void mainWindow::AddLore5()//品红色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn5->text());
}
void mainWindow::AddLore6()//金色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn6->text());
}
void mainWindow::AddLore7()//浅灰色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn7->text());
}
void mainWindow::AddLore8()//灰色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn8->text());
}
void mainWindow::AddLore9()//蓝紫色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn9->text());
}
void mainWindow::AddLore_a()//浅绿色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_a->text());
}
void mainWindow::AddLore_b()//浅蓝色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_b->text());
}
void mainWindow::AddLore_c()//浅红色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_c->text());
}
void mainWindow::AddLore_d()//粉色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_d->text());
}
void mainWindow::AddLore_f()//白色
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_f->text());
}
void mainWindow::AddLore_k()//乱码
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_k->text());
}
void mainWindow::AddLore_l()//加粗
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_l->text());
}
void mainWindow::AddLore_m()//删除线
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_m->text());
}
void mainWindow::AddLore_n()//下划线
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_n->text());
}
void mainWindow::AddLore_o()//斜体
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_o->text());
}
void mainWindow::AddLore_r()//默认字体颜色（即不附魔不改名时物品名称的样式）
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_r->text());
}

void mainWindow::DisTip()
{
	if (crtLang == CNSIMP)
	{
		QMessageBox::information(
			this,
			" ",
			SETCN("格式符'§'无法在聊天框和命令方块中输入\n\n请使用“工具”->“牌子转译”"),
			SETCN("确定")
		);
	}
	else if (crtLang == ENGUS)
	{
		QMessageBox::information(
			this,
			" ",
			QString::fromLocal8Bit("Format character '§' cannot be entered into chat box or command block \n\n Please use \"Tools\"->\"Sign Transcoder\"")
			);
	}

}

void mainWindow::getDis()
{
	QString disName = ui.leItemName->text();
	QString disLore = ui.teItemLore->toPlainText();
	disLore.replace("\n", "\",\"");
	
	if (disName != "" && disLore == "")
	{
		NBTstr::disNbt = ",display:{Name:\"" + disName + "\"}";
	} 
	else if (disLore != "" && disName == "")
	{
		NBTstr::disNbt = ",display:{Lore: [\"" + disLore + "\"]}";
	}
	else if (disLore == "" && disName == "")
	{
		NBTstr::disNbt = "";
	}
	else
	{
		NBTstr::disNbt = ",display:{Name:\"" + disName + "\"" + ",Lore: [\"" + disLore + "\"]}";
	}
	
}


//附魔
void mainWindow::AddEnchant()
{
	ItemID = ui.leItemID->text();

	AddEnch a;
	a.setId(ItemID);
	if (crtLang == CNSIMP)
	{
		a.setLanCNs();
	}
	else// if (crtLang == ENGUS)
	{
		a.setLanUS();
	}

	int ext = a.exec();

	if (ext == 0) //判断“添加附魔”窗口的返回状态，为0（点“X”或Cancel）则跳出
	{
		return;
	}

	
	NBTstr::EnchStr = setEnch(NBTstr::EnchIndex);
	setEnchNBT();
	
	this->model_Ench->setItem(row, 0, new QStandardItem(NBTstr::EnchShow));
	this->model_Ench->setItem(row, 1, new QStandardItem(QString::number(NBTstr::Enchlvl)));

	row++;
	setTableHeader();

}

void mainWindow::DelEnchant()
{
	if (row > 0)
	{
		crtRow = ui.tbvEnch->currentIndex().row();
		this->model_Ench->removeRow(crtRow);
		setEnchNBT(true);

		row--;
	}
	setTableHeader();
}

void mainWindow::setEnchNBT(bool isDeled)  //拼接附魔NBT字符串（末尾的“]”不在此函数内）
{
	if (isDeled == false)//添加附魔
	{
		if (EnchNum > 0)
		{
			NBTstr::EnchNBT += ",";
		}
		NBTstr::EnchNBT += "{id:" + NBTstr::EnchStr + ",lvl:" + QString::number(NBTstr::Enchlvl) + "}";
		EnchNum++;
	}
	else if (isDeled == true)//删除附魔
	{
		if (EnchNum > 1)
		{
			int j = 0, n = 0; //用于计数“ ','的数量”
			if (crtRow == 0)  //当选中行为第一行
			{
				for (int i = 0; i < NBTstr::EnchNBT.size(); i++)
				{
					if (NBTstr::EnchNBT[i] == ',')
					{
						n++;   //计数，从字符串首到下一个附魔NBT的逗号数
					}
					NBTstr::EnchNBT[i] = '\0';
					if (n == 2) //离下一个附魔NBT的逗号有两个时跳出循环
					{
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < NBTstr::EnchNBT.size(); i++)
				{
					if (NBTstr::EnchNBT[i] == ',')
					{
						j++; //计数，从字符串首开始的第几个','
						if (j == (2 * (crtRow + 1) - 2))  //当在目标逗号位置
						{
							for (int k = i; k < NBTstr::EnchNBT.size(); k++)
							{
								if (NBTstr::EnchNBT[k] == ',')
								{
									n++; //计数，到下一个附魔NBT的逗号数
									if (n > 2)  //离下一个附魔NBT的逗号有两个时跳出循环
									{          ///注: {id:id, lvl : lvl}, { id:id,lvl : lvl }, { id:id,lvl : lvl } *附魔格式
										break;
									}
								}
								NBTstr::EnchNBT[k] = '\0';
							}
							break; //跳出循环
						}
					}
				}
			}
		}
		else if (EnchNum == 1)
		{
			NBTstr::EnchNBT = "";
		}
		EnchNum--; //附魔数量 - 1
	}
}


//隐藏属性
void mainWindow::hfAll()
{
	if (ui.chbSelectAll->isChecked() == true)
	{
		HideFlag = SELECTAll;
		ui.chbEnch->setChecked(true);
		ui.chbAttri->setChecked(true);
		ui.chbUnbreak_hf->setChecked(true);
		ui.chbCanDes->setChecked(true);
		ui.chbCanPlace->setChecked(true);
		ui.chbOthers->setChecked(true);
	}
	else
	{
		HideFlag = NULL;
		ui.chbEnch->setChecked(false);
		ui.chbAttri->setChecked(false);
		ui.chbUnbreak_hf->setChecked(false);
		ui.chbCanDes->setChecked(false);
		ui.chbCanPlace->setChecked(false);
		ui.chbOthers->setChecked(false);
	}
}
void mainWindow::hfEnch()
{
	if (ui.chbEnch->isChecked() == true)
	{
		HideFlag += ENCHANTMENT;
	}
	else
	{
		HideFlag -= ENCHANTMENT;
	}

	if (HideFlag == SELECTAll)
	{
		ui.chbSelectAll->setChecked(true);
	}
	else
	{
		ui.chbSelectAll->setChecked(false);
	}
}
void mainWindow::hfAttri()
{
	if (ui.chbAttri->isChecked() == true)
	{
		HideFlag += ATTRIBUTES;
	}
	else
	{
		HideFlag -= ATTRIBUTES;
	}

	if (HideFlag == SELECTAll)
	{
		ui.chbSelectAll->setChecked(true);
	}
	else
	{
		ui.chbSelectAll->setChecked(false);
	}
}
void mainWindow::hfUnbreak()
{
	if (ui.chbUnbreak_hf->isChecked() == true)
	{
		HideFlag += UNBREAKABLE;
	}
	else
	{
		HideFlag -= UNBREAKABLE;
	}

	if (HideFlag == SELECTAll)
	{
		ui.chbSelectAll->setChecked(true);
	}
	else
	{
		ui.chbSelectAll->setChecked(false);
	}
}
void mainWindow::hfCanDes()
{
	if (ui.chbCanDes->isChecked() == true)
	{
		HideFlag += CANDES;
	}
	else
	{
		HideFlag -= CANDES;
	}

	if (HideFlag == SELECTAll)
	{
		ui.chbSelectAll->setChecked(true);
	}
	else
	{
		ui.chbSelectAll->setChecked(false);
	}
}
void mainWindow::hfCanPlace()
{
	if (ui.chbCanPlace->isChecked() == true)
	{
		HideFlag += CANPLACE;
	}
	else
	{
		HideFlag -= CANPLACE;
	}

	if (HideFlag == SELECTAll)
	{
		ui.chbSelectAll->setChecked(true);
	}
	else
	{
		ui.chbSelectAll->setChecked(false);
	}
}
void mainWindow::hfOthers()
{
	if (ui.chbOthers->isChecked() == true)
	{
		HideFlag += OTHERS;
	}
	else
	{
		HideFlag -= OTHERS;
	}

	if (HideFlag == SELECTAll)
	{
		ui.chbSelectAll->setChecked(true);
	}
	else
	{
		ui.chbSelectAll->setChecked(false);
	}
}


//最终输出
void mainWindow::setNBT()
{
	if (ui.rbtn13plus->isChecked() == true && NBTstr::EnchNBT != "")
	{
		for (int i = 0; i < NBTstr::EnchNBT.size(); i++)
		{
			if (NBTstr::EnchNBT[i] == "{")
			{
				break;
			}
			NBTstr::EnchNBT[i] = '\0';
		}
		EnchSwitchForm(&NBTstr::EnchNBT);
		NBTstr::EnchNBT = "Enchantments:[" + NBTstr::EnchNBT + "]";
	}
	else if(ui.rbtn13plus->isChecked() == false && NBTstr::EnchNBT != "")
	{
		for (int i = 0; i < NBTstr::EnchNBT.size(); i++)
		{
			if (NBTstr::EnchNBT[i] == "{")
			{
				break;
			}
			NBTstr::EnchNBT[i] = '\0';
		}
		EnchSwitchForm(&NBTstr::EnchNBT, true);
		NBTstr::EnchNBT = "ench:[" + NBTstr::EnchNBT + "]";
	}

	QString isUnbreakable = "";
	if (ui.chbUnbreakable->isChecked() == true)
	{
		isUnbreakable = ",Unbreakable:1b";
	}
	else
	{
		isUnbreakable = "";
	}

	QString HideFlagStr = "";
	if (HideFlag != NULL)
	{
		HideFlagStr = ",HideFlag:" + QString::number(HideFlag);
	}

	getDis();

	NBTstr::NBTfull = "{" + NBTstr::EnchNBT + isUnbreakable + HideFlagStr + NBTstr::disNbt + "}";
	NBTstr::NBTfull.replace("{,", "{");
}

void mainWindow::Generate()
{

	Command = COMDPREF;

	if (ui.leItemID->text() == "") //判断是否已输入物品ID
	{
		ui.tbCommand->setText("Error..\nPlease input item ID..");
		return;
	}

	amount = ui.spbAmount->value();
	ItemID = ui.leItemID->text();

	setNBT();
	if (NBTstr::NBTfull == "{}")
	{
		NBTstr::NBTfull = "";
	}

	if (ui.rbtn13plus->isChecked() == true)
	{
		Command += IDPREF + ItemID + NBTstr::NBTfull + " " + QString::number(amount);
	}
	else 
	{
		Command += IDPREF + ItemID + " " + QString::number(amount) + " 0" + " " + NBTstr::NBTfull;
	}
	
	ui.tbCommand->setText(Command);
}



void mainWindow::ColorFix()
{
	SignTranscode a;
	a.exec();
}

void mainWindow::commandUpgrade()
{
	QDesktopServices::openUrl(QUrl(QLatin1String("https://spu.spgoding.com/")));
}

void mainWindow::IDinfo()
{
	QDesktopServices::openUrl(QUrl(QLatin1String("https://minecraft-ids.grahamedgecombe.com/")));
}
void mainWindow::NBTwiki()
{
	QDesktopServices::openUrl(QUrl(QLatin1String("https://minecraft.gamepedia.com/Tutorials/Command_NBT_tags")));
}
void mainWindow::aboutMC()
{
	QDesktopServices::openUrl(QUrl(QLatin1String("https://en.wikipedia.org/wiki/Minecraft")));
}
void mainWindow::_aboutQt()
{
	QMessageBox::aboutQt(this, "About Qt");
}
void mainWindow::_about()
{
	QMessageBox::information(this, "About..", "Desgined & Written BY \n ELivicti_ \n Based on VisualStdio 2019 & Qt5.12.3");
}

void mainWindow::changeLanUS() //修改界面语言 - 英文
{
	crtLang = ENGUS;
	this->setWindowTitle("CustomGIVE");
	this->model_Ench->setHorizontalHeaderItem(0, new QStandardItem("Enchantments"));
	this->model_Ench->setHorizontalHeaderItem(1, new QStandardItem("Level"));
	ui.tbvEnch->setModel(model_Ench);
	setTableHeader();

	ui.lbItemID->setText("ItemID");
	ui.lbAmount->setText("Item Amount");
	ui.lbPS_Others->setText("*Potion effects & shield pattern info");
	ui.lbItemName->setText("Item Name");
	ui.lbLore->setText("Lore");
	ui.lbColor->setText("Color");
	ui.lbFormat->setText("Format");
	ui.lbDefault->setText("Default");

	ui.gbVersion->setTitle("Version");
	ui.gbEnch->setTitle("Enchantments");
	ui.gbDisplay->setTitle("Display");
	ui.gbHideFlag->setTitle("HideFlag");
	ui.gbAttri->setTitle("Attributes Editor");

	ui.chbSelectAll->setText("SelectAll");
	ui.chbEnch->setText("Enchantments");
	ui.chbAttri->setText("Attributes");
	ui.chbUnbreak_hf->setFont(QFont("Agency FB", 9));
	ui.chbUnbreak_hf->setText("Unbreakable");
	ui.chbCanDes->setText("CanDestory");
	ui.chbCanPlace->setText("CanPlaceOn");
	ui.chbOthers->setText("Others");
	ui.chbUnbreakable->setText("Unbreakable");

	ui.btnInfo->setText("ID Info");
	ui.btnAdd->setText("Add");
	ui.btnDel->setText("Delete");
	ui.btnGenerate->setText("Generate");
	ui.btnCopy->setText("Copy");

	ui.menuLanguage->setTitle("Language");
	ui.menuOtherNBT->setTitle("OtherNBT");
	ui.menuMoreInfo->setTitle("MoreInfo");
	ui.menuTools->setTitle("Tools");
	ui.actionNBT_Wiki->setText("NBT Wiki");
	ui.actionAboutQt->setText("About Qt");
	ui.actionAboutMinecraft->setText("About Minecraft");
	ui.actionAbout->setText("About..");
	ui.actionSign_Transcoder->setText("Sign Transcoder");
	ui.actionUpgradeCommand->setText("Upgrade Your Command!");

	ui.actionComing_Soon->setText("Coming soon...");
}
void mainWindow::changeLanCNs() //修改界面语言 - 中文
{
	crtLang = CNSIMP;
	this->setWindowTitle(SETCN("自定义GIVE指令"));
	this->model_Ench->setHorizontalHeaderItem(0, new QStandardItem(SETCN("附魔")));
	this->model_Ench->setHorizontalHeaderItem(1, new QStandardItem(SETCN("等级")));
	ui.tbvEnch->setModel(model_Ench);
	setTableHeader();

	ui.lbItemID->setText(SETCN("物品ID"));
	ui.lbAmount->setText(SETCN("物品数量"));
	ui.lbPS_Others->setText(SETCN("           *如药水效果和盾牌图案信息"));
	ui.lbItemName->setText(SETCN("物品名称"));
	ui.lbLore->setText(SETCN("描述"));
	ui.lbColor->setText(SETCN("字体颜色"));
	ui.lbFormat->setText(SETCN("字体格式"));
	ui.lbDefault->setText(SETCN("默认"));

	ui.gbVersion->setTitle(SETCN("指令版本"));
	ui.gbEnch->setTitle(SETCN("附魔"));
	ui.gbDisplay->setTitle(SETCN("显示"));
	ui.gbHideFlag->setTitle(SETCN("隐藏属性"));
	ui.gbAttri->setTitle(SETCN("附加属性编辑器"));

	ui.chbSelectAll->setText(SETCN("全选"));
	ui.chbEnch->setText(SETCN("附魔"));
	ui.chbAttri->setText(SETCN("附加属性"));
	ui.chbUnbreak_hf->setFont(QFont("Agency FB", 8));
	ui.chbUnbreak_hf->setText(SETCN("\"无法破坏\"标签"));
	ui.chbCanDes->setText(SETCN("可以破坏.."));
	ui.chbCanPlace->setText(SETCN("可以放置在.."));
	ui.chbOthers->setText(SETCN("其它"));
	ui.chbUnbreakable->setText(SETCN("无法破坏"));

	ui.btnInfo->setText(SETCN("ID信息"));
	ui.btnAdd->setText(SETCN("添加"));
	ui.btnDel->setText(SETCN("删除"));
	ui.btnGenerate->setText(SETCN("生成指令"));
	ui.btnCopy->setText(SETCN("复制"));

	ui.menuLanguage->setTitle(SETCN("语言"));
	ui.menuOtherNBT->setTitle(SETCN("其它NBT"));
	ui.menuMoreInfo->setTitle(SETCN("更多.."));
	ui.menuTools->setTitle(SETCN("工具"));
	ui.actionNBT_Wiki->setText(SETCN("维基百科 - NBT"));
	ui.actionAboutQt->setText(SETCN("关于Qt"));
	ui.actionAboutMinecraft->setText(SETCN("关于Minecraft"));
	ui.actionAbout->setText(SETCN("关于.."));
	ui.actionSign_Transcoder->setText(SETCN("牌子转译"));
	ui.actionUpgradeCommand->setText(SETCN("升级你的指令！"));

	ui.actionComing_Soon->setText(SETCN("即将到来(咕咕咕).."));
}