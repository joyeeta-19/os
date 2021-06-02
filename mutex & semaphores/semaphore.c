#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
sem_t mutex; 
void* thread(void* arg) 
{ 
	//wait 
	sem_wait(&mutex); //to block the calling thread until the semaphore count pointed to by sem becomes greater than zero, then atomically decrement the count.
	printf("\nEntered..\n"); 
	
	//critical section 
	sleep(4); 
	
	//signal 
	printf("\nJust Exiting...\n"); 
	sem_post(&mutex);  // atomically increment the semaphore pointed to by mutex.
} 

int main() 
{ 
	//sem_init(sem_t *sem, int pshared, unsigned int value);
	//When pshared is 0, the semaphore can be used by all the threads in this process only.
	//When pshared is nonzero, the semaphore can be shared by other processes.
	// sem_init() returns zero after completing successfully. Any other return value indicates that an error occurred.
	sem_init(&mutex, 0, 2);  /*If the value of pshared is zero, then the semaphore cannot be shared between processes. 
	If the value of pshared is nonzero, then the semaphore can be shared between processes.*/
	//sem init arguments -> mutex, pshared, count for counnting semaphore
	
	pthread_t t1,t2; 
	pthread_create(&t1,NULL,thread,NULL); 
	sleep(2); 
	pthread_create(&t2,NULL,thread,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&mutex); 
	return 0; 
} 

