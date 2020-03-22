s:
	oj s main.cpp --guess-cxx-latest --guess-cxx-compiler gcc

t: a.out test
	oj t

r: a.out
	./a.out

a.out: main.cpp
	g++ -std=c++14 -Wall --pedantic-errors main.cpp

.PHONY : s t r
