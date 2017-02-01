CXXFLAGS = -std=c++11 -lncurses

CXXFILES = $(shell find src -type f -name '*.cpp')
OBJECTS  = $(CXXFILES:.cpp=.o)

INCLUDESDIR = -I"src/"
OUTPUTFILE = VendeurAssistant

%.o: %.cpp
	$(CXX) $(CXXFLAGS)  $< -c -o $@  $(INCLUDESDIR)

default: main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUTPUTFILE)

clean:
	rm $(OBJECTS)
