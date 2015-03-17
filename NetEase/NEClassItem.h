#pragma once
#include <QGraphicsItem>  
#include <QPainter>  
#include <QRectF>  
#include <QPainterPath>  
#include "qobject.h"
class NEClassItem : public QGraphicsItem
{
//	Q_OBJECT
		Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
	NEClassItem();
	~NEClassItem();
	NEClassItem(QRectF &frame,QPoint &id	);
	NEClassItem(const NEClassItem &item);
	NEClassItem& operator=(const NEClassItem &item);
	QRectF getClassFrame()const;
	void changePos(QPoint pos);

	void setClassFrame(QRectF frame);
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QPainterPath shape()const;
	QPoint getItemId()const;


protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;



private:
	QRectF classFrame;
	QPoint itemId;
	int classId;
};

