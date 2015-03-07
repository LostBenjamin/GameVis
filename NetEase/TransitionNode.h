#pragma once

#include <QtCore/QVector>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QtGui/QBrush>
#include <QtGui/QPen>

class TransitionNode
{
public:
	TransitionNode(TransitionNode* p, QGraphicsScene* s, QColor c, int l, int cx, int ty);
	TransitionNode();
	~TransitionNode();
	void paintBar();
	QVector<TransitionNode*>* getChildren() const;
	void addChild(TransitionNode* t);

protected:
	QVector<TransitionNode*>* children;

private:
	TransitionNode* parent;
	QGraphicsRectItem* bar;
	QGraphicsScene* scene;
	QColor color;
	int length;
	int centerX, topY;
};

