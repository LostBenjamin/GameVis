#include "ClusterSet.h"


ClusterSet::ClusterSet() : 
	transitionMatrix(CLUSTER_SIZE, CLUSTER_SIZE)
{
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
	clusterItems.push_back(c);
}

void ClusterSet::setMatrixElement(int i, int j, double value)
{
	transitionMatrix(i, j) = value;
}