#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>

int main()
{
struct dirent *d=NULL;
DIR *dir=NULL;
dir=opendir(".");
d=readdir(dir);
printf("%s",d->d_name);
return 0;
}
