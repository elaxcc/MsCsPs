#include "stdafx.h"

#include "MsCsPs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MsCsPs w;
	w.show();

	return a.exec();
}
