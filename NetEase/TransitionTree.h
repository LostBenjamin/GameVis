#pragma once

#include <QtWidgets/QGraphicsItem>
#include "TransitionNode.h"

class TransitionTree
{
public:
	TransitionTree();
	~TransitionTree();
	void display();

private:
	TransitionNode* root;
	QGraphicsScene* scene;

};

