#include <stdio.h>
//#define SWITCH 1

int main(int argc, char *argv[])
{
	int ch;

#ifdef SWITCH
	printf("getchar and putchar\n");
	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}
#else
	printf("fgetc and fputc\n");
	while ((ch = fgetc(stdin)) != EOF) {
		fputc(ch, stdout);
	}
#endif
	return 0;
}
