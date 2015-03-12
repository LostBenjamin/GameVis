/********************************************************************************
** Form generated from reading UI file 'NetEase.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETEASE_H
#define UI_NETEASE_H

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

class Ui_NetEaseClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NetEaseClass)
    {
        if (NetEaseClass->objectName().isEmpty())
            NetEaseClass->setObjectName(QStringLiteral("NetEaseClass"));
        NetEaseClass->resize(600, 400);
        menuBar = new QMenuBar(NetEaseClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        NetEaseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NetEaseClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NetEaseClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NetEaseClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NetEaseClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NetEaseClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NetEaseClass->setStatusBar(statusBar);

        retranslateUi(NetEaseClass);

        QMetaObject::connectSlotsByName(NetEaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *NetEaseClass)
    {
        NetEaseClass->setWindowTitle(QApplication::translate("NetEaseClass", "NetEase", 0));
    } // retranslateUi

};

namespace Ui {
    class NetEaseClass: public Ui_NetEaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETEASE_H
