INCLUDE = -I include/tinyxml2 -I include/

PDPExp : src/LogManager.cpp src/main.cpp src/Matrix.cpp src/Rule.cpp src/RuleManager.cpp src/XMLParser.cpp src/XPDPAlgorithm.cpp src/tinyxml2/tinyxml2.cpp

	g++ -o PDPExp $(INCLUDE) src/LogManager.cpp src/main.cpp src/Matrix.cpp src/Rule.cpp src/RuleManager.cpp src/XMLParser.cpp src/XPDPAlgorithm.cpp src/tinyxml2/tinyxml2.cpp --std=c++11 -O2 -Wall

clean : 
	rm -f *.o *.a

