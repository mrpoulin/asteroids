include standard_defs.mk

vpath %.cpp components systems messages

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
