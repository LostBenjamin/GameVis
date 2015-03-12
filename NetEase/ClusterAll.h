#pragma once
#include "ClusterSet.h"
class ClusterAll
{
public:
	ClusterAll();
	~ClusterAll();
	QVector<ClusterSet>& getClusterSets();
	void push_back(ClusterSet& c);
	ClusterSet *getLastElement();

private:
	QVector<ClusterSet> clusterSets;

};

