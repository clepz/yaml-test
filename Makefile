all: yamlreader.cpp
	g++ -fPIC -std=c++11 yamlreader.cpp -lyaml-cpp  -o yaml