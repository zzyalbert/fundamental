src:=../quick_sort.cpp

all:clean

bin:$(src)
	@g++ -o $@ $^

test:bin
	@./bin

clean:test
	@rm -rf bin
