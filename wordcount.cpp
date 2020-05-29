#include<stdio.h>
#include<stdlib.h>

int charCount(FILE *f);
int wordCount(FILE *f);

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc <= 2)
	{
		printf("ȱ�ٲ���!\n");
		exit(0);
	}

	if ((fp = fopen(argv[2], "rb")) == NULL)
	{
		printf("���ܴ򿪴��ļ�!\n");
	
	}
	else
	{
	
		if (*(argv[1]+1)== 'c')
		{
			printf("��%d���ַ�", charCount(fp));
		}
		else if(*(argv[1]+1)== 'w')
		{
			printf("��%d������", wordCount(fp));
		}
		else
		{
			fclose(fp);
			printf("��������\n");
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

