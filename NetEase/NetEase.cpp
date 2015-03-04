#include "NetEase.h"

NetEase::NetEase(QWidget *parent):
	QMainWindow(parent), 
	scene(new QGraphicsScene(this)), 
	view(new QGraphicsView(scene, this))
{
	ui.setupUi(this);
	setCentralWidget(view);
	resize(1200, 800);

	initScene();
}

NetEase::~NetEase()
{

}

void NetEase::initScene()
{
	scene->setSceneRect(-500, -300, 1000, 600);
	QBrush redBrush(Qt::red);
	QPen blackPen(Qt::black);
	QBrush grayBrush(QColor(0xEE, 0xEE, 0xEE));
	QPen grayPen(QColor(0xEE, 0xEE, 0xEE));
	QGraphicsRectItem* rect = scene->addRect(-500, -300, 1000, 600, grayPen, grayBrush);
}