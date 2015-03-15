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
	//来源分量注意 要获得第i个到底有多少需要用i-（i-1） 第0个为第0个的值
	QVector<double> _source;

	int _id;
	double _countRecord;
	double _countTrans;
};

