CXX = g++ -std=c++11
OPTS = -g -O2
WARN = -Wall -Werror
DEPS = -MMD -MF $*.d
INCL =

OBJS = test_algorithm.o timing.o

default: $(OBJS)

docs:
	doxygen DoxygenSetup/doxyfile.prog03

clean:
	rm -rf Dependencies $(OBJS)

%.o: %.cpp
	$(CXX) $(OPTS) $(WARN) $(DEPS) $(INCL) $< -o $@
	cat $*.d >> Dependencies
	rm -f $*.d

-include Dependencies

