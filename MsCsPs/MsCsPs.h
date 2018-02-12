#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MsCsPs.h"

class MsCsPs : public QMainWindow
{
	Q_OBJECT

public:
	MsCsPs(QWidget *parent = Q_NULLPTR);

private:
	Ui::MsCsPsClass ui;
};
