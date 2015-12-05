CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++14 
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

CXXSRC = src/game.cc \
				 src/engine/engine.cc \
				 src/engine/scene.cc \
				 src/engine/object.cc \
				 src/engine/game-object.cc \
				 src/engine/color.cc \
				 src/engine/font.cc \
				 src/game/scenes/main-scene.cc \
				 src/game/scenes/menu-scene.cc \
				 src/game/objects/background.cc \
				 src/game/objects/maze.cc \
				 src/game/objects/menu.cc \
				 src/game/objects/player.cc \
				 src/maze/maze.cc \
				 src/maze/generator.cc \
				 src/maze/room.cc	\
				 src/maze/world.cc \
				 src/pathfinding/path.cc \
				 src/game/objects/enemy.cc \
				 src/game/objects/sentinel.cc
CXXOBJ = $(CXXSRC:.cc=.o)
CXXBIN = ./lab

all: game

bin: $(CXXOBJ)
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $(CXXBIN)

game:
	$(MAKE) -Bj bin
	$(CXXBIN)

clean:
	$(RM) $(CXXOBJ) $(CXXBIN)

.PHONY: all bin game clean
