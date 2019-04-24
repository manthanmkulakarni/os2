#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
int pid=fork();
if(pid<0) printf("Error\n");
else if(pid==0) 
{
execl("./files","processcalled",(char*)NULL);
}

else { wait();printf("Parent process %d\n",pid); }

return 0;
}
