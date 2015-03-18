#include "NEItem.h"


NEItem::NEItem()
{
	itemTag = -1;
}


NEItem::~NEItem()
{
}

void NEItem::setTag(int tag){
	itemTag= tag;
}
int NEItem::getTag(){
	return itemTag;
}