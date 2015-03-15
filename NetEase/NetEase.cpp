#include "NetEase.h"

NetEase::NetEase(QWidget *parent) :
	QMainWindow(parent),
	model(0)
{
	//ui.setupUi(this);
	//resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//QDesktopWidget* desktop = QApplication::desktop();
	//move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	myCentralWidget = new MyCentralWidget(this);
	statusBar = new StatusBar();
	setCentralWidget(myCentralWidget);
	setStatusBar(statusBar);
}

NetEase::~NetEase()
{
	delete myCentralWidget;
}

void NetEase::setModel(Model *_model)
{
	model = _model;
}

void NetEase::paintMainView(void)
{
	myCentralWidget->paintMainView(model->getClusterAll());
}