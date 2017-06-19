//
//  Rule.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "Rule.hpp"

Rule :: Rule()
{
	
}

Rule :: Rule(std::string id, std::string sub, std::string act, std::string res, std::string con, std::string eff)
{
	ruleID = id;
	subject = sub;
	action = act;
	resource = res;
	condition = con;
	effect = eff;
}
