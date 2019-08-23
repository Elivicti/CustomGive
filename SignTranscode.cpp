#include "SignTranscode.h"

SignTranscode::SignTranscode(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnLink, SIGNAL(clicked()), this, SLOT(ModLink()));

	ui.teInput->setDisabled(true);
	ui.tbOutput->setDisabled(true);
	ui.btnTranscode->setDisabled(true);

	ui.teInput->setText("This tool is currently unfinished.\nUse \"AllowColor\" Mod instead.");
	ui.tbOutput->setText("This tool is currently unfinished.\nUse \"AllowColor\" Mod instead.");
}

SignTranscode::~SignTranscode()
{
}

void SignTranscode::ModLink()
{
	QDesktopServices::openUrl(QUrl(QLatin1String(AllowColorURL)));
}