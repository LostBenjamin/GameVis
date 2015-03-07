#include "TransitionNode.h"

TransitionNode::TransitionNode(TransitionNode* p, QGraphicsScene* s, QColor c, int l, int cx, int ty):
	parent(p),
	scene(s),
	color(c),
	length(l),
	centerX(cx),
	topY(ty)
{
	paintBar();
//	if(p!=NULL) p->addChild(this);
}

TransitionNode::TransitionNode()
{

}


TransitionNode::~TransitionNode()
{
}

void TransitionNode::paintBar()
{
	int barWidth = 2;
	QBrush brush(color);
	QPen pen(color);
	bar = scene->addRect(centerX - barWidth, topY, 2 * barWidth, length, pen, brush);
}

QVector<TransitionNode*>* TransitionNode::getChildren() const
{
	return children;
}

void TransitionNode::addChild(TransitionNode* t)
{
	children->push_back(t);
//	for (QVector<TransitionNode>::iterator it = children->begin(); it != children->end(); it++)
//		it->addChild(t);
}
