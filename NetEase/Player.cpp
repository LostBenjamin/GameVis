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
			double count_=0;
			for (int k = 0; k < CLUSTER_SIZE; k++)
			{
				double tmp;
				in >> tmp;
				if (tmp<0)
				{
					tmp = 0;
				}
				count_ += tmp;
				clusterItem->push_back(tmp);
				clusterSet->setMatrixElement(j, k, tmp);
			}
			if (count_==0)
			{
				count_ = 0;
			}
			if (i==0)
			{
				clusterItem->setCountRecord(1);
			}
			else
			{

				ClusterSet* lastClusterSet = clusterAll->getLastElement();
				double totalCountRecord = 0;
				for (int k = 0; k < lastClusterSet->getCount(); k++){
					ClusterItem *item=lastClusterSet->itemsAtIndex(k);
					totalCountRecord += item->getCountRecord()*item->getTransition()[j];
				}
				clusterItem->setCountRecord(totalCountRecord);
			}

//
			clusterSet->push_back(*clusterItem);
		}
		clusterAll->push_back(*clusterSet);
	}
}