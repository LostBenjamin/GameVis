#include "MainView.h"
#include <QPolygonF>
#include <QHBoxLayout>
#include "QPropertyAnimation"
#include "QPushButton"
MainView::MainView(QGraphicsScene* _scene, QWidget* parent) :
	scene(_scene),
	QGraphicsView(_scene)
{
	scaling = 0.2;
	timeSise = 30;
	clusterSize = 20;
	//setMouseTracking(true);
	bool a=hasMouseTracking();

	clickedClassItemId = QPoint(-1, -1);
	//QHBoxLayout *layout = new QHBoxLayout(this);
	//layout->addWidget(view);
	//this->setLayout(layout);
	//resize(MAINVIEW_WIDTH, MAINVIEW_HEIGHT);
	//scene->setSceneRect(-1 * (MAINVIEW_WIDTH >> 1), -1 * (MAINVIEW_HEIGHT >> 1), MAINVIEW_WIDTH, MAINVIEW_HEIGHT);
	int t = 0xff;
	QBrush grayBrush(QColor(t, t, t));
	QPen grayPen(QColor(t, t, t));
	//QGraphicsRectItem* rect = scene->addRect(-1 * (MAINVIEW_WIDTH >> 1), -1 * (MAINVIEW_HEIGHT >> 1), MAINVIEW_WIDTH, MAINVIEW_HEIGHT, grayPen, grayBrush);
	QGraphicsRectItem* rect = scene->addRect(0, 0, MAINVIEW_WIDTH, MAINVIEW_HEIGHT, grayPen, grayBrush);
	scaling = 0.2;
	scene->update();
	setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
}


MainView::~MainView()
{
}
//void MainView::resize(const QSize &)
//{
//	update();
//}
void MainView::repaint(){
	




}




void MainView::paint(ClusterAll* clusterAll_)
{
	
	QVector<ClusterSet> clusterSets = clusterAll_->getClusterSets();

	for (int i = 0; i != clusterSets.size(); i++)
	{
		QVector<ClusterItem> clusterItems = clusterSets[i].getClusterItems();
		
		for (int j = 0; j != clusterItems.size(); j++)
		{
			QBrush brush_bar(QColor(0xff, 0, 0));
			QPen pen_bar(QColor(0xff, 0, 0));
			QVector<double> transition = clusterItems[j].getTransition();
			NEClassItem * barInfo = &classItems[i][j];

			scene->addItem(&classItems[i][j]);//barInfo.getClassFrame().topLeft()
			barInfo->setPos(barInfo->getClassFrame().x(), barInfo->getClassFrame().y());
			for (int k = 0; k < stripesItems[i][j].size();k++)
			{

				NEStripeItem* stripesItem = &stripesItems[i][j][k];
				if (!stripesItem->getStripeFrame().isVisable)
				{
					continue;
				}
				stripesItem->setPos(stripesItem->getItemFrame().topLeft());
				if (stripesItem->getItemFrame().topLeft().y() < 2)
				{
					k = k;
				}
				scene->addItem(stripesItem);

			}
		}

	}






}





void MainView::initItemWithData(ClusterAll* clusterAll)
{
	QVector<ClusterSet> clusterSets = clusterAll->getClusterSets();
	
	int distanceWidth = MAINVIEW_WIDTH / timeSise;
	int totalHeigh = MAINVIEW_HEIGHT - 5 * clusterSize;

	//int viewportX = -1 * (MAINVIEW_WIDTH >> 1);
	//int viewportY = -1 * (MAINVIEW_HEIGHT >> 1);
	int viewportX = 0;
	int viewportY = 0;


	for (int i = 0; i != clusterSets.size(); i++)
	{
		QVector<ClusterItem> clusterItems = clusterSets[i].getClusterItems();
		double currentPosY = 3;
		QVector<NEClassItem> classItemsForOneRow;
		QVector<QVector<NEStripeItem>> stripesItemsForOneRow;
		
		for (int j = 0; j != clusterItems.size(); j++)
		{
			
			QVector<double> transition = clusterItems[j].getTransition();
			double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getTotalRecords() * totalHeigh;
			//double currentHeight = clusterItems[j].getCountRecord() / clusterSets[i].getCount() * totalHeigh;

			
			QRectF classFrame(viewportX + i*distanceWidth + 20, viewportY + currentPosY, 5, currentHeight);
			
			NEClassItem classItem(classFrame,QPoint(i,j));
			classItemsForOneRow.push_back(classItem);

			QVector<NEStripeItem> stripesItems;
			int tcount = 0;
			double currentRelativePos = 0;
			double distancePosY = 3;

			for (int k = 0; k != transition.size() && i != clusterSets.size() - 1; k++)
			{


				QVector<ClusterItem> distanceClusterItems = clusterSets[i + 1].getClusterItems();
				double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getTotalRecords() * totalHeigh;
				//	double distanceHeight = distanceClusterItems[k].getCountRecord() / clusterSets[i + 1].getCount() * totalHeigh;
				double sourcePolygonH = transition[k] * currentHeight;
				double sourcePolygonX = viewportX + i*distanceWidth + 20 + 5;
				double sourcePolygonY = viewportY + currentPosY + currentRelativePos;
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
					double targetPolygonX = viewportX + (i + 1)*distanceWidth + 20;
					double targetPolygonY = viewportY + distancePosY + targetRelativePos;
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
					transframe.isVisable = false;
					if (transition[k] > 0.2)
					{
						transframe.isVisable = true;
					}

					NEStripeItem stripesItem(transframe, scaling);
					stripesItem.setStripeId(i, j, k);
					stripesItems.push_back(stripesItem);
					distancePosY += distanceHeight + 5;
			}
			
			stripesItemsForOneRow.push_back(stripesItems);
			currentPosY += currentHeight + 5;
		}
		classItems.push_back(classItemsForOneRow);
		stripesItems.push_back(stripesItemsForOneRow);
	}






}




















void MainView::mousePressEvent(QMouseEvent *event)
{
	qDebug() <<QString("pos:%1,%2").arg(QString::number(event->x()),QString::number(event->y()));
	QPoint clickPos = event->pos();
	QTransform transform;
	//type_info info= typeid( scene->itemAt(clickPos, transform));
	NEClassItem* cItem = (NEClassItem*)scene->itemAt(clickPos, transform);
	NEStripeItem* sitem = (NEStripeItem*)scene->itemAt(clickPos, transform);
	if (cItem==nullptr)
	{
		return;
	}

	clickedClassItemId = cItem->getItemId();

}



void MainView::mouseMoveEvent(QMouseEvent *event)
{
	if (clickedClassItemId == QPoint(-1, -1))
	{
		return;
	}
	classItems[clickedClassItemId.x()][clickedClassItemId.y()].changePos(event->pos());

	QPoint clickPos = clickedClassItemId;
	QTransform transform;
	NEClassItem* item = &classItems[clickedClassItemId.x()][clickedClassItemId.y()];
	item->setPos(event->pos());

	//repaint();
	
}


void MainView::mouseReleaseEvent(QMouseEvent *event)
{
	
	clickedClassItemId = QPoint(-1, -1);
}