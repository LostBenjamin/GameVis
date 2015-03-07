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

	QColor green(0x00, 0xFF, 0x00);
	TransitionNode* t0=new TransitionNode(NULL, scene, green, 50, -400, -200);
	transitionTree = new TransitionTree(t0, scene);
	QColor blue(0x00, 0x00, 0xFF);
	TransitionNode* t1 = new TransitionNode(t0, scene, blue, 50, -300, -200);
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