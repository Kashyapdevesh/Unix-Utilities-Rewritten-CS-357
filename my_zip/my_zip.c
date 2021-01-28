#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc,char*argv[])
{
	FILE *fp;
	FILE *ofp;
	char* buffer;
	size_t len=0;
	
	if(argc==1)
	{
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}
	else if(argc==2)
	{
		fp=fopen(argv[1],"r");
		if(fp==NULL)
		{
			printf("Error:%s\n\n",strerror(errno));
			exit(1);
		}
		while(getline(&buffer,&len,fp)!=-1)
		{
			int count=1;
			for(int i=1;i<len;i++)
			{
				if(buffer[i]==10)
					break;
				if(buffer[i]==buffer[i+1])
					count++;
				else
					printf("%d%c",count,buffer[i]);
			}
		}
		fclose(fp);
	}
	else 
	{
		fp=fopen(argv[1],"r");
		ofp=fopen(argv[2],"w");
		if(fp==NULL||ofp==NULL)
		{
			printf("Error:%s\n\n",strerror(errno));
			exit(1);
		}
		while(getline(&buffer,&len,fp)!=-1)
		{
			int count=1;
			for(int i=1;i<len;i++)
			{
				if(buffer[i]==10)
					break;
				if(buffer[i]==buffer[i+1])
					count++;
				else
					fprintf(ofp,"%d%c",count,buffer[i]);
			}
		}
		fclose(fp);
		fclose(ofp);
	}
	return 0;
}
