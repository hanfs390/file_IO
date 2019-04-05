#include <stdio.h>
#include <string.h>

#include "head.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	struct test test;
	if((fp = fopen("test.txt", "r")) == NULL){
		perror("fopen error");
		return -1;
	}


	if(fread(&test, sizeof(struct test), 1, fp) > 0){
		printf("num = %d buf = %s\n", test.num, test.buf);
	}
	return 0;
}
