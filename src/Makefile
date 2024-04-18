CXX = g++
CXXFLAGS = --std=c++11 
block.o: block.cpp block.h
	$(CXX) $(CXXFLAGS) -c block.cpp
game_map.o: game_map.cpp game_map.h block.h
	$(CXX) $(CXXFLAGS) -c game_map.cpp
main.o: main.cpp block.h game_map.h
	$(CXX) $(CXXFLAGS) -c main.cpp
main: main.o block.o game_map.o
	$(CXX) $(CXXFLAGS) -o main main.o block.o game_map.o
clean:
	rm -f main main.o block.o game_map.o
.PHONY: clean