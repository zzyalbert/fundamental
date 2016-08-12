src:=BinarySearch

all:clean

bin:../$(src).java
	@javac -d . $^

test:bin
	@java $(src)

clean:test
	@rm -rf $(src).class
