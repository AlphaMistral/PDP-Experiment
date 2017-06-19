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
		msg = fromptf("The Indicated TXT File \"%s\" does not exist! Initialization of Rule Manager Aborted! \n", txt);
		std::cout << msg;
		LogManager::AppendToLog(msg);
		return false;
	}
	rules = new std::vector<Rule>();
	msg = fromptf("TXT File \"%s\" is now being analyzed. Please standby ... \n", txt);
	std::cout << msg;
	LogManager::AppendToLog(msg);
	std::string i, s, a, r, c, e;
	while(txtIn >> i >> s >> a >> r >> c >> e)
	{
		rules->push_back(Rule(i, s, a, r, c, e));
	}
	msg = fromptf("File Analysis is successful! %d entries have been read into the rules! \n", rules->size());
	std::cout << msg;
	LogManager::AppendToLog(msg);
	return true;
}
