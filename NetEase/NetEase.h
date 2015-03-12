#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include "ui_NetEase.h"
#include "constant.h"
#include "MainView.h"
#include "Model.h"

class NetEase : public QMainWindow
{
	//Q_OBJECT
public:
	NetEase(QWidget *parent = 0);
	~NetEase();
	void setModel(Model *_model);
	void paintMainView(void);
private:
	Ui::NetEaseClass ui;
	Model *model;
	MainView *mainView;
};