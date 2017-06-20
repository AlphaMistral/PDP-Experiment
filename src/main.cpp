//
//  main.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/18.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include <iostream>

#include "XMLParser.hpp"
#include "RuleManager.hpp"
#include "XPDPAlgorithm.hpp"

using namespace tinyxml2;

int main ()
{
	RuleManager rm;
	rm.InitializeWithTXTFile("data/txts/vms.txt");
	XPDPAlgorithm::Initialize(rm.rules);
	std::cout << XPDPAlgorithm::Query(Rule("R", "newSub15", "RESERVEBOOK", "BORROWERACCOUNT", "SALEOPENEDMINOR", "Permit")).effect << std::endl;
	XPDPAlgorithm::ReleaseAllResources();
	while(true)
	{
		//XMLParser :: ParseXML2TXT("data/xmls/asms.xml", "data/txts/asms.txt");
		//XMLParser :: ParseXML2TXT("data/xmls/lms.xml", "data/txts/lms.txt");
		//XMLParser :: ParseXML2TXT("data/xmls/vms.xml", "data/txts/vms.txt");
		break;
	}
	return 0;
}
