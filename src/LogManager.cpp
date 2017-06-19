//
//  LogManager.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "LogManager.hpp"

const std::string LogManager :: logPath = "Debug/PDPLOG.log";
std::ofstream LogManager :: logStream;
LogManager LogManager :: singleton;

LogManager :: LogManager()
{
	logStream.open(logPath, std::ios::app | std::ios::out);
}

void LogManager :: AppendToLog(std::string str)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	logStream << std::ctime(&now_time) << str << std::endl;
}

void LogManager :: AppendToLog(const char *str)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	logStream << std::ctime(&now_time) << str << std::endl;
}
