#pragma once
#include "MainView.h"
#include "Model.h"
class Control
{
public:
	Control(Model* _model=0, MainView* _mainView=0);
	~Control();
private:
	Model* model;
	MainView* mainView;
};

