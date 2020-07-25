
INC=-I/opt/ros/melodic/include
LIBS=-L/opt/ros/melodic/lib -lroscpp -lrosconsole -lroscpp_serialization -lrostime -ltf2_ros

all: yamlreader.cpp
	g++ -fPIC -g -std=c++11 yamlreader.cpp $(INC) $(LIBS) -lyaml-cpp  -o yaml

clean:
	rm yaml