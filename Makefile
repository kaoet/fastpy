CXXFLAGS = -std=c++11 -Wall -Wno-switch -Wno-logical-op-parentheses
OBJS = main.o assert.o list.o int.o float.o str.o func.o set.o none.o bool.o dict.o range.o range_iterator.o

run: debug
	./debug

debug: CXXFLAGS += -O0 -g
debug: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

release: CXXFLAGS += -Ofast -flto -DNDEBUG
release: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	- rm debug release *.o *.gcno *.gcda *.gcov
