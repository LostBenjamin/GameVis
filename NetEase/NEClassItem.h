#pragma once 
#include <QPainter>  
#include <QRectF>  
#include <QPainterPath>  
#include "qobject.h"
#include "NEItem.h"
#include <qcolor>




class NEClassItem : public NEItem
{
//	Q_OBJECT
		Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
	NEClassItem();
	~NEClassItem();
	NEClassItem(QRectF &frame,QPoint &id	);
	NEClassItem(const NEClassItem &item);
	NEClassItem& operator=(const NEClassItem &item);
	virtual int getId(){
		return 1;
	}

	QRectF getClassFrame()const;
	void changePos(QSize offset);

	void setClassFrame(QRectF frame);
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QPainterPath shape()const;
	QPoint getItemId()const;
	int getClassId()const;

	QColor getColor()const;
	void setColor(QColor color);


protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;



private:
	QRectF classFrame;
	QPoint itemId;
	QColor itemColor;

	int classId=1;
};

