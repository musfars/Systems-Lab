
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t count;
sem_t bufferAccess;


int readCount=0;int c=0;

void *Reader(void * args);

void *Writer(void *args);


int main() {
	
	int i=0;
	int ReaderThreads=0;
	int WriterThreads=0;

	sem_init(&count , 0,1);
	sem_init(&bufferAccess,0,1);
	
	pthread_t Readers[100], Writers[100];
	printf("\n Enter the number of Readers required");
	scanf("%d", &ReaderThreads);
	printf("\n Enter the number of Writers required");
	scanf("%d", &WriterThreads);
	
	for(i=0;i<ReaderThreads;i++)
		pthread_create(&Readers[i],NULL,Reader,(void *)i);
	for(i=0;i<WriterThreads;i++) 	
		pthread_create(&Writers[i],NULL,Writer,(void *)i);

	//joining threads
	
	for(i=0;i<ReaderThreads;i++)
		pthread_join(Readers[i],NULL);
	for(i=0;i<WriterThreads;i++)
		pthread_join(Writers[i],NULL);

	sem_destroy(&bufferAccess);
	sem_destroy(&count);

	return 0;


	}

void *Writer(void * args)
	{
		sleep(1);
		int temp =(int) args;
		printf("\n Writer %d is entering buffer ",temp);
		sem_wait(&bufferAccess);
	printf("\n Writer %d is writing to buffer",temp);
//		readCount++;
		printf("\n Writer %d is leaving buffer",temp);
		sem_post(&bufferAccess);
	}

void *Reader (void *args)	
{
	
	int temp =(int ) args;
	printf("\n Reader %d is entering buffer",temp);
	

	sem_wait(&count);
	
	readCount++;
	
	if(readCount==1)
	{ sem_wait(&bufferAccess);
	  
	  
	 }
    printf("\nReader %d is reading buffer%d",temp,readCount);
	sem_post(&count);sleep(1);
	sem_wait(&count);
	printf("\n Reader %d is leaving buffer",temp);
	readCount --;
	
	if(readCount==0) 
	{
		
		sem_post(&bufferAccess);
	}
	
	sem_post(&count);
}



	


