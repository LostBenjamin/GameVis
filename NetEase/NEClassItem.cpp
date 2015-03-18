#include "NEClassItem.h"

#include <QtWidgets>
#include "QDebug"

NEClassItem::NEClassItem()
{
	
	setFlags(ItemIsSelectable | ItemIsMovable);
	setAcceptHoverEvents(true);
	setCursor(Qt::OpenHandCursor);
	setAcceptedMouseButtons(Qt::LeftButton);
	setAcceptDrops(true);
	setAcceptTouchEvents(true);
	setTag(classId);
	itemColor.setNamedColor("#ffff00");
}


NEClassItem::~NEClassItem()
{
}
NEClassItem::NEClassItem(QRectF &frame, QPoint &id){
	setTag(classId);


	itemColor.setNamedColor("#ffff00");
	classFrame = frame;
	itemId = id;
	//shape();
}
NEClassItem::NEClassItem(const NEClassItem &item){

	itemColor = item.getColor();
	setTag(classId);
	classFrame = item.getClassFrame();
	itemId = item.getItemId();
}
NEClassItem& NEClassItem::operator=(const NEClassItem &item){

	itemColor.setNamedColor("#ffff00");

	classFrame = item.getClassFrame();

	itemId = item.getItemId();
	return *this;
}
QRectF NEClassItem::getClassFrame()const{
	return classFrame;
}
QPoint NEClassItem::getItemId()const{
	return itemId;
}
void NEClassItem::changePos(QSize offset){
	
	classFrame = QRectF(QPoint(classFrame.topLeft().x() + offset.width(), classFrame.topLeft().y() + offset.height()), classFrame.size());
	update();
}


void  NEClassItem::setColor(QColor color){
	itemColor = color;
	update();
	
}


QColor  NEClassItem::getColor()const
{
	return itemColor;

}



void NEClassItem::setClassFrame(QRectF frame)
{
	classFrame = frame;
	update();
}

int NEClassItem::getClassId()const{
	return classId;
}

QRectF NEClassItem::boundingRect()const{
	return QRectF(0, 0, classFrame.size().width()+10,classFrame.size().height()+10);

}
void  NEClassItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	Q_UNUSED(option);
	Q_UNUSED(widget);
	QBrush brush_bar(itemColor);
	QPen pen_bar(itemColor);
	painter->setPen(pen_bar);
	painter->setBrush(brush_bar);
	//painter->drawRect(classFrame);
	painter->drawRect(QRectF(0, 0, classFrame.size().width(), classFrame.size().height()));

}
QPainterPath NEClassItem::shape()const{
	QPainterPath path;
	path.addRect(QRectF(0, 0, classFrame.size().width(), classFrame.size().height()));         return path;
	//path.addRect(classFrame);
	return path;

}
void NEClassItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mousePressEvent(event);
	qDebug() << event->pos().x() << event->pos().y();
	update();
}

void NEClassItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

	QGraphicsItem::mouseMoveEvent(event);
	if (event->modifiers() & Qt::ShiftModifier) {
		classFrame.topLeft()= event->pos();
		update();
		return;
	}
}

void NEClassItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mouseReleaseEvent(event);
	update();
}
