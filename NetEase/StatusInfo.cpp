#include "StatusInfo.h"

StatusInfo::StatusInfo(QWidget *parent)
	: QDialog(parent), ui(new Ui::StatusInfo) {
	ui->setupUi(this);
	renderStatus(1); //TODO
}

StatusInfo::~StatusInfo() {
	delete ui;
}

void StatusInfo::renderStatus(int chartType) {
	switch (chartType) {
	case 1:
		drawHistogram(ui->customPlot);
		break;
	default:
		break;
	}

	setWindowTitle("StatusInfo: " + currentStatus);
	currentChartType = chartType;
	ui->customPlot->replot();
}

void StatusInfo::drawHistogram(QCustomPlot *customPlot) {

	QPen pen;
	pen.setWidthF(1.2);
	penColors << QColor(255, 131, 0) << QColor(1, 92, 191) << QColor(150, 222, 0);
	brushColors << QColor(255, 131, 0, 50) << QColor(1, 92, 191, 50) << QColor(150, 222, 0, 70);

	QCPBarsGroup *group = new QCPBarsGroup(customPlot);

	clusters.resize(clusterNum);
	dataSet.resize(clusterNum);

	QVector<double> ticks;
	QVector<QString> labels;

	// set ticks
	ticks << 1 << 2 << 3;
	// attribute name
	attributes << "attr1" << "attr2" << "attr3";
	// add data
	dataSet[0] << 0.86*10.5 << 0.83*5.5 << 0.84*5.5;
	dataSet[1] << 0.08*10.5 << 0.12*5.5 << 0.12*5.5;
	dataSet[2] << 0.06*10.5 << 0.05*5.5 << 0.04*5.5;

	for (int i = 0; i < clusterNum; i++) {
		// create empty bar chart objects
		clusters[i] = new QCPBars(customPlot->xAxis, customPlot->yAxis);
		customPlot->addPlottable(clusters[i]);

		// set names and colors
		clusters[i]->setName(attributes[i]);
		pen.setColor(penColors[i]);
		clusters[i]->setPen(pen);
		clusters[i]->setBrush(brushColors[i]);
		clusters[i]->setWidthType(QCPBars::wtAxisRectRatio);
		clusters[i]->setWidth(1.0 / 7 / 3);

		// stack bars ontop of each other
		group->append(clusters[i]);

		// set labels
		labels << attributes[i];

//		dataSet[i] << 0.86*10.5 << 0.83*5.5 << 0.84*5.5;
		clusters[i]->setData(ticks, dataSet[i]);
	}

	// prepare x axis:
	customPlot->xAxis->setAutoTicks(false);
	customPlot->xAxis->setAutoTickLabels(false);
	customPlot->xAxis->setTickVector(ticks);
	customPlot->xAxis->setTickVectorLabels(labels);
	customPlot->xAxis->setTickLabelRotation(60);
	customPlot->xAxis->setSubTickCount(0);
	customPlot->xAxis->setTickLength(0, 8);
	customPlot->xAxis->grid()->setVisible(true);
	customPlot->xAxis->setRange(0, 4);

	// prepare y axis:
	customPlot->yAxis->setRange(0, 12.1);
	customPlot->yAxis->setPadding(5); // a bit more space to the left border
	customPlot->yAxis->setLabel("StatusInfo");
	customPlot->yAxis->grid()->setSubGridVisible(true);
	QPen gridPen;
	gridPen.setStyle(Qt::SolidLine);
	gridPen.setColor(QColor(0, 0, 0, 25));
	customPlot->yAxis->grid()->setPen(gridPen);
	gridPen.setStyle(Qt::DotLine);
	customPlot->yAxis->grid()->setSubGridPen(gridPen);

	// setup legend
	customPlot->legend->setVisible(true);
	customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignHCenter);
	customPlot->legend->setBrush(QColor(255, 255, 255, 200));
	QPen legendPen;
	legendPen.setColor(QColor(130, 130, 130, 200));
	customPlot->legend->setBorderPen(legendPen);
	QFont legendFont = font();
	legendFont.setPointSize(10);
	customPlot->legend->setFont(legendFont);
	customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}