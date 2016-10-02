BUILDDIR=build
OBJ=$(addprefix $(BUILDDIR)/, $(patsubst %.cpp, %.o, $(wildcard *.cpp)))
DEPS=$(OBJ:.o=.d)
CXXFLAGS += -std=c++14
BIN=asteroids

-include $(DEPS)

all: $(BUILDDIR) $(BIN)

$(BUILDDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN) : $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^


$(BUILDDIR):
	mkdir $(BUILDDIR)

.PHONY:
clean:
	rm $(BIN) $(wildcard *.o) $(wildcard *.d) $(wildcard *.gch)
	rm -rf $(BUILDDIR)
