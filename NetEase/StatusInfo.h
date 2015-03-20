#ifndef STATUSINFO_H
#define STATUSINFO_H

#include <QDialog>
#include "ui_StatusInfo.h"
#include "qcustomplot.h"

namespace Ui {
	class StatusInfo;
}

class StatusInfo : public QDialog {
	Q_OBJECT

public:
	explicit StatusInfo(QWidget *parent = 0);
	~StatusInfo();

	void renderStatus(int chartType);
	void drawHistogram(QCustomPlot *customPlot);
	void drawLineChart(QCustomPlot *customPlot);

private:
	void normalize();
	void getData();

	Ui::StatusInfo *ui;
	QString currentStatus;
	int currentChartType;

	QVector<QCPBars *> clusters;
	QVector<QVector<double>> dataSet;
	int clusterNum = 3, attrNum;

	QVector<QColor> penColors;
	QVector<QColor> brushColors;
	QVector<QString> attributes;
};

#endif // STATUSINFO_H
