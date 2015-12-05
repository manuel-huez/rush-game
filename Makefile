CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -Werror -pedantic -std=c++14 -g
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

CXXSRC = src/game.cc \
				 src/engine/engine.cc \
				 src/engine/scene.cc \
				 src/engine/object.cc \
				 src/engine/color.cc \
				 src/engine/font.cc \
				 src/game/scenes/main-scene.cc \
				 src/game/scenes/menu-scene.cc \
				 src/maze/maze.cc \
				 src/maze/generator.cc \
				 src/maze/room.cc
CXXOBJ = $(CXXSRC:.cc=.o)
CXXBIN = ./lab

all: game

bin: $(CXXOBJ)
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $(CXXBIN)

game: bin
	$(CXXBIN)

clean:
	$(RM) $(CXXOBJ) $(CXXBIN)

.PHONY: all bin game clean
