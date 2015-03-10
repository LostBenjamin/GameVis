#pragma once
#include "MainView.h"
#include "Model.h"
#include "NetEase.h"
class Controller
{
public:
	Controller (Model* _model = 0, NetEase* _netEase = 0);
	~Controller();
private:
	Model *model;
	NetEase *netEase;
};

