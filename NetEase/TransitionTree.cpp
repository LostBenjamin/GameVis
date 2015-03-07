#include "TransitionTree.h"


TransitionTree::TransitionTree(TransitionNode* t, QGraphicsScene* q):
	root(t),
	scene(q)
{
}


TransitionTree::~TransitionTree()
{
}

void TransitionTree::display()
{
	root->paintBar();

	QVector<TransitionNode*>* ch = root->getChildren();
	for (QVector<TransitionNode*>::iterator it = ch->begin(); it != ch->end(); it++)
		(*it)->paintBar();
}

void TransitionTree::addNode(TransitionNode* t)
{
	root->addChild(t);
}