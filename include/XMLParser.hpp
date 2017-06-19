//
//  XMLParser.hpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#ifndef XMLParser_hpp
#define XMLParser_hpp

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#include "tinyxml2.h"
#include "LogManager.hpp"

///XML Parser is a static Singleton. You are not supposed to instantiate it!
///It just does a simple job, doesn't it? 
class XMLParser
{
public:
	static char *xmlFilePath;
	static char *txtFilePath;
	static bool ParseXML2TXT(const char *, const char *);
private:
	static std::string CastToString(const char *);
};

#endif /* XMLParser_hpp */
