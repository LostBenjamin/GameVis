#include "MyCentralWidget.h"


MyCentralWidget::MyCentralWidget(QWidget* parent)
{
	QGraphicsScene* scene = new QGraphicsScene;
	mainView = new MainView(scene, this);
	infoList = new InfoList;

	layout = new QHBoxLayout;
	layout->addWidget(mainView);
	layout->addWidget(infoList);
	
	setLayout(layout);
}


MyCentralWidget::~MyCentralWidget()
{
}


void MyCentralWidget::paintMainView(ClusterAll* clusterAll)
{
	mainView->paint(clusterAll);
}