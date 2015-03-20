/********************************************************************************
** Form generated from reading UI file 'StatusInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSINFO_H
#define UI_STATUSINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_StatusInfo
{
public:
    QCustomPlot *customPlot;

    void setupUi(QDialog *StatusInfo)
    {
        if (StatusInfo->objectName().isEmpty())
            StatusInfo->setObjectName(QStringLiteral("StatusInfo"));
        StatusInfo->resize(800, 600);
        customPlot = new QCustomPlot(StatusInfo);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(20, 20, 751, 551));

        retranslateUi(StatusInfo);

        QMetaObject::connectSlotsByName(StatusInfo);
    } // setupUi

    void retranslateUi(QDialog *StatusInfo)
    {
        StatusInfo->setWindowTitle(QApplication::translate("StatusInfo", "StatusInfo", 0));
    } // retranslateUi

};

namespace Ui {
    class StatusInfo: public Ui_StatusInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSINFO_H
