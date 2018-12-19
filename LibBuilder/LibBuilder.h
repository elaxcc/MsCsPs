#pragma once

#include <QtWidgets/QMainWindow>
#include <QTreeWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "ui_LibBuilder.h"

class LibBuilder : public QMainWindow
{
	Q_OBJECT

public:
	LibBuilder(QWidget *parent = Q_NULLPTR);

public slots:
	void slot_elementListAddButClick();
	void slot_elementListDeleteButClick();
	void slot_elementListSelectItem(QTreeWidgetItem *itemPtr, int colomn);

private:
	Ui::LibBuilderClass ui;

	QTreeWidget *elementList_;
	QTreeWidgetItem *elementListTopItem_;
	QTreeWidgetItem *elementListSelectedItem_;
	QPushButton *elementListAddBut_;
	QPushButton *elementListDeleteBut_;

	QVBoxLayout *layoutElementList_;
	QHBoxLayout *layoutElementListBut_;

	QWidget *centralWgt_;

	unsigned int cnt_;
};
