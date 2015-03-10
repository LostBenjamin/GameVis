#pragma once
#include <QtCore/QVector>
class ClusterItem
{
public:
	ClusterItem();
	~ClusterItem();
	void push_back(double d);
	QVector<double>& getTransition();
private:
	QVector<double> transition;
};

