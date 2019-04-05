#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define N 128
int get_line(FILE *fp){
	char buf[N] = "";
	int count = 0;

	while(fgets(buf, N, fp) != NULL){
		if(buf[strlen(buf) - 1] == '\n')
			count++;
	}
	return count;
}	
int main(int argc, char *argv[])
{
	FILE *fp;
	int line = 0;
	time_t tm;
	struct tm *tv;
	if((fp = fopen("test.txt", "a+")) == NULL){
		perror("fopen error");
		return -1;
	}

	line = get_line(fp);

	while(1){
		tm = time(&tm);
		tv = localtime(&tm);

		fprintf(fp, "%d  %d-%d-%d  %d:%d:%d\n", 
				++line, tv->tm_year+1900, tv->tm_mon+1, tv->tm_mday, tv->tm_hour, tv->tm_min, tv->tm_sec);

		sleep(1);

		fflush(fp);
	}

	fclose(fp);
	return 0;
}
