#pragma once

#include <QDialog>
#include "ui_AddEnch.h"
#include "NBTstr.h"

class AddEnch : public QDialog
{
	Q_OBJECT

public:
	AddEnch(QWidget *parent = Q_NULLPTR);

	//����ItemID����ʾ
	void setId(QString _ID)
	{
		ui.lbItmID->setText(_ID);
	}

	//��������
	void setLanCNs();
	void setLanUS();


private slots:
	void EnchAdd(); //��Ӹ�ħ

private:
	Ui::AddEnch ui;
};
