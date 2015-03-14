#pragma once
#include "QtWidgets/QWidget"
#include "QtWidgets/QHBoxLayout"
#include "MainView.h"
#include "InfoList.h"
#include "ToolBar.h"
class MyCentralWidget :public QWidget
{
public:
	MyCentralWidget(QWidget* parent=0);
	~MyCentralWidget();
	void paintMainView(ClusterAll* clusterAll);
private:
	MainView* mainView;
	InfoList* infoList;
	ToolBar* toolBar;
	QHBoxLayout* layout;
};

