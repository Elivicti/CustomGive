#include "mainWindow.h"
#include "Enchantments.h"

#define SETCN(cnstring) QString::fromLocal8Bit(cnstring)  //QT5��settext�����������룬��Ҫ�ô˴�����

//����״̬
#define ENGUS 0   //Ӣ�������
#define CNSIMP 1  //��������
int crtLang = ENGUS;




int presentLan = SUBLANGID(GetSystemDefaultLangID());   //����ǰʹ�õ����ԣ�Ĭ��Ϊϵͳ����

void mainWindow::debug()
{
	this->ui.teItemLore->textCursor().insertText("123");
}


mainWindow::mainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//��Ϣ
	connect(ui.actionAboutMinecraft, SIGNAL(triggered()), this, SLOT(aboutMC()));
	connect(ui.actionAboutQt, SIGNAL(triggered()), this, SLOT(_aboutQt()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(_about()));
	connect(ui.actionNBT_Wiki, SIGNAL(triggered()), this, SLOT(NBTwiki()));
	connect(ui.actionEng, SIGNAL(triggered()), this, SLOT(changeLanUS()));
	connect(ui.actionCNs, SIGNAL(triggered()), this, SLOT(changeLanCNs()));
	connect(ui.btnInfo, SIGNAL(clicked()), this, SLOT(IDinfo()));

	//����
	connect(ui.actionUpgradeCommand, SIGNAL(triggered()), this, SLOT(commandUpgrade()));
	connect(ui.actionSign_Transcoder, SIGNAL(triggered()), this, SLOT(ColorFix()));

	//��ʾ��display��
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

	//��ħ
	connect(ui.btnAdd, SIGNAL(clicked()), this, SLOT(AddEnchant()));
	connect(ui.btnDel, SIGNAL(clicked()), this, SLOT(DelEnchant()));

	//��������
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

	if (PriLan == LANG_CHINESE)                               //ϵͳ������ 
	{
		if (presentLan == SUBLANG_CHINESE_SIMPLIFIED)             //ϵͳ�Ǽ������� 
		{
			mainWindow::changeLanCNs();
		}
	}
}

