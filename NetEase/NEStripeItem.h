#pragma once
#include <QGraphicsItem>  
#include <QPainter>  
#include <QRectF>  
#include <QPainterPath>  
#include "NEItem.h"
#include <QColor>


struct TransFrame
{
	QPoint sourcePos;
	QPoint targetPos;
	double height;
	bool isVisable;
};

struct StripeId
{
	int x;
	int y;
	int z;
};


class NEStripeItem : public NEItem
{
	//Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
	NEStripeItem();
	NEStripeItem(const NEStripeItem &item);
	NEStripeItem(TransFrame &frames);
	NEStripeItem(TransFrame &frames, double scaling_);
	NEStripeItem(TransFrame &frames,double scaling_,StripeId id);
	~NEStripeItem();
	NEStripeItem& operator=(const NEStripeItem &item);

	virtual int getId() {
		return 0;
	}


	QRectF boundingRect()const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
	QPainterPath shape()const;

	void setStripeFrame(TransFrame frames);
	TransFrame getStripeFrame()const;

	double getScaling()const;
	void setScaling(double scaling);

	QColor getItemColor()const;
	void setItemColor(QColor color);

	void setStripeId(StripeId id);
	void setStripeId(int x,int y,int z);
	StripeId getStripeId()const;	

	int getClassId()const;
	QRectF getItemFrame()const;
	void changeSourcePos(QSize offset);
	void changeTargetPos(QSize offset);


private:
	//可有setStripeFrame函数得到
	TransFrame stripeFrame;
	QPainterPath painterPath;
	QRectF itemFrame;
	QColor itemColor;



	//stripeId[3]={timeId,classId,stripeId}
	StripeId stripeId;
	double scaling;
	int classId=0;
};

