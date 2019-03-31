#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	long offset;

	fp = fopen("test.txt", "w+");
	if (!fp) {
		perror("fopen error");
		return -1;
	}
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc('d', fp);
	
	offset = ftell(fp);
	printf("offset1 = %ld\n", offset);

	fseek(fp, 1, SEEK_SET);
	
	offset = ftell(fp);
	printf("offset1 = %ld\n", offset);

	while ((ch = fgetc(fp)) != EOF) {
		printf("ch = %c\n", ch);	
	}

	fclose(fp);
	return 0;
}
