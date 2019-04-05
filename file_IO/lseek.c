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
	char buf1[N] = "";
	size_t n;
	ssize_t nbyte;
	off_t offset;
	if((fd = open("test.txt", O_RDWR|O_CREAT|O_TRUNC, 0664)) == -1){
		perror("open error");
		return -1;
	}

	while(1){
		fgets(buf, N, stdin);
		buf[strlen(buf) - 1] = '\0';
		n = strlen(buf);

		write(fd, buf, n);

		offset = lseek(fd, 0, SEEK_SET);
		printf("offset = %d\n", (int)offset);

		nbyte = read(fd, buf1, N);
		printf("nbyte = %d\n", nbyte);
		printf("buf1 = %s\n", buf1);

		offset = lseek(fd, 0, SEEK_CUR);
		printf("offset = %d\n", (int)offset);

	}
	return 0;
}
