#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char *arr;
	int i, j;
	long sum, random_result, allocate_memory;
	sum = 0;
	for(i=0; i<30; i++){
		printf("i:%d\n", i);
		for(j=0; j<100; j++){
			arr = malloc(1024*1024);
			random_result = random() % (1024*512);
			arr += random_result;
			sum += 1024*1024 - random_result;
			allocate_memory += 1024*1024;
			free(arr);
		}
		printf("leak: %ld, allocate_memory: %ld\n", sum / 1024 / 1024, 
			allocate_memory / 1024 / 1024);
		sleep(1);
	}
	pause();
	return 0;
}
