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
	/* get char from file */
	ch = fgetc(fp);
	if (ch != EOF) {
		printf("ch = %c\n", ch);
	}
	fclose(fp);
	return 0;
}
