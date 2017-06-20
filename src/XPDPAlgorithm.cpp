//
//  XPDPAlgorithm.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "XPDPAlgorithm.hpp"

XPDPAlgorithm XPDPAlgorithm :: singleton;
std::map<std::string, XPDPAlgorithm :: Subject*> XPDPAlgorithm :: subjectDic;

const int XPDPAlgorithm :: Subject :: STD_CLUSTER_NUM = 8;

XPDPAlgorithm :: XPDPAlgorithm()
{
	subjectDic.clear();
}

XPDPAlgorithm :: ~XPDPAlgorithm()
{
	for(std::map<std::string, XPDPAlgorithm :: Subject*>::iterator iter = subjectDic.begin();iter != subjectDic.end();iter++)
	{
		delete iter->second;
	}
}

XPDPAlgorithm :: Cluster :: Cluster(Rule r)
{
	centeroid = r;
}

void XPDPAlgorithm :: Initialize(std::vector<Rule> *r)
{
	for(std::vector<Rule>::iterator iter = r->begin();iter != r->end();iter++)
	{
		std::string subject = (*iter).subject;
		if(subjectDic.find(subject) == subjectDic.end())
		{
			subjectDic[subject] = new XPDPAlgorithm :: Subject();
			subjectDic[subject]->rules.push_back(*iter);
		}
		else
		{
			subjectDic[subject]->rules.push_back(*iter);
		}
	}
	for(std::map<std::string, XPDPAlgorithm :: Subject*>::iterator iter = subjectDic.begin();iter != subjectDic.end();iter++)
	{
		iter->second->MakeCluster();
	}
}

void XPDPAlgorithm :: Subject :: MakeCluster()
{
	int cluster_num = std::min(STD_CLUSTER_NUM, (int)rules.size());
	///Currently, the initial choose centroids from the beginning of the array.
	///Why? Because I am lazy. That's all.
	for(int i = 0;i < cluster_num;i++)
	{
		clusters.push_back(Cluster(rules[i]));
	}
	for(int i = 0;i < (int)rules.size();i++)
	{
		float smallest = std::numeric_limits<float>::max();
		int chosenCentroid = 0;
		for(int j = 0;j < cluster_num;j++)
		{
			float distance = CalculateDistance(rules[i], rules[j]);
			if(distance < smallest)
			{
				smallest = distance;
				chosenCentroid = j;
			}
		}
	}
}
