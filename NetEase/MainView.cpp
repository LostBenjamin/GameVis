#include "MainView.h"
#include <QPolygonF>
#include <QHBoxLayout>

MainView::MainView(QWidget* parent) :
	scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene, this))
{
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(view);
	this->setLayout(layout);

	//resize(MAINVIEW_WIDTH, MAINVIEW_HEIGHT);
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
			//double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getTotalRecords() * totalHeigh;
			double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getCount() * totalHeigh;



			double distancePosY = 3;
			scene->addRect(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20, -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY, 5, currentHeight, p, b);
			double currentRelativePos = 0;
			for (int k = 0; k != transition.size()  && i != clusterSets.size()-1; k++)
			{
				QVector<ClusterItem> distanceClusterItems = clusterSets[i + 1].getClusterItems();
			//	double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getTotalRecords() * totalHeigh;
				double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getCount() * totalHeigh;

				if (transition[k] > 0.4)
				{
					QPolygonF polygon;
	


					double sourcePolygonH = transition[k] * currentHeight;
					double sourcePolygonX = -1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20+5;
					double sourcePolygonY = -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY + currentRelativePos;
					currentRelativePos += sourcePolygonH;



					double targetRelativePos = 0;
					for (int t = 0; t < k; t++){
						if (distanceClusterItems[k].getSourceAtIndex(t)!=0.0f)
						targetRelativePos += distanceClusterItems[k].getSourceAtIndex(t) / distanceClusterItems[k].getCountRecord()*distanceHeight;
					}

					double targetPolygonX = -1 * (MAINVIEW_WIDTH >> 1) + (i + 1)*distanceWidth + 20 ;
					double targetPolygonY = -1 * (MAINVIEW_HEIGHT >> 1) + distancePosY + targetRelativePos;
					//	double targetPolygonH = transition[k] * clusterItems[j].getCountRecord / clusterSets[i + 1].getCount() * totalHeigh;
					double targetPolygonH = distanceClusterItems[k].getSourceAtIndex(j) / distanceClusterItems[k].getCountRecord() * distanceHeight;
					if (targetPolygonH!=sourcePolygonH)
					{
						continue;
					}
					double targetPolygonW = 0;
					QBrush b(QColor(0xff, 0xff, 0));
					QPen p(QColor(0xff, 0xff, 0));
					scene->addPolygon(polygon << QPointF(sourcePolygonX, sourcePolygonY) << QPointF(sourcePolygonX, sourcePolygonY + sourcePolygonH) << QPointF(targetPolygonX, targetPolygonY + targetPolygonH) << QPointF(targetPolygonX, targetPolygonY), p, b);

					scene->addLine(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20, -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY + currentHeight / 2, -1 * (MAINVIEW_WIDTH >> 1) + (i + 1)*distanceWidth + 20 + 3, -1 * (MAINVIEW_HEIGHT >> 1) + distancePosY + distanceHeight / 2);
					
				}
				distancePosY += distanceHeight + 5;
			}


			currentPosY += currentHeight+5;



		}



	}
}