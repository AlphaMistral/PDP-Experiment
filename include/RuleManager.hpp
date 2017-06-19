//
//  RuleManager.hpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#ifndef RuleManager_hpp
#define RuleManager_hpp

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>
#include <vector>

#include "Rule.hpp"
#include "LogManager.hpp"

class RuleManager
{
public:
	std::vector<Rule> *rules;
	RuleManager();
	RuleManager(const char *);
	bool InitializeWithTXTFile(const char *);
};

#endif /* RuleManager_hpp */
