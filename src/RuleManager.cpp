//
//  RuleManager.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "RuleManager.hpp"

RuleManager :: RuleManager()
{
	rules = NULL;
}

RuleManager :: ~RuleManager()
{
	rules->clear();
}

RuleManager :: RuleManager(const char *txt)
{
	if(!InitializeWithTXTFile(txt))
		rules = NULL;
}

bool RuleManager::InitializeWithTXTFile(const char *txt)
{
	std::string msg;
	std::ifstream txtIn(txt, std::ios::in);
	if(!txtIn.good())
	{
		LogManager::Alert(fromptf("The Indicated TXT File \"%s\" does not exist! Initialization of Rule Manager Aborted! ", txt));
		return false;
	}
	rules = new std::vector<Rule *>();
	LogManager::Alert(fromptf("TXT File \"%s\" is now being analyzed. Please standby ... ", txt));
	std::string i, s, a, r, c, e;
	while(txtIn >> i >> s >> a >> r >> c >> e)
	{
		rules->push_back(new Rule(i, s, a, r, c, e));
	}
	LogManager::Alert(fromptf("File Analysis is successful! %d entries have been read into the rules! ", rules->size()));
	return true;
}
