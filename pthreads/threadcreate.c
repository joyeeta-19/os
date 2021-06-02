#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//passing value to threads
void* printodd(void *arg){
	//int *iptr = (int *)arg;
	int *iptr = (int *)malloc(sizeof(int));
	*iptr=6;
	for(int i=0;i<8;i++){
		if(i%2!=0){
			sleep(1);
			printf("## thread 1: %d --> %d\n",i,*iptr);
			(*iptr)++;
		}
		//(*iptr)++;
	}
	//sleep(500);
	return iptr;
}
void printeven(){
	for(int i=0;i<8;i++){
		if(i%2==0){
			printf("** thread 2: %d\n",i);
		}
	}
}
int main()
{
	pthread_t newthread;
	//int val = 6;
	int  *res;
	//pthread_create(&newthread, NULL, printodd, &val); //the name of the thread, NULL, function, its argument
	pthread_create(&newthread, NULL, printodd, NULL);
	printeven();
	
	//thread join ->waits until the thread is finished ->allows us to get value from the thread
	pthread_join(newthread, (void *)&res);
	printf("final value is: %d\n",*res);
	return 0;
}
