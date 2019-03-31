#include <stdio.h>
#define N 64

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[N];
	
	fp = fopen("test.txt", "w");
	if (!fp) {
		perror("fopen error");
		return -1;
	}
	
	while (fgets(buf, N, stdin) != NULL) {
		fputs(buf, fp);
		fflush(fp); /* flush fp buffer */
	}
	
	fclose(fp);
	return 0;
}
