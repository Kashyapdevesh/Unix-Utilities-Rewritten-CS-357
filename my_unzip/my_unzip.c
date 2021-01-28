#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc,char* argv[])
{
	FILE *fp;
	char *buffer;
	size_t len=0;
	
	if(argc==1)
	{
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}
	else
	{
		fp=fopen(argv[1],"r");
		if(fp==NULL)
		{
		printf("Error:%s\n\n",strerror(errno));
		}
		
		while(getline(&buffer,&len,fp)!=-1)
		{
			for(int i=0;i<len;i++)
			{	
			if(buffer[i]>=97 && buffer[i]<=122)
			{
				int loop=(buffer[i-1]-48);
				for(int j=0;j<loop;j++)
					printf("%c",buffer[i]);
			}
			}
		}
		printf("\n");
		fclose(fp);
	}
}
