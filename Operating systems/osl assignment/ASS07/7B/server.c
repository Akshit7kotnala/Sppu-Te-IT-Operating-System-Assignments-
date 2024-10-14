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
	char buffer[2048];
	int shmid;
	shmid = shmget((key_t)1234, sizeof(struct shared_m), 0666 | IPC_CREAT);
	shared_memory = shmat(shmid, (void *)0, 0);
	shared_stuff = (struct shared_m *)shared_memory;
	while(1) 
	{
		while(shared_stuff->flag == 1) { sleep(1); }
		printf("Enter some text: ");
		fgets(buffer, 2048, stdin);
		strncpy(shared_stuff->text, buffer, 2048);
		shared_stuff->flag = 1;
		if (strncmp(buffer, "end", 3) == 0) exit(0);
	}
}
