#pragma once
#include "ClusterAll.h"
#include "Player.h"
class Model
{
public:
	Model(ClusterAll* _clusterAll=0, Player* _player=0);
	~Model();

private:
	ClusterAll* clusterAll;
	Player* player;
};

