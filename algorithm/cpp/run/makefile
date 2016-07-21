# set source file name to make it built and run
#src:=../binary_search.cpp
src:=../heap_sort.cpp
#src:=../quick_sort.cpp

all:clean

bin:$(src)
	@g++ -o $@ $^

test:bin
	@./bin

clean:test
	@rm -rf bin
