#pragma once
#include <QGraphicsItem>  
#include <QPainter>  
#include <QRectF>  
#include <QPainterPath>  



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


class NEStripeItem : public QGraphicsItem
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



	void setStripeFrame(TransFrame frames);
	QRectF boundingRect()const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
	QPainterPath shape()const;
	TransFrame getStripeFrame()const;
	double getScaling()const;
	void setScaling(double scaling);
	void setStripeId(StripeId id);
	void setStripeId(int x,int y,int z);
	StripeId getStripeId()const;	
	QRectF getItemFrame()const;



private:
	//可有setStripeFrame函数得到
	TransFrame stripeFrame;
	QPainterPath painterPath;
	QRectF itemFrame;
	//stripeId[3]={timeId,classId,stripeId}
	StripeId stripeId;
	double scaling;
	int classId;
};

