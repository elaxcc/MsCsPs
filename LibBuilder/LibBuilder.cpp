#include "stdafx.h"
#include "LibBuilder.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>

LibBuilder::LibBuilder(QWidget *parent)
	: QMainWindow(parent)
	, cnt_(0)
{
	ui.setupUi(this);

	elementList_ = new QTreeWidget;
	elementListTopItem_ = new QTreeWidgetItem(elementList_);
	elementListTopItem_->setText(0, "Top");
	elementListSelectedItem_ = elementListTopItem_;

	elementListAddBut_ = new QPushButton;
	elementListAddBut_->setText("Add");
	elementListAddBut_->setFixedSize(100, 30);
	elementListDeleteBut_ = new QPushButton;
	elementListDeleteBut_->setText("Delete");
	elementListDeleteBut_->setFixedSize(100, 30);

	QObject::connect(elementListAddBut_, SIGNAL(clicked()),
		this, SLOT(slot_elementListAddButClick()));
	QObject::connect(elementListDeleteBut_, SIGNAL(clicked()),
		this, SLOT(slot_elementListDeleteButClick()));
	QObject::connect(elementList_, SIGNAL(itemClicked(QTreeWidgetItem*, int)),
		this, SLOT(slot_elementListSelectItem(QTreeWidgetItem*, int)));

	layoutElementListBut_ = new QHBoxLayout;
	layoutElementListBut_->setSpacing(5);
	layoutElementListBut_->setMargin(5);
	layoutElementListBut_->addWidget(elementListAddBut_);
	layoutElementListBut_->addWidget(elementListDeleteBut_);
	
	layoutElementList_ = new QVBoxLayout;
	layoutElementList_->addLayout(layoutElementListBut_);
	layoutElementList_->addWidget(elementList_);

	centralWgt_ = new QWidget;
	centralWgt_->setLayout(layoutElementList_);
	this->setCentralWidget(centralWgt_);
}

void LibBuilder::slot_elementListAddButClick()
{
	elementListSelectedItem_->setExpanded(true);

	QTreeWidgetItem *item = new QTreeWidgetItem(elementListSelectedItem_);
	item->setText(0, QString::number(cnt_));

	cnt_++;

}

void LibBuilder::slot_elementListDeleteButClick()
{
	if (elementListSelectedItem_ != elementListTopItem_)
	{
		QTreeWidgetItem *parentPtr = elementListSelectedItem_->parent();
		parentPtr->removeChild(elementListSelectedItem_);
		delete elementListSelectedItem_;
		elementListSelectedItem_ = elementListTopItem_;
	}
}

void LibBuilder::slot_elementListSelectItem(QTreeWidgetItem *itemPtr, int colomn)
{
	elementListSelectedItem_ = itemPtr;
}
