#include <stdio.h>
#include <string.h>
#define N 64

int get_line(FILE *fp)
{
	char buf[N];
	int count = 0;
	while (fgets(buf, N, fp) != NULL) {
		if (buf[strlen(buf) - 1] == '\n') {
			printf("%s", buf);
			count++;
		}
	}
	return count;

}
int main(int argc, char *argv[])
{
	FILE *fp;
	int line;
	
	fp = fopen("test.txt", "r");
	if (!fp) {
		perror("fopen error");
		return -1;
	}
	line = get_line(fp);
	printf("the line count %d\n", line);

	fclose(fp);
	return 0;
}
