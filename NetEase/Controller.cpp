#include "Controller.h"


Controller::Controller(Model* _model, NetEase* _netEase) :
	model(_model),
	netEase(_netEase)
{
	model->loadTestData();
}


Controller::~Controller()
{
}
