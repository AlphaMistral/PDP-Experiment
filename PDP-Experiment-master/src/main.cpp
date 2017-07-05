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
#include "SunPDPAlgorithm.hpp"
#include "SunPDPAlgorithm.cpp"

using namespace tinyxml2;

std::vector<Rule> readRequests(void)
{
	std::vector<Rule> Requests;
	std::ifstream in("data/txts/request.txt");
	if(!in)
	{
		std::cout<<"Can't open request.txt"<<std::endl;	
	}
	std::string i,s,a,r,c,e;
	std::string flag="request";
	while(in>>s>>a>>r>>c>>e)
	{
		Requests.push_back(Rule(flag,s,a,r,c,e));
	}
	in.close();
	return Requests;
}
int main ()
{
	RuleManager rm;
	rm.InitializeWithTXTFile("data/txts/vms.txt");
	std::vector<Rule> Requests=readRequests();
	std::vector<Rule>::iterator iter=Requests.begin();
	std::cout<<Requests.size()<<" requests are loaded!"<<std::endl;


	XPDPAlgorithm::Initialize(rm.rules);
	LogManager::StartTiming();
	while(iter!=Requests.end())
	{	
		XPDPAlgorithm::Query(*iter);
		//std::cout << XPDPAlgorithm::Query(*iter).effect << std::endl;
		*iter++;
	}
	LogManager::AlertWithExecutionTime("XPDP: Query Complete! ", false);
	XPDPAlgorithm::ReleaseAllResources();
	
	iter=Requests.begin();

	SunPDPAlgorithm::InitWithRules(rm.rules);
	LogManager::StartTiming();
	while(iter!=Requests.end())
	{
		SunPDPAlgorithm::Query(*iter);		
		//std::cout << SunPDPAlgorithm::Query(*iter).effect << std::endl;
		*iter++;
	}
	LogManager::AlertWithExecutionTime("SunPDP: Query Complete! ", false);
	
	return 0;
}
