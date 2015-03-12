#include "ClusterSet.h"


ClusterSet::ClusterSet()  
//transitionMatrix(CLUSTER_SIZE, CLUSTER_SIZE)
{
	_totalRecords = 0;


}


ClusterSet::~ClusterSet()
{
}

QVector<ClusterItem>& ClusterSet::getClusterItems()
{
	return clusterItems;
}

void ClusterSet::push_back(ClusterItem& c)
{
	_totalRecords += c.getCountRecord();
	clusterItems.push_back(c);
}

void ClusterSet::setMatrixElement(int i, int j, double value)
{
//	transitionMatrix(i, j) = value;
}
int ClusterSet::getCount()
{
	return clusterItems.count();
}

ClusterItem * ClusterSet::itemsAtIndex(int i){
	return &clusterItems[i];
}
double ClusterSet::getTotalRecords(){
	return _totalRecords;
}
