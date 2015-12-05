CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -Werror -pedantic -std=c++14 -g
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

CXXSRC_G = src/game.cc \
		 src/engine/engine.cc \
		 src/engine/scene.cc \
		 src/engine/object.cc \
		 src/engine/color.cc \
		 src/game/scenes/main-scene.cc
CXXSRC_M= src/maze/main.cc \
					src/maze/maze.cc \
					src/maze/generator.cc \
					src/maze/room.cc
CXXOBJ_G = $(CXXSRC_G:.cc=.o)
CXXOBJ_M= $(CXXSRC_M:.cc=.o)
CXXBIN = ./game

all: game

bin: $(CXXOBJ_G)
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $(CXXBIN)

bin_m: $(CXXOBJ_M)
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $(CXXBIN)

game: bin
	$(CXXBIN)

maze: bin_m
	$(CXXBIN)

clean:
	$(RM) $(CXXOBJ_G) $(CXXOBJ_M) $(CXXBIN)

.PHONY: all bin game clean
