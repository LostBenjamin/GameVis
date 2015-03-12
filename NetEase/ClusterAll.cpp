#include "ClusterAll.h"


ClusterAll::ClusterAll()
{

}


ClusterAll::~ClusterAll()
{
}

QVector<ClusterSet>& ClusterAll::getClusterSets()
{
	return clusterSets;
}

void ClusterAll::push_back(ClusterSet& c)
{

	clusterSets.push_back(c);
}

ClusterSet * ClusterAll::getLastElement(){
	return &clusterSets.last();
}