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
#include <memory>

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
		static const int STD_ITERATION;
		std::vector<Rule *> rules;
		std::vector<std::shared_ptr<Cluster>> clusters;
		Subject (){}
		~Subject (){}
		void MakeCluster ();
		static float CalculateDistance(Rule, Rule);
	private:
		void AssignCentroid(int, Cluster **);
		void CalculateNewCentroid();
	};
	class Cluster
	{
	public:
		Rule centeroid;
		std::vector<Rule *> rules;
		Cluster (){}
		Cluster (Rule *);
		~Cluster (){}
	};
public:
	static std::map<std::string, std::shared_ptr<Subject>> subjectDic;
	static void Initialize(std::vector<Rule *> *);
	static Rule Query(Rule);
	static void ReleaseAllResources();
};

#endif /* XPDPAlgorithm_hpp */
