CXXFLAGS = -std=c++11 -Wall -Wno-switch -Wno-logical-op-parentheses
OBJS = assert.o list.o int.o float.o str.o func.o set.o none.o bool.o dict.o range.o range_iterator.o slice.o list_iterator.o set_iterator.o dict_iterator.o generated.o

run: debug
	./debug

debug: CXXFLAGS += -O0 -g
debug: $(OBJS) main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

release: CXXFLAGS += -Ofast -march=native -flto -DNDEBUG
release: $(OBJS) main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

test: CXXFLAGS += -Ofast -march=native -flto -DNDEBUG
test: $(OBJS) test.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
.PHONY: clean
clean:
	- rm debug release *.o *.gcno *.gcda *.gcov
