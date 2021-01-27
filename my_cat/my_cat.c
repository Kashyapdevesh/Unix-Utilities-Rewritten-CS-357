#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp;
	char buffer[521];
	
	for(int i=1;i<argc;i++)
	{
		fp=fopen(argv[i],"r");
		if(fp==NULL)
		{
			printf("Cannot open file\n");
			exit(1);
		}
		while(1)
		{
			if(fgets(buffer,521,fp)!=NULL)
				printf("%s",buffer);
			else
				break;
		}
		fclose(fp);		
		
	}
}
