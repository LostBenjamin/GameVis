#pragma once
#include "ClusterAll.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include "constant.h"
class MainView: public QWidget
{
	//Q_OBJECT
public:
	MainView(QWidget* parent = 0);
	~MainView();
	void paint(ClusterAll* clusterAll);
private:
	QGraphicsScene* scene;
	QGraphicsView* view;
};

