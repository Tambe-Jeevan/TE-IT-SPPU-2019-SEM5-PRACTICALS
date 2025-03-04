#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<semaphore.h>
void * reader(int *) ;
void * writer (int *) ;
sem_t wsem,mutex ;
int readcount=0 ;
 void main()
{
 int a=1,b=1;
 system("clear");
 sem_init(&wsem,0,1) ;
 sem_init(&mutex,0,1) ;
 pthread_t r,w,r1,w1 ;
 pthread_create(&r,NULL,reader,(void *)a);
 a++;
 pthread_create(&w1,NULL,writer,(void *)b);
 b++;
 pthread_create(&r1,NULL,reader,(void *)a);
 pthread_create(&w,NULL,writer,(void *)b);
 pthread_join(r,NULL);
 pthread_join(w1,NULL);
 pthread_join(r1,NULL);
 pthread_join(w,NULL) ;
 printf("main terminated\n");
}
void * reader(int * arg)
{
 int * c=(int)arg ;
 printf("\nreader %d is created",c);
 sleep(1);
 sem_wait(&mutex) ;
 readcount++;
 if(readcount==1)
 sem_wait(&wsem) ;
 sem_post(&mutex) ;
/*Critcal Section */
 printf("\n\nreader %d is reading\n ",c);
 sleep(1) ;
 printf("\nreader%d finished reading\n",c);
/* critical section completd */
 sem_wait(&mutex) ;
 readcount-- ;
 if(readcount==0)
 sem_post(&wsem) ;
 sem_post(&mutex) ;
}
void * writer (int * arg)
{
 int * c=(int)arg ;
 printf("\nwriter %d is created",c);
 sleep(1);
 sem_wait(&wsem) ;
 printf("\nwriter %d is writing\n",c) ;
 sleep(1);
 printf("\nwriter%d finished writing\n",c);
 sem_post(&wsem) ;
 getch();
}
