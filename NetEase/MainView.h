#pragma once
#include "ClusterAll.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include "QDebug"
#include "QMouseEvent"
#include "constant.h"

struct BarFrame
{
	QPoint pos;
	QPoint range;
};
struct TransFrame
{
	QPoint sourcePos;
	QPoint targetPos;
	double height;
};

struct BarInfo
{
	BarFrame barFrame;
	QVector<TransFrame> transFrames;
};


class MainView: public QGraphicsView
{
	Q_OBJECT
public:
	MainView(QGraphicsScene* _scene, QWidget* parent = 0);
	~MainView();
	void paint(ClusterAll* clusterAll);
	void initViewWithData(ClusterAll* clusterAll);


private:
	QGraphicsScene* scene;
	QVector<QVector<BarInfo>> barInfoMatrix;
	
	
	
	
	double scaling;
	int timeSise;
	int clusterSize;




protected:
	void mousePressEvent(QMouseEvent *event);

};

