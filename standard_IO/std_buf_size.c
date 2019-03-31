#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;

	fp = fopen("test.txt", "w");
	if (!fp) {
		perror("fopen error");
		return -1;
	}

	/* put 'c' to file */
	if (fputc(99, fp) == EOF) {
		perror("fputc error");
	}
	printf("fp size = %d\n", fp->_IO_buf_end - fp->_IO_buf_base);
	printf("stdin size = %d\n", stdin->_IO_buf_end - stdin->_IO_buf_base);
	printf("stdout size = %d\n", stdout->_IO_buf_end - stdout->_IO_buf_base);
	printf("stderr size = %d\n", stderr->_IO_buf_end - stderr->_IO_buf_base);
	
	fclose(fp);
	return 0;
}
