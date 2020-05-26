#include "stdafx.h"

int charCount(FILE *f);
int wordCount(FILE *f);

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc <= 2)
	{
		printf("缺少参数!\n");
		exit(0);
	}

	if ((fp = fopen(argv[2], "rb")) == NULL)
	{
		printf("不能打开此文件!\n");
	
	}
	else
	{
	
		if (*(argv[1]+1)== 'c')
		{
			printf("有%d个字符", charCount(fp));
		}
		else if(*(argv[1]+1)== 'w')
		{
			printf("有%d个单词", wordCount(fp));
		}
		else
		{
			fclose(fp);
			printf("参数错误\n");
			exit(0);
		}
		fclose(fp);

	}
	return 0;
}
int charCount(FILE *f)
{
	char c;
	int count = 0;
	while (!feof(f))
	{
		fread(&c, 1, 1, f);
		if (c == ' ' || c == '\t' || c == '\n')
			count++;
	}
	return count;
}
int wordCount(FILE *f)
{
	char c,temp;
	int count = 0;
	fread(&c, 1, 1, f);
	while (!feof(f))
	{
		
        temp=c;		
		fread(&c, 1, 1, f);
	
		if (c == ' ' ||c == ','||c=='\n') {
			
			if (temp != ' ' &&temp != ','&&temp!='\n')
				count++;
		}
	}
	return count + 1;
}

