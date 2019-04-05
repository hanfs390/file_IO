#include <stdio.h>
#include <string.h>

#define N 128
struct test{
	int num;
	char buf[N];
};
int main(int argc, char *argv[])
{
	FILE *fp;
	struct test test;
	if((fp = fopen("test.txt", "w")) == NULL){
		perror("fopen error");
		return -1;
	}

	test.num = 10;
	strcpy(test.buf, "hello");

	if(fwrite(&test, sizeof(struct test), 1, fp) < 0){
		perror("fwrite error");
		return -1;
	}
	return 0;
}
