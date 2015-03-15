#include "MainView.h"
#include <QPolygonF>
#include <QHBoxLayout>

MainView::MainView(QGraphicsScene* _scene, QWidget* parent) :
	scene(_scene),
	QGraphicsView(_scene)
{
	//QHBoxLayout *layout = new QHBoxLayout(this);
	//layout->addWidget(view);
	//this->setLayout(layout);

	//resize(MAINVIEW_WIDTH, MAINVIEW_HEIGHT);
	//scene->setSceneRect(-1 * (MAINVIEW_WIDTH >> 1), -1 * (MAINVIEW_HEIGHT >> 1), MAINVIEW_WIDTH, MAINVIEW_HEIGHT);
	int t = 0xff;
	QBrush grayBrush(QColor(t, t, t));
	QPen grayPen(QColor(t, t, t));
	QGraphicsRectItem* rect = scene->addRect(-1 * (MAINVIEW_WIDTH >> 1), -1 * (MAINVIEW_HEIGHT >> 1), MAINVIEW_WIDTH, MAINVIEW_HEIGHT, grayPen, grayBrush);
	scaling = 0.2;
	scene->update();
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
			QBrush brush_bar(QColor(0xff, 0, 0));
			QPen pen_bar(QColor(0xff, 0, 0));
			QVector<double> transition = clusterItems[j].getTransition();
			double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getTotalRecords() * totalHeigh;
			//double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getCount() * totalHeigh;

			double distancePosY = 3;
			scene->addRect(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20, -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY, 5, currentHeight, pen_bar, brush_bar);
			double currentRelativePos = 0;
			for (int k = 0; k != transition.size()  && i != clusterSets.size()-1; k++)
			{
				QVector<ClusterItem> distanceClusterItems = clusterSets[i + 1].getClusterItems();
				double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getTotalRecords() * totalHeigh;
			//	double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getCount() * totalHeigh;

				if (transition[k] > 0.2)
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

					QBrush brush_trans(QColor(0xff, 0x88, 0));
					QPen pen_trans(QColor(0xff, 0x88, 0));
					//scene->addPolygon(polygon << QPointF(sourcePolygonX, sourcePolygonY) << QPointF(sourcePolygonX, sourcePolygonY + sourcePolygonH) << QPointF(targetPolygonX, targetPolygonY + targetPolygonH) << QPointF(targetPolygonX, targetPolygonY), p, b);
					
					QPoint sourceUp_pos(sourcePolygonX, sourcePolygonY);
					QPoint sourceBottom_pos(sourcePolygonX, sourcePolygonY + sourcePolygonH);
					QPoint midUp_pos((sourcePolygonX + targetPolygonX) / 2, (sourcePolygonY + targetPolygonY) / 2 + sourcePolygonH*(1 - scaling) / 2);
					QPoint midBottom_pos((sourcePolygonX + targetPolygonX) / 2, (sourcePolygonY + targetPolygonY) / 2 + sourcePolygonH - sourcePolygonH*(1 - scaling) / 2);
					QPoint targetUp_pos(targetPolygonX, targetPolygonY);
					QPoint targetBottom_pos(targetPolygonX, targetPolygonY + targetPolygonH);
		

				//	QPoint end_pos(100, 200);
					//drawPath;
					QPainterPath path(sourceUp_pos);

					path.cubicTo(midUp_pos, midUp_pos, targetUp_pos);
					path.lineTo(targetBottom_pos);
					path.cubicTo(midBottom_pos, midBottom_pos, sourceBottom_pos);
					path.lineTo(sourceUp_pos);

					//path.moveTo(10, 100);
					//path.cubicTo(10, 100, 100, 10, 200, 70);
					//path.lineTo(200, 50);
					//path.lineTo(220, 80);
					scene->addPath(path, pen_trans, brush_trans);






					//scene->addLine(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20, -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY + currentHeight / 2, -1 * (MAINVIEW_WIDTH >> 1) + (i + 1)*distanceWidth + 20 + 3, -1 * (MAINVIEW_HEIGHT >> 1) + distancePosY + distanceHeight / 2);
					
				}
				distancePosY += distanceHeight + 5;
			}


			currentPosY += currentHeight+5;
		}

	}






}


void MainView::mousePressEvent(QMouseEvent *event)
{
	qDebug() <<QString("pos:%1,%2").arg(QString::number(event->x()),QString::number(event->y()));


}





