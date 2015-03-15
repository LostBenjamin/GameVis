#include "ClusterItem.h"


ClusterItem::ClusterItem()
{
	_countTrans = 0;
}


ClusterItem::~ClusterItem()
{
}




void ClusterItem::push_back(double d)
{
	_countTrans += d;
	transition.push_back(d);
}

void ClusterItem::pushSource(double sourceComponent)
{

	//if (_source.size()==0)
	//{
	//	_source.push_back(sourceComponent);
	//}
	//else _source.push_back(sourceComponent+_source.last());



	_source.push_back(sourceComponent);

}



QVector<double>& ClusterItem::getTransition()
{
	return transition;
}


double ClusterItem::getCountRecord(){
	return _countRecord;
}
double ClusterItem::getCountTrans(){
	return _countTrans;
}
double ClusterItem::getSourceAtIndex(int id){
	return _source[id];
}
void ClusterItem::setCountRecord(double countRecord){
	normalize();
	_countRecord = countRecord;
}
void ClusterItem::normalize(){

	for (int i = 0; i < transition.count()&&_countTrans!=0; i++)
	{
		transition[i] = transition[i] / _countTrans;
	}
	if (_countTrans!=0)
	{
		_countTrans = 1;
	}
	
}