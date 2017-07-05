#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
#include "Rule.hpp"
#include "Rule.cpp"
using namespace std;
vector<Rule> readRequests(void)
{
	vector<Rule> Requests;
	ifstream in("request.txt");
	string i,s,a,r,c,e;
	string flag="request";
	while(in>>s>>a>>r>>c>>e)
	{
		Requests.push_back(Rule(flag,s,a,r,c,e));
	}
	in.close();
	return Requests;
}
void printReq(Rule req)
{
	cout<<req.ruleID<<" "<<req.subject<<" "<<req.action<<" "<<req.resource<<" "<<req.condition<<" "<<req.effect<<endl;
}
int main()
{
	vector<Rule> Requests=readRequests();
	vector<Rule>::iterator iter=Requests.begin();
	while(iter!=Requests.end())
	{
		printReq(*iter);
		*iter++;
	}	
	return 0;
}
