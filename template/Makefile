s:
	oj s main.cpp --guess-cxx-latest --guess-cxx-compiler gcc

t: a.out test
	oj t

r: a.out
	./a.out

a.out: main.cpp
	g++ -std=c++17 -I /Users/sotetsuk/github/procon/ac-library main.cpp

.PHONY : s t r
