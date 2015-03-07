#pragma once

#include <QtWidgets/QGraphicsItem>
#include "TransitionNode.h"

class TransitionTree
{
public:
	TransitionTree(TransitionNode*, QGraphicsScene*);
	~TransitionTree();
	void display();
	void addNode(TransitionNode* t);

private:
	TransitionNode* root;
	QGraphicsScene* scene;

};

