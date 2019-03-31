#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;

	fp = fopen("test.txt", "w");
	if (!fp) {
		perror("fopen error");
		return -1;
	}
	/* put string from file */
	if (fputs("hello world", fp) == EOF) {
		perror("fputs error");
	}
	fclose(fp);
	return 0;
}
