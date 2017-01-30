CXXFLAGS = -std=c++11

CXXFILES = $(shell find src -type f -name '*.cpp')
OBJECTS  = $(CXXFILES:.cpp=.o)

INCLUDESDIR = -I"src/"
OUTPUTFILE = MasterSalesman

%.o: %.cpp
	$(CXX) $(CXXFLAGS)  $< -c -o $@  $(INCLUDESDIR)

default: main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUTPUTFILE)

clean:
	rm $(OBJECTS) $(OUTPUTFILE)