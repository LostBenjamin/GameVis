#include "ClusterItem.h"


ClusterItem::ClusterItem()
{
	_totalRecord = 0;
}


ClusterItem::~ClusterItem()
{
}




void ClusterItem::push_back(double d)
{
	_totalRecord += d;
	transition.push_back(d);
}

QVector<double>& ClusterItem::getTransition()
{
	return transition;
}


double ClusterItem::getCountRecord(){
	return _countRecord;
}
void ClusterItem::setCountRecord(double countRecord){
	normalize();
	_countRecord = countRecord;
}
void ClusterItem::normalize(){

	for (int i = 0; i < transition.count()&&_totalRecord!=0; i++)
	{
		transition[i] = transition[i] / _totalRecord;
	}
	if (_totalRecord!=0)
	{
		_totalRecord = 1;
	}
	
}