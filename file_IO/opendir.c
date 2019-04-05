#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dp;
	struct stat buf;
	if((dir = opendir(".")) == NULL){
		perror("opendir error");
		return -1;
	}

	while((dp = readdir(dir)) != NULL){
		//除去隐藏文件
		if(dp->d_name[0] == '.')
			continue;
		printf("%s\n", dp->d_name);

		//获取文件的属性
		if(stat(dp->d_name, &buf) == 0){
			printf("inode = %d nlink = %d uid = %d gid = %d size = %d\n",
					(int)buf.st_ino, buf.st_nlink, buf.st_uid, buf.st_gid, (int)buf.st_size);
		}
	}
	return 0;
}
