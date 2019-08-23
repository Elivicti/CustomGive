#pragma once

#include <QDialog>
#include <qdesktopservices.h>
#include "ui_SignTranscode.h"

#define AllowColorURL "https://www.mcbbs.net/thread-651063-1-1.html"


class SignTranscode : public QDialog
{
	Q_OBJECT

public:
	SignTranscode(QWidget *parent = Q_NULLPTR);
	~SignTranscode();

private slots:
	void ModLink();

private:
	Ui::SignTranscode ui;
};
