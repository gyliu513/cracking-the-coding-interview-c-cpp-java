#include <stdio.h>
#include <pthread.h>
void printOdd(void *max){
	int limit;
	int i = 1;
	limit = (int)max;
	while(i <= limit){
		printf("%d\n",i);
		i = i+2;
		sched_yield();
	}
}

void printEven(void * max){
	int limit;
	int i = 0;
	limit = (int)max;
	while(i <= limit){
		printf("%d\n",i);
		i = i+2;
		sched_yield();
	}

}

int main(){
	int limit;
	printf("Enter the maximum value till which you would like to print\n");
	scanf("%d",&limit);
	printf("\nPrinting\n");
	pthread_t evenThread, oddThread;
	pthread_create(&evenThread, NULL, printEven, (void *)limit);
	pthread_create(&oddThread, NULL, printOdd, (void *)limit);
	pthread_join(evenThread, NULL);
	pthread_join(oddThread, NULL);
	return 0;
}
