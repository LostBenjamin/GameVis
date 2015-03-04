#include "TransitionTree.h"


TransitionTree::TransitionTree()
{
}


TransitionTree::~TransitionTree()
{
}

void TransitionTree::display()
{
	root->paint();

	QVector<TransitionNode>* ch = root->getChildren();
	for (QVector<TransitionNode>::iterator it = ch->begin(); it != ch->end(); it++)
		it->paint();
}