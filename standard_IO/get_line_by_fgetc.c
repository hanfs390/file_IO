#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;

	fp = fopen("test.txt", "r");
	if (!fp) {
		perror("fopen error");
		return -1;
	}
	/* get line from file */
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n');
			printf("%c", ch);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
