BUILDDIR=build

CXX=g++
CXXFLAGS=-MMD -Wall -std=c++14 -I"components" -I"systems" -I"messages" -I"input" -I"graphics" -I"." -I"/usr/local/include/SDL2"
LDFLAGS=-L"/usr/local/lib" -lSDL2 -lSDL2_image

BIN=asteroids

vpath %.cc components systems messages input graphics

SRC= $(wildcard *.cc) $(wildcard */*.cc)
OBJ=$(addprefix $(BUILDDIR)/, $(notdir $(patsubst %.cc, %.o, $(SRC))))

all: $(BUILDDIR) $(BIN)

$(BUILDDIR)/%.o: %.cc
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
