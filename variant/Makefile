CXX = g++
CXXFLAGS = -g -Wall -std=c++17
PROGRAM  = variant

$(PROGRAM) : main.o
	$(CXX) -o $@ $^

.PHONY: clean

clean:
	-rm -rf $(PROGRAM) *.o *~ *core
