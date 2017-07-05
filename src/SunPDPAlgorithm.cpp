//
//  SunPDPAlgorithm.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/7/5.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "SunPDPAlgorithm.hpp"

std::vector<Rule *> * SunPDPAlgorithm :: rules;

SunPDPAlgorithm :: SunPDPAlgorithm()
{
	rules = NULL;
}

SunPDPAlgorithm :: SunPDPAlgorithm(std::vector<Rule *> *r)
{
	InitWithRules(r);
}

void SunPDPAlgorithm :: InitWithRules(std::vector<Rule *> *r)
{
	rules = r;
}

Rule SunPDPAlgorithm :: Query(Rule rule)
{
	LogManager::StartTiming();
	Rule result;
	for(std::vector<Rule *> :: iterator iter = rules->begin();iter != rules->end();iter++)
	{
		if((*iter)->subject == rule.subject && (*iter)->action == rule.action && (*iter)->resource == rule.resource && (*iter)->condition == rule.condition)
		{
			LogManager::AlertWithExecutionTime("Sun PDP Complete! ", false);
			return **iter;
		}
	}
	LogManager::AlertWithExecutionTime("Sun PDP Complete! ", false);
	return Rule("NOT FOUND", "NOT FOUND", "NOT FOUND", "NOT FOUND", "NOT FOUND", "NOT FOUND");
}
