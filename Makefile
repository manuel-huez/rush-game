CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -Werror -pedantic -std=c++14 -g
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

CXXSRC = src/game.cc \
		 src/engine/engine.cc \
		 src/engine/event-handler.cc \
		 src/engine/scene.cc \
		 src/engine/object.cc \
		 src/engine/color.cc
CXXOBJ = $(CXXSRC:.cc=.o)
CXXBIN = ./game

all: game

bin: $(CXXOBJ)
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $(CXXBIN)

game: bin
	$(CXXBIN)

clean:
	$(RM) $(CXXOBJ) $(CXXBIN)

.PHONY: all bin game clean
