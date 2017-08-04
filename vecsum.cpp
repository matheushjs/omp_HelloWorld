#include <iostream>
#include <cstdlib>

#ifdef _OPENMP
#  include <omp.h>
#endif

using namespace std;

void sumVec(int *one, int *two, int *out, int vecSize){
	int init, step;

#ifdef _OPENMP
	step = omp_get_num_threads();
	init = omp_get_thread_num();
#else
	step = 1;
	init = 0;
#endif
	while(init < vecSize){
		out[init] = one[init] + two[init];
		init += step;
	}
}

int main(int argc, char *argv[]){
	int vecSize, *one, *two, *sum;

	if(argc != 2)
		return 0;

	vecSize = atoi(argv[1]);
	one = (int *) malloc(sizeof(int*) * vecSize);
	two = (int *) malloc(sizeof(int*) * vecSize);
	sum = (int *) malloc(sizeof(int*) * vecSize);

	for(int i = 0; i < vecSize; i++){
		one[i] = i;
		two[i] = -i;
	}

	#pragma omp parallel
	{
	sumVec(one, two, sum, vecSize);
	}
	
	for(int i = 0; i < vecSize; i++){
		cout << sum[i] << " ";
	}
	cout << "\n";

	return 0;
}
