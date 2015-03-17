#include "MyCentralWidget.h"


MyCentralWidget::MyCentralWidget(QWidget* parent)
{
	QGraphicsScene* scene = new QGraphicsScene;
	mainView = new MainView(scene, this);
	infoList = new InfoList;
	toolBar = new ToolBar;
	setMouseTracking(true);
	bool a = hasMouseTracking();
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
	mainView->initItemWithData(clusterAll);
	mainView->paint(clusterAll);
}