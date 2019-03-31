#include <stdio.h>
#define N 64

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[N];
	
	fp = fopen("test.txt", "r");
	if (!fp) {
		perror("fopen error");
		return -1;
	}
	/* get string from file */
	if (fgets(buf, N, fp) != NULL) {
		printf("%s\n", buf);
	}
	fclose(fp);
	return 0;
}
