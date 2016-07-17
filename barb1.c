#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,chair,waitingcustomer;
int emptychairs,nochair,countc=1;

void *customer(void *args)
{
	sem_wait(&mutex);
	if(emptychairs==00)
	{
		printf("\nWaiting room is full...Customer is leaving\n");			countc++;
		return;
	}
	}
	sem_wait(&chair);
	sem_wait(&mutex);
	emptychairs--;
	printf("\nCustomer %d enters waiting room\n",countc);
	countc++;
	sem_post(&mutex);
	sem_post(&waitingcustomer);
}

void *barber(void *args)
{
	int countb=1;
	while(1)
	{
		sem_wait(&waitingcustomer);
		sem_wait(&mutex);
		emptychairs++;
		printf("\nBarber serves customer %d\n",countb);
		countb++;
		sleep(1);
		sem_post(&mutex);
		sem_post(&chair);
		if(emptychairs==nochair)
			printf("\nBarber starts sleeping\n");
	}
}

int main()
{
	int i=0,nocust;
	pthread_t Customers[100],Barber;
	
	printf("\nEnter the number of chairs in the waiting room: ");
	scanf("%d",&nochair);
	printf("\nEnter the number of customers required: ");
	scanf("%d",&nocust);
	emptychairs=nochair;
	
	sem_init(&mutex,0,1);
	sem_init(&chair,0,nochair);
	sem_init(&waitingcustomer,0,0);
	
	pthread_create(&Barber,NULL,barber,(void *)i);
	for(i=1;i<=nocust;i++)
		pthread_create(&Customers[i],NULL,customer,(void *)i);
	
	pthread_join(Barber,NULL);
	for(i=1;i<=nocust;i++)
		pthread_join(Customers[i],NULL);

	return 0;
}

