#include "TransitionNode.h"

TransitionNode::TransitionNode()
{
}


TransitionNode::~TransitionNode()
{
}

void TransitionNode::paint()
{
	int barWidth = 2;
	QBrush brush(color);
	QPen pen(color);
	bar = scene->addRect(centerX - barWidth, topY, 2 * barWidth, length, pen, brush);
}

QVector<TransitionNode>* TransitionNode::getChildren() const
{
	return children;
}
