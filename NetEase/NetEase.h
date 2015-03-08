#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include "ui_NetEase.h"

class NetEase : public QMainWindow
{
	Q_OBJECT

public:
	NetEase(QWidget *parent = 0);
	~NetEase();
	void initScene();
	void initSceneBackground();

private:
	Ui::NetEaseClass ui;
	QGraphicsScene* scene;
	QGraphicsView* view;

};