EXE = client
CXX = clang++
CXXFLAGS = -ggdb3 -O0 -std=c++14 -Wall -Wextra -Wshadow
OBJS = $(EXE).o p1.o

$(EXE): $(OBJS) makefile
	$(CXX) $(CXXLAGS) -o $@ $(OBJS)

# Remove object files from folder
clean:
	rm -f core $(EXE) *.o

run: $(EXE)
	./$(EXE)

