//
//  main.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/18.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include <iostream>

#include "tinyxml2.h"
#include "XMLParser.hpp"

using namespace tinyxml2;

int main ()
{
	XMLParser :: ParseXML2TXT("data/xmls/asms.xml", "data/txts/asms.txt");
	XMLParser :: ParseXML2TXT("data/xmls/lms.xml", "data/txts/lms.txt");
	XMLParser :: ParseXML2TXT("data/xmls/vms.xml", "data/txts/vms.txt");
	return 0;
}
