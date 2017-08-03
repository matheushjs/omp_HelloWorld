all: locvar vecsum

locvar: locvar.cpp
	g++ -Wall -O2 -Wno-unused-result -fopenmp $@.cpp -o $@

vecsum: vecsum.cpp
	g++ -Wall -O2 -Wno-unused-result -fopenmp $@.cpp -o $@

clean:
	rm -vf *~
