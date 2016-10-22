BUILDDIR=build

CXX=g++
CXXFLAGS=-MMD -Wall -std=c++14 -I"components" -I"systems" -I"messages" -I"input" -I"." -I"/usr/local/include/SDL2"
LDFLAGS=-L"/usr/local/lib" -lSDL2

BIN=asteroids

vpath %.cpp components systems messages input

SRC= $(wildcard *.cpp) $(wildcard */*.cpp)
OBJ=$(addprefix $(BUILDDIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC))))

all: $(BUILDDIR) $(BIN)

$(BUILDDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN) : $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILDDIR):
	mkdir $(BUILDDIR)

.PHONY:
clean:
	rm -rf $(BUILDDIR)
	rm $(BIN) $(wildcard *.o) $(wildcard *.d)
test:
	echo $(OBJ)
