/********************************************************************************
** Form generated from reading UI file 'MsCsPs.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSCSPS_H
#define UI_MSCSPS_H

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

class Ui_MsCsPsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MsCsPsClass)
    {
        if (MsCsPsClass->objectName().isEmpty())
            MsCsPsClass->setObjectName(QStringLiteral("MsCsPsClass"));
        MsCsPsClass->resize(600, 400);
        menuBar = new QMenuBar(MsCsPsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MsCsPsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MsCsPsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MsCsPsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MsCsPsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MsCsPsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MsCsPsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MsCsPsClass->setStatusBar(statusBar);

        retranslateUi(MsCsPsClass);

        QMetaObject::connectSlotsByName(MsCsPsClass);
    } // setupUi

    void retranslateUi(QMainWindow *MsCsPsClass)
    {
        MsCsPsClass->setWindowTitle(QApplication::translate("MsCsPsClass", "MsCsPs", 0));
    } // retranslateUi

};

namespace Ui {
    class MsCsPsClass: public Ui_MsCsPsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSCSPS_H
