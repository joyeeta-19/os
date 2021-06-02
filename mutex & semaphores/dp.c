#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define LEFT i
#define RIGHT (i+1) %5


int philosoph[]={0,1,2,3,4};

pthread_mutex_t forks[5];


void think(int i){
	
	printf("%d. is thinking\n",i);
	sleep((rand()%3)+1);
	
	}

void pickup_forks(int i){
	
	pthread_mutex_lock(&forks[RIGHT]);
	pthread_mutex_lock(&forks[LEFT]);
	
	
	}
	
void  eat(int i){
	
	printf("%d is eating\n",i);
	sleep((rand()%3)+1);
	}
	
void putdown_forks(int i){
		
		pthread_mutex_unlock(&forks[RIGHT]);
		pthread_mutex_unlock(&forks[LEFT]);
	
		
		}
	
void *philo(void *a){  
	
	int *i=(int*)a;
	while(1){
		think(*i);
		pickup_forks(*i);
		eat(*i);
		putdown_forks(*i);
		}	
	}

int main(){
	
	pthread_t philos[5];
	
	
	for(int i=0;i<5;i++){
		pthread_mutex_init(&forks[i],NULL);
		}
 
	
	for (int j=0;j<5;j++){
		
		pthread_create(&philos[j] , NULL, philo,&philosoph[j]);
		
		}
	
	for(int k=0;k<5;k++){
		
		pthread_join(philos[k],NULL);
		
		}
	
	return 0;
	}
