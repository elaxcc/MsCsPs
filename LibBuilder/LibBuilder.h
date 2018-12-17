#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LibBuilder.h"

class LibBuilder : public QMainWindow
{
	Q_OBJECT

public:
	LibBuilder(QWidget *parent = Q_NULLPTR);

private:
	Ui::LibBuilderClass ui;
};
