#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::loadTestData(ClusterAll* clusterAll)
{
	for (int i = 0; i < TIME_SIZE; i++)
	{
		std::string s = std::to_string(i+1);
		std::ifstream in("new/result"+ s + ".csv");
		ClusterSet* clusterSet = new ClusterSet;
		for (int j = 0; j < CLUSTER_SIZE; j++)
		{
			ClusterItem* clusterItem = new ClusterItem;
			for (int k = 0; k < CLUSTER_SIZE; k++)
			{
				double tmp;
				in >> tmp;
				clusterItem->push_back(tmp);
				clusterSet->setMatrixElement(j, k, tmp);
			}
			clusterSet->push_back(*clusterItem);
		}
		clusterAll->push_back(*clusterSet);
	}
}