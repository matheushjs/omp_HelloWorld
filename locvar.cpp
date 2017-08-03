#include <omp.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
	int thSize, myRank;

	// myRank and thSize are local.
	#pragma omp parallel private(thSize, myRank)
	{

	myRank = omp_get_thread_num();
	printf("Hello from thread %d.\n", myRank);

	if(myRank == 0){
		thSize = omp_get_num_threads();
		printf("Number of threads = %d\n", thSize);
	}

	} // Join here.

	return 0;
}
