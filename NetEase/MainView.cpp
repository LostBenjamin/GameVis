#include "MainView.h"
#include <QPolygonF>
#include <QHBoxLayout>

MainView::MainView(QGraphicsScene* _scene, QWidget* parent) :
	scene(_scene),
	QGraphicsView(_scene)
{

	scaling = 0.2;
	timeSise = 30;
	clusterSize = 20;




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


	for (int i = 0; i != clusterSets.size(); i++)
	{
		QVector<ClusterItem> clusterItems = clusterSets[i].getClusterItems();
		
		for (int j = 0; j != clusterItems.size(); j++)
		{
			QBrush brush_bar(QColor(0xff, 0, 0));
			QPen pen_bar(QColor(0xff, 0, 0));
			QVector<double> transition = clusterItems[j].getTransition();
			BarInfo barInfo = barInfoMatrix[i][j];
			scene->addRect(barInfo.barFrame.pos.x(), barInfo.barFrame.pos.y(), barInfo.barFrame.range.x(), barInfo.barFrame.range.y(), pen_bar, brush_bar);
			for (int k = 0; k != transition.size() && i != clusterSets.size() - 1; k++)
			{
				QVector<ClusterItem> distanceClusterItems = clusterSets[i + 1].getClusterItems();
				if (transition[k] > 0.2)
				{
					double sourcePolygonH = barInfo.transFrames[k].height;
					double sourcePolygonX = barInfo.transFrames[k].sourcePos.x();
					double sourcePolygonY = barInfo.transFrames[k].sourcePos.y();
					double targetPolygonX = barInfo.transFrames[k].targetPos.x();
					double targetPolygonY = barInfo.transFrames[k].targetPos.y();
					double targetPolygonH = barInfo.transFrames[k].height;
					if (targetPolygonH != sourcePolygonH)
					{
						continue;
					}

					QBrush brush_trans(QColor(0xff, 0x88, 0));
					QPen pen_trans(QColor(0xff, 0x88, 0));

					QPoint sourceUp_pos(sourcePolygonX, sourcePolygonY);
					QPoint sourceBottom_pos(sourcePolygonX, sourcePolygonY + sourcePolygonH);
					QPoint midUp_pos((sourcePolygonX + targetPolygonX) / 2, (sourcePolygonY + targetPolygonY) / 2 + sourcePolygonH*(1 - scaling) / 2);
					QPoint midBottom_pos((sourcePolygonX + targetPolygonX) / 2, (sourcePolygonY + targetPolygonY) / 2 + sourcePolygonH - sourcePolygonH*(1 - scaling) / 2);
					QPoint targetUp_pos(targetPolygonX, targetPolygonY);
					QPoint targetBottom_pos(targetPolygonX, targetPolygonY + targetPolygonH);

					QPainterPath path(sourceUp_pos);

					path.cubicTo(midUp_pos, midUp_pos, targetUp_pos);
					path.lineTo(targetBottom_pos);
					path.cubicTo(midBottom_pos, midBottom_pos, sourceBottom_pos);
					path.lineTo(sourceUp_pos);

					scene->addPath(path, pen_trans, brush_trans);
				}

			}

		}

	}






}





void MainView::initViewWithData(ClusterAll* clusterAll)
{
	QVector<ClusterSet> clusterSets = clusterAll->getClusterSets();
	
	int distanceWidth = MAINVIEW_WIDTH / timeSise;
	int totalHeigh = MAINVIEW_HEIGHT - 5 * clusterSize;


	for (int i = 0; i != clusterSets.size(); i++)
	{
		QVector<ClusterItem> clusterItems = clusterSets[i].getClusterItems();
		double currentPosY = 3;
		QVector<BarInfo> barsInfo;
		for (int j = 0; j != clusterItems.size(); j++)
		{
			
			QVector<double> transition = clusterItems[j].getTransition();
			double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getTotalRecords() * totalHeigh;
			//double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getCount() * totalHeigh;

			double distancePosY = 3;
			BarInfo barInfo;
			barInfo.barFrame.pos = QPoint(-1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20, -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY);
			barInfo.barFrame.range = QPoint(5, currentHeight);
			
			int tcount = 0;
			double currentRelativePos = 0;
			for (int k = 0; k != transition.size() && i != clusterSets.size() - 1; k++)
			{
				if (i == 2 && j == 9)
				{
					i=2;
				}
				if (transition[k]>0.2)
				{
					tcount++;
				}
				if (tcount > 1)
				{
					tcount = tcount;
				}

				QVector<ClusterItem> distanceClusterItems = clusterSets[i + 1].getClusterItems();
				double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getTotalRecords() * totalHeigh;
				//	double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getCount() * totalHeigh;
					double sourcePolygonH = transition[k] * currentHeight;
					double sourcePolygonX = -1 * (MAINVIEW_WIDTH >> 1) + i*distanceWidth + 20 + 5;
					double sourcePolygonY = -1 * (MAINVIEW_HEIGHT >> 1) + currentPosY + currentRelativePos;
					currentRelativePos += sourcePolygonH;
					double targetRelativePos = 0;
					for (int t = 0; t < j; t++){
						if (distanceClusterItems[k].getSourceAtIndex(t) != 0.0f)
							targetRelativePos += distanceClusterItems[k].getSourceAtIndex(t) / distanceClusterItems[k].getCountRecord()*distanceHeight;
					}
					//if (j==0)
					//{
					//	targetRelativePos = 0;
					//} 
					//else
					//{
					//	targetRelativePos = distanceClusterItems[k].getSourceAtIndex(j-1) / distanceClusterItems[k].getCountRecord()*distanceHeight;
					//}
					//
					double targetPolygonX = -1 * (MAINVIEW_WIDTH >> 1) + (i + 1)*distanceWidth + 20;
					double targetPolygonY = -1 * (MAINVIEW_HEIGHT >> 1) + distancePosY + targetRelativePos;
					//	double targetPolygonH = transition[k] * clusterItems[j].getCountRecord / clusterSets[i + 1].getCount() * totalHeigh;
					double targetPolygonH = distanceClusterItems[k].getSourceAtIndex(j) / distanceClusterItems[k].getCountRecord() * distanceHeight;

					double targetPolygonW = 0;
					if (sourcePolygonH+targetPolygonY>distancePosY+distanceHeight)
					{
						targetPolygonW = 0;
					}

					QPoint sourceUp_pos(sourcePolygonX, sourcePolygonY);
					QPoint targetUp_pos(targetPolygonX, targetPolygonY);
					TransFrame transframe;
					transframe.sourcePos = sourceUp_pos;
					transframe.targetPos = targetUp_pos;
					transframe.height = sourcePolygonH;
					barInfo.transFrames.push_back(transframe);

				distancePosY += distanceHeight + 5;
			}
			barsInfo.push_back(barInfo);
			currentPosY += currentHeight + 5;
		}
		barInfoMatrix.push_back(barsInfo);
	}






}




















void MainView::mousePressEvent(QMouseEvent *event)
{
	qDebug() <<QString("pos:%1,%2").arg(QString::number(event->x()),QString::number(event->y()));


}





