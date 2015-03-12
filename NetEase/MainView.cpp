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


	int totalHeigh = MAINVIEW_HEIGHT - 5 * CLUSTER_SIZE;


	for (int i=0; i != clusterSets.size(); i++)
	{
		QVector<ClusterItem> clusterItems = clusterSets[i].getClusterItems();
		double currentPosY =3;

		for (int j = 0; j != clusterItems.size(); j++)
		{
			QBrush b(QColor(0xff, 0, 0));
			QPen p(QColor(0xff, 0, 0));
			QVector<double> transition = clusterItems[j].getTransition();
			double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getTotalRecords() * totalHeigh;



			double distancePosY = 3;
			scene->addRect(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20, -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY, 5, currentHeight, p, b);

			for (int k = 0; k != transition.size()  && i != clusterSets.size()-1; k++)
			{
				QVector<ClusterItem> distanceClusterItems = clusterSets[i + 1].getClusterItems();
				double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getTotalRecords() * totalHeigh;

				if (transition[k] > 0.3)
				{
					
					scene->addLine(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20, -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY + currentHeight / 2, -1 * (MAINVIEW_WIDTH >> 1) + (i + 1)*distanceWidth + 20 + 3, -1 * (MAINVIEW_HEIGHT >> 1) + distancePosY + distanceHeight / 2);
				
				}
				distancePosY += distanceHeight + 5;
			}


			currentPosY += currentHeight+5;



		}



	}
}