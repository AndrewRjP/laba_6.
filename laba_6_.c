#include <stdio.h>
#include <string.h>
#define MAXLINE 255

int isIdentificator(char *s)
{
    int res = 1;
    if(!(s[0]=='_'||(s[0]>=65&&s[0]<=90)||(s[0]>=97&&s[0]<=122))) res = 0;
    for(int i = 1; i < strlen(s); i++)
        if(!(s[i]=='_'||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||(s[i]>=30&&s[i]<=39))) res = 0;  
    return res; 
}

int convert(char *s, char *res)
{
    const char* limits = " \0";
    int empty = 1;
    char* ptr = strtok(s, limits);
    if(isIdentificator(ptr)) 
    {
        strcpy(res, ptr);
        empty = 0;
    }
    while(ptr)
    {
        ptr = strtok(NULL, limits);
        if(!ptr) break;
        if(isIdentificator(ptr))
        {
            if(empty)
            {
                strcpy(res, ptr);
                empty = 0;
            }
            else
            {
                strcat(res, " ");
                strcat(res, ptr);
            }
        }
    }
    strcat(res, "\0");
    return empty;
}

int main(void)
{
    char str[MAXLINE], res[MAXLINE];
    printf("Enter string:\n");
    fgets(str, MAXLINE, stdin);
    str[strlen(str)-1] = '\0';
    if(convert(str, res))
        printf("Result string is empty!\n");
    else    
    printf("Result:\n%s\n", res);
  
    return 0;
}
