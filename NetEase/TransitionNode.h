#pragma once

#include <QtCore/QVector>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QtGui/QBrush>
#include <QtGui/QPen>

class TransitionNode
{
public:
	TransitionNode();
	~TransitionNode();
	void paint();
	QVector<TransitionNode>* getChildren() const;

protected:
	QVector<TransitionNode>* children;

private:
	TransitionNode* parent;
	QGraphicsRectItem* bar;
	QGraphicsScene* scene;
	QColor color;
	int length;
	int centerX, topY;
};

