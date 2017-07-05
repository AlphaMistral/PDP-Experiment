

#ifndef Rule_hpp
#define Rule_hpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

class Rule
{
public:
	std::string ruleID, subject, action, resource, condition, effect;
	Rule();
	Rule(std::string, std::string, std::string, std::string, std::string, std::string);
};

#endif /* Rule_hpp */
