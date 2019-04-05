#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "head.h"

#define N 128

struct test test = {
	.num = 12,
	.buf = "world",
};
int main(int argc, char *argv[])
{
	int fd;
	if((fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0664)) == -1){
		perror("open error");
		return -1;
	}


	if(write(fd, &test, sizeof(struct test)) == -1){
		perror("write error");
		return -1;
	}
	return 0;
}
