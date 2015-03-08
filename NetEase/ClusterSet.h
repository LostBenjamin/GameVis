#pragma once
#include "ClusterItem.h"
#include "QtCore/QVector"
class ClusterSet
{
public:
	ClusterSet();
	~ClusterSet();
private:
	QVector<ClusterItem> clusterItem;
};

