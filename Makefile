CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -Werror -pedantic -std=c++14
LDLIBS=-lsfml-graphics

CXXSRC = src/game.cc \
		 src/engine/engine.cc \
		 src/event-handler.cc
CXXOBJ = $(CXXSRC:.cc=.o)
CXXBIN = ./game

all: game

bin: $(CXXOBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(CXXBIN)

game: bin
	$(CXXBIN)

clean:
	$(RM) $(OBJ) $(BIN)

.PHONY: all bin game clean
