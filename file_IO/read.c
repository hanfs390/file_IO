#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define N 128
int main(int argc, char *argv[])
{
	int fd;
	char buf[N] = "";
	ssize_t nbyte;
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror("open error");
		return -1;
	}


	if((nbyte = read(fd, buf, N)) > 0){
		printf("nbyte = %d\n", nbyte);
		printf("buf = %s\n", buf);
	}
	return 0;
}
