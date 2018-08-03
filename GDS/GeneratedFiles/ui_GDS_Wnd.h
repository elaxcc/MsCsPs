/********************************************************************************
** Form generated from reading UI file 'GDS_Wnd.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GDS_WND_H
#define UI_GDS_WND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GDS_WndClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GDS_WndClass)
    {
        if (GDS_WndClass->objectName().isEmpty())
            GDS_WndClass->setObjectName(QStringLiteral("GDS_WndClass"));
        GDS_WndClass->resize(600, 400);
        menuBar = new QMenuBar(GDS_WndClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GDS_WndClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GDS_WndClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GDS_WndClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GDS_WndClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GDS_WndClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GDS_WndClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GDS_WndClass->setStatusBar(statusBar);

        retranslateUi(GDS_WndClass);

        QMetaObject::connectSlotsByName(GDS_WndClass);
    } // setupUi

    void retranslateUi(QMainWindow *GDS_WndClass)
    {
        GDS_WndClass->setWindowTitle(QApplication::translate("GDS_WndClass", "GDS_Wnd", 0));
    } // retranslateUi

};

namespace Ui {
    class GDS_WndClass: public Ui_GDS_WndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GDS_WND_H
