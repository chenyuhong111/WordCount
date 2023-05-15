#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    
    FILE *fp;
    int cnt = 0; 
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if (argv[1][1] == 'w') 
    {
        char s[1024];
        int i; 
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++;
            for (i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("������=%d\n", cnt);
    }
    else if (argv[1][1] == 'c') 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("�ַ���=%d", cnt);
    }
    fclose(fp);
    return 0;
}


/*
#include <stdio.h>
#include <string.h>
int main (int n, char *m[])
{
    int num = 0;
    FILE *fn;
    if (m[1][1] == 'c')
    {
        char c;
        while ((c = fgetc(fn)) != EOF) num ++;
        printf("�ַ���%d", num);
    }
    if (m[1][1] == 'w')
    {
        char s[1024];
        int i; 
        while (fscanf(fn, "%s", s) != EOF)
        {
            num ++;
            for (i = 1; i < strlen(s) - 1; i ++)
			{
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    num ++;
       		}
        }
        printf("������: %d\n", num);
    }
    else if ((fn=fopen(m[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    fclose(fn);
    return 0;
}
*/


