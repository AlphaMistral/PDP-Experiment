//
//  main.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/18.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include <iostream>

#include "tinyxml2.h"
#include "LogManager.hpp"
#include "XMLParser.hpp"

using namespace tinyxml2;

int main ()
{
	static const char* xml =
	"<?xml version=\"1.0\"?>"
	"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
	"<PLAY>"
	"<TITLE>A Midsummer Night's Dream</TITLE>"
	"</PLAY>";
	XMLDocument testDoc;
	testDoc.LoadFile("data/xmls/asms.xml");
	XMLElement *rule = testDoc.FirstChildElement("Policy")->FirstChildElement("Rule");
	XMLElement *target = rule->FirstChildElement("Target");
	XMLElement *subject = target->FirstChildElement("Subjects")->FirstChildElement("Subject")->FirstChildElement("SubjectMatch")->FirstChildElement("AttributeValue");
	printf("%s\n", subject->GetText());
	XMLElement *nextSubject = target->FirstChildElement("Subjects")->NextSiblingElement()->FirstChildElement("Resource")->FirstChildElement("ResourceMatch")->FirstChildElement("AttributeValue");
	if (nextSubject->GetText() == NULL)
		puts("NULL!");
	printf("%s\n", nextSubject->GetText());
	XMLDocument doc;
	doc.Parse( xml );
	XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
	const char* title = titleElement->GetText();
	printf( "Name of play (1): %s\n", title );
	std :: cout << "Fuck World" << std :: endl;
	XMLParser :: ParseXML2TXT("data/xmls/asms.xml", "data/txts/asms.txt");
	XMLParser :: ParseXML2TXT("data/xmls/lms.xml", "data/txts/lms.txt");
	XMLParser :: ParseXML2TXT("data/xmls/vms.xml", "data/txts/vms.txt");
	return 0;
}
