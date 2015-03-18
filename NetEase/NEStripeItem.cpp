#include "NEStripeItem.h"


NEStripeItem::NEStripeItem()
{
	scaling = 0.5;
	setStripeId(-1, -1, -1);
	itemFrame = QRectF(0, 0, 0, 0);
	setTag(classId);
}


NEStripeItem::NEStripeItem(TransFrame &frames, double scaling_, StripeId id){
	setStripeFrame(frames);
	setScaling(scaling_);
	setStripeId(id);
	setTag(classId);
}
NEStripeItem::NEStripeItem(TransFrame &frames, double scaling_){
	setStripeFrame(frames);
	setScaling(scaling_);
	setTag(classId);
}






void NEStripeItem::setStripeId(StripeId id){
	stripeId = id;
}
void NEStripeItem::setStripeId(int x, int y, int z)
{
	stripeId.x = x;
	stripeId.y = y;
	stripeId.z = z;
}
StripeId NEStripeItem :: getStripeId()const{
	return stripeId;
}


QRectF  NEStripeItem::getItemFrame()const{
	return itemFrame;
}



NEStripeItem::NEStripeItem(const NEStripeItem &item){

	setStripeFrame(item.getStripeFrame());
	setStripeId(item.getStripeId());
	setScaling(item.getScaling());
	setTag(classId);
}

NEStripeItem::NEStripeItem(TransFrame &frames){
	scaling = 0.5;
	setStripeFrame(frames);
	setStripeId(-1, -1, -1);
	setTag(classId);
}

NEStripeItem::~NEStripeItem()
{
}

NEStripeItem& NEStripeItem::operator=(const NEStripeItem &item){

	setStripeFrame(item.getStripeFrame());
	setScaling(item.getScaling());

	return *this;
}



TransFrame NEStripeItem::getStripeFrame()const{
	return stripeFrame;
}

double NEStripeItem::getScaling()const{

	return scaling;

}

int NEStripeItem::getClassId()const{

	return classId;

}

void NEStripeItem::setScaling(double scaling_)
{
	scaling = scaling_;
	setStripeFrame(stripeFrame);
	update();
}





QRectF NEStripeItem::boundingRect()const
{
	
	return QRectF(0, 0, itemFrame.size().width(), itemFrame.size().height());

}


QPainterPath NEStripeItem::shape()const{
	
	return painterPath;

}








void  NEStripeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	QBrush brush_trans(QColor(0xff, 0x88, 0));
	QPen pen_trans(QColor(0xff, 0x88, 0));

	if (stripeFrame.isVisable)
	{

		painter->setPen(pen_trans);
		painter->setBrush(brush_trans);
		painter->drawPath(painterPath);


	}
}




void NEStripeItem::setStripeFrame(TransFrame frames){

	stripeFrame = frames;


	double ymin = stripeFrame.targetPos.y() > stripeFrame.sourcePos.y() ? stripeFrame.sourcePos.y() : stripeFrame.targetPos.y();
	double ymax = stripeFrame.targetPos.y() + stripeFrame.height > stripeFrame.sourcePos.y() + stripeFrame.height ? stripeFrame.targetPos.y() + stripeFrame.height : stripeFrame.sourcePos.y() + stripeFrame.height;
	double xmin = stripeFrame.sourcePos.x();
	double xmax = stripeFrame.targetPos.x();
	itemFrame = QRectF(xmin, ymin, xmax - xmin, ymax - ymin);




	if (!stripeFrame.isVisable)
	{

		return;


	}

	double sourcePolygonH = stripeFrame.height;
	double sourcePolygonX = stripeFrame.sourcePos.x()-xmin;
	double sourcePolygonY = stripeFrame.sourcePos.y()-ymin;
	double targetPolygonX = stripeFrame.targetPos.x()-xmin;
	double targetPolygonY = stripeFrame.targetPos.y()-ymin;
	double targetPolygonH = stripeFrame.height;

	QPointF sourceUp_pos(sourcePolygonX, sourcePolygonY);
	QPointF sourceBottom_pos(sourcePolygonX, sourcePolygonY + sourcePolygonH);
	QPointF midUp_pos((sourcePolygonX + targetPolygonX) / 2, (sourcePolygonY + targetPolygonY) / 2 + sourcePolygonH*(1 - scaling) / 2);
	QPointF midBottom_pos((sourcePolygonX + targetPolygonX) / 2, (sourcePolygonY + targetPolygonY) / 2 + sourcePolygonH - sourcePolygonH*(1 - scaling) / 2);
	QPointF targetUp_pos(targetPolygonX, targetPolygonY);
	QPointF targetBottom_pos(targetPolygonX, targetPolygonY + targetPolygonH);
	QPainterPath path(sourceUp_pos);

	path.moveTo(sourceUp_pos);
	path.cubicTo(midUp_pos, midUp_pos, targetUp_pos);
	path.lineTo(targetBottom_pos);
	path.cubicTo(midBottom_pos, midBottom_pos, sourceBottom_pos);
	path.lineTo(sourceUp_pos);
	painterPath = path;
	update();
}