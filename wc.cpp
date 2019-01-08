#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <iostream>
using namespace std;
const int maxlen_filename=80;

struct Twc
{
	int character,word,line;
	int null_line,annotation_line,code_line;
	Twc() { character=word=line=null_line=annotation_line=code_line=0;}
}; 

struct Topt
{
	bool s,c,w,l,a;
	Topt() { s=c=w=l=a=false;}
};

bool is_character(char ch)
{
	if (ch>='a' && ch<='z') return true;
	if (ch>='A' && ch<='Z') return true;
	if (ch>='0' && ch<='9') return true;
	return false;
}



Twc calc(char* filename)
{
	Twc res;
	FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
   	  printf("������\n");
    	printf("�밴enter������....");
    	_getch();
    	exit(0);
    }
    char ch,lastch;
    lastch=0;
    int char_num=0;
    int bufsize=105;
    char st[bufsize];
           
    while(!feof(fp))                       
    {
    	//�����ļ���ÿһ�У�ͳ���������ַ����ʹ���
    	fgets(st,bufsize,fp);
    	res.line++;
    	int len=strlen(st);    	

    	for (int i=0;i<len;i++)
    	{
    		if (is_character(st[i]))
    		{
    			res.character++;
				if  ( i==0 || !is_character(st[i-1]) ) 
    				res.word++;    		
    		}
    	}
    	
    	// ����������е��ж� 
    	int show_char=0; 
    	for (int i=0;i<len;i++)
    	{
    		if (st[i]!=' ' && st[i]!='\n' && st[i]!='\t')
    			show_char++;
    	}
    	if (show_char>1) res.code_line++;
    	else res.null_line++;
    	
    	// ע���е��ж�
    	bool is_annotation_line=false;
    	show_char=0;
    	for (int i=0;i<len;i++)
    	{
    		if ((st[i]!=' ') && st[i]!='\n' && st[i]!='\t')
    		{
    			show_char++;
    			if (st[i]=='/')
    			{
    				if (i+1<len && st[i+1]=='/')
    					is_annotation_line=true;
    				break;
    			}
    			if (show_char>1) break;
    		}
    	}
    	if (is_annotation_line==true) res.annotation_line++;	
    }
    
    return res;
}

void work(char* filename,Topt now)
{
	Twc ans=calc(filename);
	if (now.c==true)
	{
	    printf("The number of characters is %d\n", ans.character);
	}
	if (now.w==true)
	{
	    printf("The number of words is %d\n", ans.word);
	}
	if (now.l==true)
    {
	    printf("The number of lines is %d\n", ans.line);
	}
	if (now.a==true)
	{
	    printf("The number of null line is %d\n", ans.null_line);
	    printf("The number of annotation line is %d\n", ans.annotation_line);
	    printf("The number of code line is %d\n", ans.code_line);
	}

}


//�ݹ鴦��Ŀ¼�·����������ļ� 
void listFiles(string dir,Topt nowopt)
{
	intptr_t handle;
	_finddata_t findData;
 
	handle = _findfirst((dir+"\\*.*").c_str(), &findData);    // ����Ŀ¼�еĵ�һ���ļ�
	if (handle == -1)
	{
		cout << "Failed to find first file!\n";
		return;
	}
 
	do
	{
		string nextdir=dir+'/'+string(findData.name);
		if (strcmp(findData.name, ".") == 0) continue;
		if (strcmp(findData.name, "..") == 0) continue;
		if (findData.attrib & _A_SUBDIR )
		{   
			    listFiles(nextdir,nowopt);
		}
		else 
		{
			printf("the file is %s\n",(nextdir).c_str());
			int len=nextdir.size();
			char filename[len+1];
			nextdir.copy(filename, len, 0);//����5�����Ƽ����ַ���0�����Ƶ�λ�ã�
			filename[len]='\0';
			work(filename,nowopt);
			printf("-------------\n");
		}
	} while (_findnext(handle, &findData) == 0);    // ����Ŀ¼�е���һ���ļ�

	_findclose(handle);    // �ر��������

}

int main(int argc, char * argv[])
{
    char filename[maxlen_filename];
    FILE *fp = NULL;
    strcpy(filename,argv[argc-1]);
    Topt nowopt;
	for (int i=0;i<argc-1;i++)
	{
		if (strcmp(argv[i], "-s") == 0)
    	{
        	nowopt.s=true;
    	}
    	if (strcmp(argv[i], "-c") == 0)
    	{
        	nowopt.c=true;
    	}
    	if (strcmp(argv[i], "-w") == 0)
    	{
        	nowopt.w=true;
    	}
    	if (strcmp(argv[i], "-l") == 0)
    	{
        	nowopt.l=true;
    	}
    	if (strcmp(argv[i], "-a") == 0)
    	{
        	nowopt.a=true;
    	}
	}
	nowopt.s=true;
	if (nowopt.s==true)
	{
		listFiles(string(filename),nowopt);
	}
	else
	{
		work(filename,nowopt);
	}
	
	return 0;
}

