#pragma once

#include <QDialog>
#include "ui_AddEnch.h"
#include "NBTstr.h"

class AddEnch : public QDialog
{
	Q_OBJECT

public:
	AddEnch(QWidget *parent = Q_NULLPTR);

	//设置ItemID的显示
	void setId(QString _ID)
	{
		ui.lbItmID->setText(_ID);
	}

	//设置语言
	void setLanCNs();
	void setLanUS();


private slots:
	void EnchAdd(); //添加附魔

private:
	Ui::AddEnch ui;
};
