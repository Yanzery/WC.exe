#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main(int argc, char * argv[])
{
    int wc_char = 0;
    int wc_word = 1;
    int wc_line = 1;
    char filename[80];
    FILE *fp = NULL;
    if (argc == 1)
    {
        printf("missing file name:\nPlease input file name:");
        gets(filename);
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
            printf("打开有误！\n");
            printf("请按enter键继续....");
            _getch();
            exit(0);
            //...
        }
        printf("This is the file :\n");
        while (1)
        {
            char ch;
            ch = fgetc(fp);
            if (ch >= 'A'&&ch <= 'z')
            {
                putchar(ch);
                wc_char++;
            }
            else if (ch == ' ')
            {
                putchar(ch);
                wc_word++;
            }
            else if (ch == '\n')
            {
                putchar(ch);
                wc_word++;
                wc_line++;
            }
            else if (ch = EOF)
            {
                break;
            }
        }
        printf("The char count is %d\n", wc_char);
        printf("The word count is %d\n", wc_word);
        printf("The line count is %d\n", wc_line);
        fclose(fp);
        _getch();
        exit(0);
    }
    else if (argc == 2)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("打开有误！\n");
            printf("请按enter键继续....");
            _getch();
            exit(0);
            //...
        }
        while (1)
        {
            char ch;
            ch = fgetc(fp);
            if (ch >= 'A'&&ch <= 'z')
            {
                wc_char++;
            }
            else if (ch == ' ')
            {
                wc_word++;
            }
            else if (ch == '\n')
            {
                wc_word++;
                wc_line++;
            }
            else if (ch = EOF)
            {
                break;
            }
        }
        printf("文件打成功!\n请输入统计方式如(-c\-w\-l):");
        gets(filename);
        if (strcmp(filename, "-c") == 0)
        {
            printf("The char count is %d\n", wc_char);
        }
        else if (strcmp(filename, "-w") == 0)
        {
            printf("The word count is %d\n", wc_word);
        }
        else if (strcmp(filename, "-l") == 0)
        {
            printf("The line count is %d\n", wc_line);
        }
    }
    else if (argc == 3)
    {
        fp = fopen(argv[2], "r");
        if (fp == NULL)
        {
            printf("打开有误！\n");
            printf("请按enter键继续....");
            _getch();
            exit(0);
            //...
        }
        while (1)
        {
            char ch;
            ch = fgetc(fp);
            if (ch >= 'A'&&ch <= 'z')
            {
                wc_char++;
            }
            else if (ch == ' ')
            {
                wc_word++;
            }
            else if (ch == '\n')
            {
                wc_word++;
                wc_line++;
            }
            else if (ch = EOF)
            {
                break;
            }
        }
        if (strcmp(argv[1],"-c")==0)
        {
            printf("The char count is %d\n", wc_char);
        }
        else if (strcmp(argv[1],"-w")==0)
        {
            printf("The word count is %d\n", wc_word);
        }
        else if (strcmp(argv[1],"-l")==0)
        {
            printf("The line count is %d\n", wc_line);
        }
        fclose(fp);
    }
}
