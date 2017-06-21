//
//  XMLParser.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/19.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include "XMLParser.hpp"

using namespace tinyxml2;

bool XMLParser :: ParseXML2TXT(const char *xml, const char *txt)
{
	int sum = 0;
	XMLDocument xmlFile;
	xmlFile.LoadFile(xml);
	
	std::string msg;
	if (xmlFile.Error())
	{
		LogManager::Alert(fromptf("!!!!!The indicated file path: \n%s \ndoes not exist, or the file itself is not an XML file. Please have a check before trying to parsing it. The Parser is now exited without doing anything. ", xml));
		return false;
	}
	
	std::ofstream toTxt;
	toTxt.open(txt, std::ios::out);
	
	XMLElement *policy = xmlFile.FirstChildElement("Policy");
	XMLElement *description = policy->FirstChildElement("Description");
	
	LogManager::Alert(fromptf("Currently Parsing :\"%s\"...The Description is as follows:\n %s\n......", xml, description->GetText()));
	
	XMLElement *rule = policy->FirstChildElement("Rule");
	
	while (rule != NULL)
	{
		XMLElement *target = rule->FirstChildElement("Target");
		XMLElement *subject = target->FirstChildElement("Subjects")->FirstChildElement("Subject")->FirstChildElement("SubjectMatch")->FirstChildElement("AttributeValue");
		XMLElement *resource = target->FirstChildElement("Resources")->FirstChildElement("Resource")->FirstChildElement("ResourceMatch")->FirstChildElement("AttributeValue");
		XMLElement *action = target->FirstChildElement("Actions")->FirstChildElement("Action")->FirstChildElement("ActionMatch")->FirstChildElement("AttributeValue");
		XMLElement *condition = rule->FirstChildElement("Condition")->FirstChildElement("AttributeValue");
		
		std::string _effect, _subject, _resource, _action, _condition, _ruleID;
		
		_effect = CastToString(rule->Attribute("Effect"));
		_ruleID = CastToString(rule->Attribute("RuleId"));
		_subject = CastToString(subject->GetText());
		_resource = CastToString(resource->GetText());
		_action = CastToString(action->GetText());
		_condition = CastToString(condition->GetText());
		
		toTxt << _ruleID << " " << _subject << " " << _action << " " << _resource << " " << _condition << " " << _effect << std::endl;
		
		sum++;
		
		rule = rule->NextSiblingElement("Rule");
	}
	
	LogManager::Alert(fromptf("Parsing Complete: %s is now parsed into %s! %d entries in total. ", xml, txt, sum));
	
	return true;
}

std::string XMLParser :: CastToString(const char *src)
{
	if(src == NULL)
		return std::string("NULL");
	else return std::string(src);
}
