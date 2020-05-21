#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char** argv)
{
	int count=0;//计数器 
	char words[1000];//存储字符 
	int i=0;
	int n;
	int flag=0;//单词完整性判断 
	FILE *fp;
	char ch;//保存从文件中读取的字符 
	if(argc!=3)//判断是否正确操作 
	{
			printf("Error Input!!\n");
			return -1;
	}	
	else
		{
			//读取文件计算单词 
			if(strcmp(argv[1],"-w")==0)
			{
				if((fp=fopen(argv[2],"r"))==NULL)
				{ 
					printf("读取文件失败！！\n");
					return -1; 
				}
				 while(!feof(fp))
				 {
				 	ch=fgetc(fp);
				 	if(ch!=EOF)
				 	{
				 		words[i]=ch;
				 		i++; 
					 }
				 
				 }
				 words[i]=0;//标识结束 
				fclose(fp);
			
				for(n=0;n<i+1;n++)
				{
					if(words[n]!=' '&&words[n]!=',')
						flag=1;
					if(words[n]==' '||words[n]==',')
					{
						count+=flag;
						flag=0;
					}
				} 
				count+=flag;
				printf("从%s中统计单词\n",argv[2]);
				printf("\t单词数量为:%d\n",count);
				
			}	
			//读取文件计算字符	
			else if(strcmp(argv[1],"-c")==0)
			{
				if((fp=fopen(argv[2],"r"))==0)
				{ 
					printf("读取文件失败！！\n");
					return -1; 
				}
				while(ch=fgetc(fp)!=EOF)
					{
						if(ch!='\n'&&ch!='\r')
						count++;				
					}
					
				fclose(fp);
				printf("从%s中统计字符\n",argv[2]);
				printf("\t字符数量为：%d\n",count);
			}
			else
				printf("Warning!!\n");
		}
	//printf("刘吉祥的代码！\n");
	return 0;
} 
