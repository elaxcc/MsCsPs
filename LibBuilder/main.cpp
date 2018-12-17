#include "stdafx.h"
#include "LibBuilder.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LibBuilder w;
	w.show();
	return a.exec();
}
