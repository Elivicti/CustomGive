#pragma once

#include <QDialog>
#include "ui_Attri.h"
#include "NBTstr.h"

class Attri : public QDialog
{
	Q_OBJECT

public:
	Attri(QWidget *parent = Q_NULLPTR);

	static QString SetAttriStr(int UUID);

	void setItemID(QString ID_);
	void setLang(int Lan);

private slots:
	void addAttri();
	void setInfinity();

private:
	Ui::Attri ui;
};

