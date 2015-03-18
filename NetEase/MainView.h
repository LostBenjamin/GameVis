#pragma once
#include "ClusterAll.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include "QDebug"
#include "QMouseEvent"
#include "constant.h"
#include "NEStripeItem.h"
#include "NEClassItem.h"
#include "ColorSet.h"
struct NEItemEvent
{
	int itemId;
	QPointF lastPoint;
	QPoint classItemIdx;
	StripeId stripeItemIdx;


};




class MainView: public QGraphicsView
{
	Q_OBJECT
public:
	MainView(QGraphicsScene* _scene, QWidget* parent = 0);
	~MainView();
	void paint(ClusterAll* clusterAll);
	void initItemWithData(ClusterAll* clusterAll);

	void resize(const QSize &);

private:
	QGraphicsScene* scene;
	QVector<QVector<NEClassItem>> classItems;
	QVector<QVector<QVector<NEStripeItem>>> stripesItems;

	double scaling;
	int timeSise;
	int clusterSize;
	double classItemsWidth;
	double classItemsInterval;

	//QPointF dragItemId;
	//QPoint clickedClassItemId;
	ClusterAll* clusterAll;
	NEItemEvent itemEventInfo;
	QVector<QColor> colorSet;



protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void repaint();
};

