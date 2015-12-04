CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -Werror -pedantic -std=c++14
LDLIBS=-lsfml-graphics

CXXSRC = src/game.cc
CXXOBJ = $(CXXSRC:.cc=.o)
CXXBIN = ./game

all: game

game: $(CXXOBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(CXXBIN)

clean:
	$(RM) $(OBJ) $(BIN)

.PHONY: all game clean
