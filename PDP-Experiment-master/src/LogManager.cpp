//
//  LogManager.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "LogManager.hpp"

const std::string LogManager :: logPath = "PDPLOG.log";
std::ofstream LogManager :: logStream;
LogManager LogManager :: singleton;
double LogManager :: startTime;

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

void LogManager :: Alert(std::string str)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	std::cout << str << std::endl;
	logStream << std::ctime(&now_time) << str << std::endl;
}

void LogManager :: Alert(const char *str)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	std::cout << str << std::endl;
	logStream << std::ctime(&now_time) << str << std::endl;
}

void LogManager :: AlertWithExecutionTime(std::string str, bool restart)
{
	Alert(str);
	logStream << "Execution Time: " << GetExecutionTime() << "ms." << std::endl;
	if(restart)
		StartTiming();
}

void LogManager :: AlertWithExecutionTime(const char *str, bool restart)
{
	Alert(str);
	logStream << "Execution Time: " << GetExecutionTime() << "ms. " << std::endl;
	if(restart)
		StartTiming();
}

void LogManager :: StartTiming()
{
	startTime = clock();
}

double LogManager :: GetExecutionTime()
{
	return (clock() - startTime)/(double)CLOCKS_PER_SEC * 1000;
}

std::string fromptf(const char *fmt, ...)
{
	__gnuc_va_list args;
	va_start(args, fmt);
	char buf[32];
	size_t n = std::vsnprintf(buf, sizeof(buf), fmt, args);
	va_end(args);
	
	// Static buffer large enough?
	if (n < sizeof(buf))
	{
		return {buf, n};
	}
	
	// Static buffer too small
	std::string s(n + 1, 0);
	va_start(args, fmt);
	std::vsnprintf(const_cast<char*>(s.data()), s.size(), fmt, args);
	va_end(args);
	
	return s;
}
