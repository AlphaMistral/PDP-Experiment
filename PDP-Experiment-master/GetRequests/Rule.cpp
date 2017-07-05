
#include "Rule.hpp"

Rule :: Rule()
{
	
}

Rule :: Rule(std::string id, std::string sub, std::string act, std::string res, std::string con, std::string eff)
{
	ruleID = id;
	subject = sub;
	action = act;
	resource = res;
	condition = con;
	effect = eff;
}
