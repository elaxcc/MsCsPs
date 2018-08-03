#include "stdafx.h"
#include "GDS_Wnd.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GDS_Wnd w;
	w.show();
	return a.exec();
}
