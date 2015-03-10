#pragma once
#include <boost/numeric/ublas/matrix.hpp>
#include "ClusterItem.h"
#include "QtCore/QVector"
#include "constant.h"
class ClusterSet
{
public:
	ClusterSet();
	~ClusterSet();
	QVector<ClusterItem>& getClusterItems();
	void push_back(ClusterItem& c);
	void setMatrixElement(int i, int j, double value);
private:
	QVector<ClusterItem> clusterItems;
	boost::numeric::ublas::matrix<double> transitionMatrix;
};