void mainWindow::setTableHeader()
{
	if (row >= 8)  //���ֱ�ͷ�ĸ�ʽ�������ֺ���Ĺ�����
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

//��ʾ��display��
void mainWindow::AddLore0()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn0->text());
}
void mainWindow::AddLore1()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn1->text());
}
void mainWindow::AddLore2()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn2->text());
}
void mainWindow::AddLore3()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn3->text());
}
void mainWindow::AddLore4()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn4->text());
}
void mainWindow::AddLore5()//Ʒ��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn5->text());
}
void mainWindow::AddLore6()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn6->text());
}
void mainWindow::AddLore7()//ǳ��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn7->text());
}
void mainWindow::AddLore8()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn8->text());
}
void mainWindow::AddLore9()//����ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn9->text());
}
void mainWindow::AddLore_a()//ǳ��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_a->text());
}
void mainWindow::AddLore_b()//ǳ��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_b->text());
}
void mainWindow::AddLore_c()//ǳ��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_c->text());
}
void mainWindow::AddLore_d()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_d->text());
}
void mainWindow::AddLore_f()//��ɫ
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_f->text());
}
void mainWindow::AddLore_k()//����
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_k->text());
}
void mainWindow::AddLore_l()//�Ӵ�
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_l->text());
}
void mainWindow::AddLore_m()//ɾ����
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_m->text());
}
void mainWindow::AddLore_n()//�»���
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_n->text());
}
void mainWindow::AddLore_o()//б��
{
	this->ui.teItemLore->textCursor().insertText(ui.btn_o->text());
}
void mainWindow::AddLore_r()//Ĭ��������ɫ��������ħ������ʱ��Ʒ���Ƶ���ʽ��
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
			SETCN("��ʽ��'��'�޷��������������������\n\n��ʹ�á����ߡ�->������ת�롱"),
			SETCN("ȷ��")
		);
	}
	else if (crtLang == ENGUS)
	{
		QMessageBox::information(
			this,
			" ",
			QString::fromLocal8Bit("Format character '��' cannot be entered into chat box or command block \n\n Please use \"Tools\"->\"Sign Transcoder\"")
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


//��ħ
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

	if (ext == 0) //�жϡ���Ӹ�ħ�����ڵķ���״̬��Ϊ0���㡰X����Cancel��������
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

void mainWindow::setEnchNBT(bool isDeled)  //ƴ�Ӹ�ħNBT�ַ�����ĩβ�ġ�]�����ڴ˺����ڣ�
{
	if (isDeled == false)//��Ӹ�ħ
	{
		if (EnchNum > 0)
		{
			NBTstr::EnchNBT += ",";
		}
		NBTstr::EnchNBT += "{id:" + NBTstr::EnchStr + ",lvl:" + QString::number(NBTstr::Enchlvl) + "}";
		EnchNum++;
	}
	else if (isDeled == true)//ɾ����ħ
	{
		if (EnchNum > 1)
		{
			int j = 0, n = 0; //���ڼ����� ','��������
			if (crtRow == 0)  //��ѡ����Ϊ��һ��
			{
				for (int i = 0; i < NBTstr::EnchNBT.size(); i++)
				{
					if (NBTstr::EnchNBT[i] == ',')
					{
						n++;   //���������ַ����׵���һ����ħNBT�Ķ�����
					}
					NBTstr::EnchNBT[i] = '\0';
					if (n == 2) //����һ����ħNBT�Ķ���������ʱ����ѭ��
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
						j++; //���������ַ����׿�ʼ�ĵڼ���','
						if (j == (2 * (crtRow + 1) - 2))  //����Ŀ�궺��λ��
						{
							for (int k = i; k < NBTstr::EnchNBT.size(); k++)
							{
								if (NBTstr::EnchNBT[k] == ',')
								{
									n++; //����������һ����ħNBT�Ķ�����
									if (n > 2)  //����һ����ħNBT�Ķ���������ʱ����ѭ��
									{          ///ע: {id:id, lvl : lvl}, { id:id,lvl : lvl }, { id:id,lvl : lvl } *��ħ��ʽ
										break;
									}
								}
								NBTstr::EnchNBT[k] = '\0';
							}
							break; //����ѭ��
						}
					}
				}
			}
		}
		else if (EnchNum == 1)
		{
			NBTstr::EnchNBT = "";
		}
		EnchNum--; //��ħ���� - 1
	}
}


//��������
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


//�������
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

	if (ui.leItemID->text() == "") //�ж��Ƿ���������ƷID
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

void mainWindow::changeLanUS() //�޸Ľ������� - Ӣ��
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
void mainWindow::changeLanCNs() //�޸Ľ������� - ����
{
	crtLang = CNSIMP;
	this->setWindowTitle(SETCN("�Զ���GIVEָ��"));
	this->model_Ench->setHorizontalHeaderItem(0, new QStandardItem(SETCN("��ħ")));
	this->model_Ench->setHorizontalHeaderItem(1, new QStandardItem(SETCN("�ȼ�")));
	ui.tbvEnch->setModel(model_Ench);
	setTableHeader();

	ui.lbItemID->setText(SETCN("��ƷID"));
	ui.lbAmount->setText(SETCN("��Ʒ����"));
	ui.lbPS_Others->setText(SETCN("           *��ҩˮЧ���Ͷ���ͼ����Ϣ"));
	ui.lbItemName->setText(SETCN("��Ʒ����"));
	ui.lbLore->setText(SETCN("����"));
	ui.lbColor->setText(SETCN("������ɫ"));
	ui.lbFormat->setText(SETCN("�����ʽ"));
	ui.lbDefault->setText(SETCN("Ĭ��"));

	ui.gbVersion->setTitle(SETCN("ָ��汾"));
	ui.gbEnch->setTitle(SETCN("��ħ"));
	ui.gbDisplay->setTitle(SETCN("��ʾ"));
	ui.gbHideFlag->setTitle(SETCN("��������"));
	ui.gbAttri->setTitle(SETCN("�������Ա༭��"));

	ui.chbSelectAll->setText(SETCN("ȫѡ"));
	ui.chbEnch->setText(SETCN("��ħ"));
	ui.chbAttri->setText(SETCN("��������"));
	ui.chbUnbreak_hf->setFont(QFont("Agency FB", 8));
	ui.chbUnbreak_hf->setText(SETCN("\"�޷��ƻ�\"��ǩ"));
	ui.chbCanDes->setText(SETCN("�����ƻ�.."));
	ui.chbCanPlace->setText(SETCN("���Է�����.."));
	ui.chbOthers->setText(SETCN("����"));
	ui.chbUnbreakable->setText(SETCN("�޷��ƻ�"));

	ui.btnInfo->setText(SETCN("ID��Ϣ"));
	ui.btnAdd->setText(SETCN("���"));
	ui.btnDel->setText(SETCN("ɾ��"));
	ui.btnGenerate->setText(SETCN("����ָ��"));
	ui.btnCopy->setText(SETCN("����"));

	ui.menuLanguage->setTitle(SETCN("����"));
	ui.menuOtherNBT->setTitle(SETCN("����NBT"));
	ui.menuMoreInfo->setTitle(SETCN("����.."));
	ui.menuTools->setTitle(SETCN("����"));
	ui.actionNBT_Wiki->setText(SETCN("ά���ٿ� - NBT"));
	ui.actionAboutQt->setText(SETCN("����Qt"));
	ui.actionAboutMinecraft->setText(SETCN("����Minecraft"));
	ui.actionAbout->setText(SETCN("����.."));
	ui.actionSign_Transcoder->setText(SETCN("����ת��"));
	ui.actionUpgradeCommand->setText(SETCN("�������ָ�"));

	ui.actionComing_Soon->setText(SETCN("��������(������).."));
}