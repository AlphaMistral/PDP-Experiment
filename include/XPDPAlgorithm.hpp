//
//  XPDPAlgorithm.hpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#ifndef XPDPAlgorithm_hpp
#define XPDPAlgorithm_hpp

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

#include "Matrix.hpp"
#include "RuleManager.hpp"

class XPDPAlgorithm
{
private:
	static XPDPAlgorithm singleton;
	XPDPAlgorithm ();
	~XPDPAlgorithm();
	class Cluster;
	class Subject
	{
	public:
		static const int STD_CLUSTER_NUM;
		std::vector<Rule> rules;
		std::vector<Cluster> clusters;
		Subject (){}
		~Subject (){}
		void MakeCluster ();
		static float CalculateDistance(Rule, Rule);
	};
	class Cluster
	{
	public:
		Rule centeroid;
		std::vector<Rule> rules;
		Cluster (){}
		Cluster (Rule);
		~Cluster (){}
	};
public:
	static std::map<std::string, Subject*> subjectDic;
	void Initialize (std::vector<Rule> *);
};

#endif /* XPDPAlgorithm_hpp */
