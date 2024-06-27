#include <sys/types.h>


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 27
int main()
{
char c;
int shmid;
key_t key;
char *shm, *s;
key = 5678;
// get identifier for shared memory
if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
{
perror("shmget");
exit(1);
}
// attach shared memory
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
{
perror("shmat");
exit(1);
}
s = shm;
printf("\n Enter data to put in shared memory:");
while((c=getchar())!='#')
*s++ = c;
// detach shared memory
sleep(2);
shmdt(s);
exit(0);
}
