#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GDS_Wnd.h"

class GDS_Wnd : public QMainWindow
{
	Q_OBJECT

public:
	GDS_Wnd(QWidget *parent = Q_NULLPTR);

private:
	Ui::GDS_WndClass ui;
};
