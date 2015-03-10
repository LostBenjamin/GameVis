#include "MainView.h"


MainView::MainView(QWidget* parent) :
	scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene, this))
{
	resize(MAINVIEW_WIDTH, MAINVIEW_HEIGHT);
	scene->setSceneRect(-1 * (MAINVIEW_WIDTH >> 1), -1 * (MAINVIEW_HEIGHT >> 1), MAINVIEW_WIDTH, MAINVIEW_HEIGHT);
	int t = 0xff;
	QBrush grayBrush(QColor(t, t, t));
	QPen grayPen(QColor(t, t, t));
	QGraphicsRectItem* rect = scene->addRect(-1 * (MAINVIEW_WIDTH >> 1), -1 * (MAINVIEW_HEIGHT >> 1), MAINVIEW_WIDTH, MAINVIEW_HEIGHT, grayPen, grayBrush);
}


MainView::~MainView()
{
}

void MainView::paint(ClusterAll* clusterAll)
{
	QVector<ClusterSet> clusterSets = clusterAll->getClusterSets();
	int distanceWidth = MAINVIEW_WIDTH / TIME_SIZE;
	int distanceHeight = MAINVIEW_HEIGHT / CLUSTER_SIZE;
	for (int i=0; i != clusterSets.size(); i++)
	{
		QVector<ClusterItem> clusterItems = clusterSets[i].getClusterItems();
		for (int j = 0; j != clusterItems.size(); j++)
		{
			QBrush b(QColor(0xff, 0, 0));
			QPen p(QColor(0xff, 0, 0));
			scene->addRect(-1 * (MAINVIEW_WIDTH >> 1)+i*distanceWidth+20, -1 * (MAINVIEW_HEIGHT >> 1)+j*distanceHeight, 5, 15, p, b);
			QVector<double> transition = clusterItems[j].getTransition();
			for (int k = 0; k != transition.size(); k++)
			{
				if (transition[k] > 0.000000001)
					scene->addLine(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20+3, -1 * (MAINVIEW_HEIGHT >> 1) + j*distanceHeight + distanceHeight / 2, -1 * (MAINVIEW_WIDTH >> 1) + (i + 1)*distanceWidth + 20+3, -1 * (MAINVIEW_HEIGHT >> 1) + k*distanceHeight + distanceHeight / 2);
			}
		}
	}
}