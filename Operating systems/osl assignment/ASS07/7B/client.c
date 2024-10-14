#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <sys/shm.h>
#include "shm_com.h"
int main()
{
	void *shared_memory = (void *)0;
	struct shared_m *shared_stuff;
	int shmid;
	char buffer[2048];
	shmid = shmget((key_t)1234, sizeof(struct shared_m), 0666);
	shared_memory = shmat(shmid, (void *)0, 0);
	shared_stuff = (struct shared_m *)shared_memory;
	shared_stuff->flag = 0;
	while(1)
	{
		if (shared_stuff->flag)
		{
			printf("You wrote: %s", shared_stuff->text);
    		shared_stuff->flag = 0;
			if (strncmp(shared_stuff->text, "end", 3) == 0) 
    			exit(0);
		}
	}

}
