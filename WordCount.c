#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char** argv)
{
	int count=0;//������ 
	char words[1000];//�洢�ַ� 
	int i=0;
	int n;
	int flag=0;//�����������ж� 
	FILE *fp;
	char ch;//������ļ��ж�ȡ���ַ� 
	if(argc!=3)//�ж��Ƿ���ȷ���� 
	{
			printf("Error Input!!\n");
			return -1;
	}	
	else
		{
			//��ȡ�ļ����㵥�� 
			if(strcmp(argv[1],"-w")==0)
			{
				if((fp=fopen(argv[2],"r"))==NULL)
				{ 
					printf("��ȡ�ļ�ʧ�ܣ���\n");
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
				 words[i]=0;//��ʶ���� 
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
				printf("��%s��ͳ�Ƶ���\n",argv[2]);
				printf("\t��������Ϊ:%d\n",count);
				
			}	
			//��ȡ�ļ������ַ�	
			else if(strcmp(argv[1],"-c")==0)
			{
				if((fp=fopen(argv[2],"r"))==0)
				{ 
					printf("��ȡ�ļ�ʧ�ܣ���\n");
					return -1; 
				}
				while(ch=fgetc(fp)!=EOF)
					{
						if(ch!='\n'&&ch!='\r')
						count++;				
					}
					
				fclose(fp);
				printf("��%s��ͳ���ַ�\n",argv[2]);
				printf("\t�ַ�����Ϊ��%d\n",count);
			}
			else
				printf("Warning!!\n");
		}
	//printf("������Ĵ��룡\n");
	return 0;
} 
