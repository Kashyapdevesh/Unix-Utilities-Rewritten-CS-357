#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>


int main(int argc,char*argv[])
{
	FILE *fp;
	char* buffer;
	size_t len=0;
	
	if(argc==1)
	{
		printf("Incomplete entries\n");
		exit(1);
	}
	else if(argc==2)
	{
		fp=stdin;
		while(getline(&buffer,&len,fp)!=-1)
		{
			if(strstr(buffer,argv[1]))
				printf("%s\n",buffer);
			else
				continue;
		}
		fclose(fp);
	}
	else
	{
		for(int i=2;i<argc;i++)
		{
			fp=fopen(argv[i],"r");
			if(fp==NULL)
			{
			printf("File:%d\n",i-1);
			printf("Error:%s\n\n",strerror(errno));
			continue;
			
			}
			while(getline(&buffer,&len,fp)!=-1)
			{
				if(strstr(buffer,argv[1]))
					printf("%s\n",buffer);
				else
					continue;
			}
			fclose(fp);
			
		}
	}
	return 0;
}
