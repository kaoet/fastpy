CXXFLAGS = -std=c++11 -Wall -Wno-switch
OBJS = main.o list.o int.o float.o str.o func.o set.o none.o bool.o dict.o

run: debug
	./debug

debug: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

release: CXXFLAGS += -Ofast -flto -DNDEBUG
release: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	- rm debug release *.o *.gcno *.gcda *.gcov
