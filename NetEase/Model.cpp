#include "Model.h"


Model::Model(ClusterAll* _clusterAll, Player* _player) : clusterAll(_clusterAll), player(_player)
{
}


Model::~Model()
{
}

void Model::loadTestData()
{
	player->loadTestData(clusterAll);
}

ClusterAll* Model::getClusterAll()
{
	return clusterAll;
}