//
//  SunPDPAlgorithm.hpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/7/5.
//  Copyright © 2017年 于京平. All rights reserved.
//

#ifndef SunPDPAlgorithm_hpp
#define SunPDPAlgorithm_hpp

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

#include "Rule.hpp"
#include "tinyxml2.h"
#include "LogManager.hpp"

class SunPDPAlgorithm
{
public:
	static std::vector<Rule *> *rules;
	SunPDPAlgorithm();
	SunPDPAlgorithm(std::vector<Rule *> *);
	static Rule Query(Rule);
	static void InitWithRules(std::vector<Rule *> *);
private:
	static SunPDPAlgorithm singleton;
};

#endif /* SunPDPAlgorithm_hpp */
