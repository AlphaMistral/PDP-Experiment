//
//  LogManager.hpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#ifndef LogManager_hpp
#define LogManager_hpp

#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <istream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <chrono>

class LogManager
{
public:
	static const std::string logPath;
	static std::ofstream logStream;
	static void AppendToLog(std::string);
	static void AppendToLog(const char *);
private:
	LogManager();
	static LogManager singleton;
};

#endif /* LogManager_hpp */
