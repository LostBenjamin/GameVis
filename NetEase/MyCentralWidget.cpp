#include "MyCentralWidget.h"


MyCentralWidget::MyCentralWidget(QWidget* parent)
{
	QGraphicsScene* scene = new QGraphicsScene;
	mainView = new MainView(scene, this);
	infoList = new InfoList;
	toolBar = new ToolBar;

	layout = new QHBoxLayout;
	layout->addWidget(toolBar);
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