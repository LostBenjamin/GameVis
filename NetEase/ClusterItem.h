#pragma once
#include <QtCore/QVector>
class ClusterItem
{
public:
	ClusterItem();
	~ClusterItem();
	void push_back(double d);
	void pushSource(double sourceComponent);
	QVector<double>& getTransition();
	double getCountRecord();
	double getCountTrans();
	double getSourceAtIndex(int id);
	void setCountRecord(double countRecord);
	void normalize();
private:
	QVector<double> transition;
	//来源分量
	QVector<double> _source;

	int _id;
	double _countRecord;
	double _countTrans;
};

