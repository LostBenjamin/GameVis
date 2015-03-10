#pragma once
#include "ClusterAll.h"
#include "fstream"
#include "iostream"
class Player
{
public:
	Player();
	~Player();
	void loadTestData(ClusterAll* clusterAll);
};

