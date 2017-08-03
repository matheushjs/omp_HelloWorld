all: locvar

locvar:
	g++ -Wall -O2 -Wno-unused-result -fopenmp $@.cpp -o $@

clean:
	rm -vf *~
