//
//  Rule.hpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#ifndef Rule_hpp
#define Rule_hpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

class Rule
{
public:
	std::string ruleID, subject, action, resource, condition, effect;
	Rule();
	Rule(std::string, std::string, std::string, std::string, std::string, std::string);
};

#endif /* Rule_hpp */
