//
//  XPDPAlgorithm.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "XPDPAlgorithm.hpp"

XPDPAlgorithm XPDPAlgorithm :: singleton;
std::map<std::string, std::shared_ptr<XPDPAlgorithm::Subject>> XPDPAlgorithm :: subjectDic;

const int XPDPAlgorithm :: Subject :: STD_CLUSTER_NUM = 8;
const int XPDPAlgorithm :: Subject :: STD_ITERATION = 5;

XPDPAlgorithm :: XPDPAlgorithm()
{
	
}

XPDPAlgorithm :: ~XPDPAlgorithm()
{
	ReleaseAllResources();
}

void XPDPAlgorithm :: ReleaseAllResources()
{
	subjectDic.clear();
}

XPDPAlgorithm :: Cluster :: Cluster(Rule *r)
{
	centeroid = *r;
}

void XPDPAlgorithm :: Initialize(std::vector<Rule *> *r)
{
	LogManager::StartTiming();
	LogManager::Alert("Trying to Intialized the XPDP Algorithm with the indicated rules. ");
	for(std::vector<Rule *>::iterator iter = r->begin();iter != r->end();iter++)
	{
		std::string subject = (*iter)->subject;
		if(subjectDic.find(subject) == subjectDic.end())
		{
			subjectDic[subject].reset(new XPDPAlgorithm :: Subject());
			subjectDic[subject]->rules.push_back(*iter);
		}
		else
		{
			subjectDic[subject]->rules.push_back(*iter);
		}
	}
	for(std::map<std::string, std::shared_ptr<XPDPAlgorithm :: Subject>>::iterator iter = subjectDic.begin();iter != subjectDic.end();iter++)
	{
		iter->second->MakeCluster();
	}
	LogManager::AlertWithExecutionTime("XPDP Algorithm initialization Complete! ", false);
}

Rule XPDPAlgorithm :: Query(Rule r)
{
	//LogManager::StartTiming();
	Subject *correspondingSubject = subjectDic[r.subject].get();
	if(correspondingSubject == NULL)
	{
		LogManager::Alert(fromptf("The Indicated Subject: \"%s\" does not exist! ", r.subject.c_str()));
	}
	else
	{
		int cluster_num = (int)correspondingSubject->clusters.size();
		for(int i = cluster_num - 1;i > 0;i--)
		{
			for(int j = 0;j < i;j++)
			{
				if(Subject::CalculateDistance(r, correspondingSubject->clusters[j]->centeroid) < Subject::CalculateDistance(r, correspondingSubject->clusters[j + 1]->centeroid))
				{
					std::swap(correspondingSubject->clusters[j], correspondingSubject->clusters[j + 1]);
				}
			}
		}
		for(int i = 0;i < cluster_num;i++)
		{
			for(std::vector<Rule *>::iterator iter = correspondingSubject->clusters[i]->rules.begin();iter != correspondingSubject->clusters[i]->rules.end();iter++)
			{
				std::string action = (*iter)->action, resource = (*iter)->resource, condition = (*iter)->condition;
				if(r.action == action && r.resource == resource && r.condition == condition)
				{
					//LogManager::AlertWithExecutionTime("XPDP Query Complete! ", false);
					return *(*iter);
				}
			}
		}
	}
	//LogManager::AlertWithExecutionTime("XPDP Query Complete! ", false);
	return Rule("NOT FOUND", "NOT FOUND", "NOT FOUND", "NOT FOUND", "NOT FOUND", "NOT FOUND");
}

void XPDPAlgorithm :: Subject :: AssignCentroid(int cluster_num, Cluster **assignedTo)
{
	for(int i = 0;i < (int)rules.size();i++)
	{
		float smallest = std::numeric_limits<float>::max();
		int chosenCentroid = 0;
		for(int j = 0;j < cluster_num;j++)
		{
			float distance = CalculateDistance(*rules[i], clusters[j]->centeroid);
			if(distance < smallest)
			{
				smallest = distance;
				chosenCentroid = j;
			}
		}
		assignedTo[i] = clusters[chosenCentroid].get();
	}
}

void XPDPAlgorithm :: Subject :: MakeCluster()
{
	int cluster_num = std::min(STD_CLUSTER_NUM, (int)rules.size());
	Cluster *assignedTo[(int)rules.size()];
	///Currently, the initial choose centroids from the beginning of the array.
	///Why? Because I am lazy. That's all.
	for(int i = 0;i < cluster_num;i++)
	{
		clusters.push_back(std::shared_ptr<Cluster>(new Cluster(rules[i])));
	}
	
	AssignCentroid(cluster_num, assignedTo);
	
	for(int i = 0;i < STD_ITERATION;i++)
	{
		CalculateNewCentroid();
		AssignCentroid(cluster_num, assignedTo);
	}
	
	for(int i = 0;i < (int)rules.size();i++)
	{
		assignedTo[i]->rules.push_back(rules[i]);
	}
}

void XPDPAlgorithm :: Subject :: CalculateNewCentroid()
{
	int cluster_num = std::min(STD_CLUSTER_NUM, (int)rules.size());
	for(int i = 0;i < cluster_num;i++)
	{
		std::map<std::string, int> actDic, resDic, conDic;
		int actionNum = 0, resourceNum = 0, conditionNum = 0;
		std::string action, resource, condition;
		for(int j = 0;j < (int)rules.size();j++)
		{
			std::string tempAct = rules[j]->action;
			std::string tempRes = rules[j]->resource;
			std::string tempCon = rules[j]->condition;
			
			if(actDic.find(tempAct) == actDic.end())
				actDic[tempAct] = 1;
			else actDic[tempAct]++;
			if(resDic.find(tempRes) == resDic.end())
				resDic[tempRes] = 1;
			else resDic[tempRes]++;
			if(conDic.find(tempCon) == conDic.end())
				conDic[tempCon] = 1;
			else conDic[tempCon]++;
			
			if(actDic[tempAct] > actionNum)
				action = tempAct, actionNum = actDic[tempAct];
			if(resDic[tempRes] > resourceNum)
				resource = tempRes, resourceNum = resDic[tempRes];
			if(conDic[tempCon] > conditionNum)
				condition = tempCon, conditionNum = conDic[tempCon];
		}
		clusters[i]->centeroid.action = action;
		clusters[i]->centeroid.resource = resource;
		clusters[i]->centeroid.condition = condition;
	}
}

float XPDPAlgorithm :: Subject :: CalculateDistance(Rule a, Rule b)
{
	float res = 0.0f;
	if(a.action == b.action)
		res += 0.6f;
	if(a.resource == b.resource)
		res += 0.3f;
	if(a.condition == b.condition)
		res += 0.1f;
	return res;
}
