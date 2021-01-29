#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char*argv[])
{
	FILE *fp;
	if(argc==1)
	{
		printf("Enter file name after my_mkdir\n");
		exit(1);
	}
	
		char cwd[PATH_MAX];
		if(getcwd(cwd,sizeof(cwd))==NULL)
			printf("getcwd() error\n");
		else
			for(int i=1;i<argc;i++)
			{
				char filler[1] ="/";
				strncat(cwd,filler,sizeof(filler));
				strncat(cwd,argv[i],sizeof(argv[i]));
				
				if(access(cwd,F_OK)!=-1)
				{
					printf("File already exists\n");
				}
				else
				{
					fp=fopen(argv[i],"w");
					fclose(fp);
				}		
			}
		
	return 0;
}
