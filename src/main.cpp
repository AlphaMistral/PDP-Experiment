//
//  main.cpp
//  PDP-Experiment
//
//  Created by 于京平 on 2017/6/18.
//  Copyright © 2017年 于京平. All rights reserved.
//

#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;

int main ()
{
	static const char* xml =
	"<?xml version=\"1.0\"?>"
	"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
	"<PLAY>"
	"<TITLE>A Midsummer Night's Dream</TITLE>"
	"</PLAY>";
	XMLDocument doc;
	doc.Parse( xml );
	XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
	const char* title = titleElement->GetText();
	printf( "Name of play (1): %s\n", title );
	std :: cout << "Fuck World" << std :: endl;
	return 0;
}
