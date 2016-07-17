#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

pthread_mutex_t lock,agent,tobs,paps,mats;int i;
void * age()
{while(1)
	{ pthread_mutex_lock(&lock);
	i=rand()%3;
	if(i==0)
	{printf("Agent puts tobacco on the table\n");
	printf("Agent puts paper on the table\n");
	sleep(1);
	pthread_mutex_unlock(&mats);
	}
	else if(i==1)
	{printf("Agent puts tobacco on the table\n");
	printf("Agent puts match on the table\n");
	sleep(1);
	pthread_mutex_unlock(&paps);
	}
	else{
	printf("Agent puts paper on the table\n");
	printf("Agent puts match on the table\n");
	sleep(1);
	pthread_mutex_unlock(&tobs);
	}
	pthread_mutex_unlock(&lock);
	pthread_mutex_lock(&agent);

	}

}
void * tob()
{while(1)
	{pthread_mutex_lock(&tobs);
	pthread_mutex_lock(&lock);
	printf("tobacco smoker picks up match\n");
	printf("tobacco smoker picks up paper\n");
	sleep(1);
	pthread_mutex_unlock(&agent);
	pthread_mutex_unlock(&lock);
	//pthread_mutex_unlock(&lock);
	printf("tobacco smoker starts smoking\n tobacco smoker ends smoking\n");
	}
}
	
void * mat()
{while(1)
	{pthread_mutex_lock(&mats);
	pthread_mutex_lock(&lock);
	printf("match smoker picks up tobacco\n");
	printf("match smoker picks up paper\n");
	sleep(1);
	pthread_mutex_unlock(&agent);
	pthread_mutex_unlock(&lock);
	//pthread_mutex_unlock(&lock);
	printf("match smoker starts smoking\n match smoker ends smoking\n");
	}
}
void * pap()
{while(1)
	{pthread_mutex_lock(&paps);
	pthread_mutex_lock(&lock);
	printf("paper smoker picks up tobacco\n");
	printf("paper smoker picks up match\n");
	sleep(1);
	pthread_mutex_unlock(&agent);
	pthread_mutex_unlock(&lock);
	//pthread_mutex_unlock(&lock);
	printf("paper smoker starts smoking\n paper smoker ends smoking\n");
	}
}	

void main()
{pthread_t tobacco,match,paper,agen;
 pthread_mutex_init(&lock,NULL);
 
 pthread_mutex_init(&mats,NULL);
 pthread_mutex_init(&paps,NULL);
 pthread_mutex_init(&tobs,NULL);
 pthread_mutex_init(&agent,NULL);
// pthread_mutex_init(&lock,agent,tobs,paps,mats,NULL);
pthread_mutex_lock(&mats);
 pthread_mutex_lock(&paps);
 pthread_mutex_lock(&tobs);
 pthread_mutex_lock(&agent);
  
 pthread_create(&agen,0,age,NULL);
 pthread_create(&tobacco,0,tob,NULL);
 pthread_create(&match,0,mat,NULL);
 pthread_create(&paper,0,pap,NULL);
 pthread_join(agen,NULL);
 pthread_join(tobacco,NULL);
 pthread_join(match,NULL);
 pthread_join(paper,NULL);
 //pthread_join(&agen,0);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 

