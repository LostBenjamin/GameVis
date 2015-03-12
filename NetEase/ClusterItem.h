#pragma once
#include <QtCore/QVector>
class ClusterItem
{
public:
	ClusterItem();
	~ClusterItem();
	void push_back(double d);
	QVector<double>& getTransition();
	double getCountRecord();
	void setCountRecord(double countRecord);
	void normalize();
private:
	QVector<double> transition;
	int _id;
	double _countRecord;
	double _totalRecord;
};

