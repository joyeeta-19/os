#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdint.h>

#define BIG 100000;
int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_to_big(void *arg){
	for(int i=0; i<100000000; i++){
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	} 
	printf("counted %d\n",counter);
	return NULL;
}
int main(){
	
	pthread_t t;
	pthread_create(&t,NULL,count_to_big,NULL);
	count_to_big(NULL);
	//count_to_big();
	pthread_join(t,NULL);
	printf("Done, counter = %d\n",counter);
}
