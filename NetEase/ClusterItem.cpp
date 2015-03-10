#include "ClusterItem.h"


ClusterItem::ClusterItem()
{
}


ClusterItem::~ClusterItem()
{
}

void ClusterItem::push_back(double d)
{
	transition.push_back(d);
}

QVector<double>& ClusterItem::getTransition()
{
	return transition;
}