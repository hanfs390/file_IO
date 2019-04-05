#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define S_IRUGO S_IRUSR|S_IRGRP|S_IROTH
#define MODE S_IRUSR|S_IRGRP|S_IROTH|S_IWUSR|S_IWGRP|S_IWOTH
int main(int argc, char *argv[])
{
	int fd;

	if((fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, MODE)) == -1){
		perror("open error");
		return -1;
	}


	return 0;
}
