#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define FIFO_PIPE "xyz"
int main()
{
	int fd, i=0;
	char str[200],ch;
	mkfifo(FIFO_PIPE, 0644);    // Pipe created	
	printf("\n Pipe Successfully created \n");
	printf("\n Enter Your message (press @ to terminate) \n");
	while((ch=fgetc(stdin)) != '@')
	{
		str[i++] = ch;
	}
	str[i]='\0'; // Null character at the end 
	fd=open(FIFO_PIPE,O_WRONLY); // Open the pipe
	write(fd, str, strlen(str)); // write into the pipe
	close(fd);
	return 0;
}
