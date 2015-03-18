#pragma once

#include <QGraphicsItem> 

class NEItem :public QGraphicsItem
{
public:
	NEItem();
	~NEItem();
	void setTag(int tag);
	int getTag();
private:
	int itemTag =-1024;

};

