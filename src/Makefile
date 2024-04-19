CXX = g++
CXXFLAGS = --std=c++11 
block.o: block.cpp block.h
	$(CXX) $(CXXFLAGS) -c block.cpp
game_map.o: game_map.cpp game_map.h block.h
	$(CXX) $(CXXFLAGS) -c game_map.cpp
level.o: level.cpp level.h game_map.h block.h
	$(CXX) $(CXXFLAGS) -c level.cpp
main.o: main.cpp block.h game_map.h level.h
	$(CXX) $(CXXFLAGS) -c main.cpp
main: main.o block.o game_map.o level.o
	$(CXX) $(CXXFLAGS) -o main main.o block.o game_map.o level.o
clean:
	rm -f main main.o block.o game_map.o level.o
.PHONY: clean