#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int lengs(char a[]);
void main()
{
    char str[100][100];
    int k[100];
    char strd[100];
    int i,j,b,L;
    for(i=0;i<10;i++)
    {
        gets(str[i]);
    }
    printf(" enter pattern: ");
    scanf("%s",strd);

    i=0;
    for(i=0;i<10;i++)
    {
        j=0;
        b=0;
    while(str[i][j]!='\0')
    {
        if(str[i][j]!=strd[b])
        {
            j++;
        }
        else
        {
                    j++;
            b++;
           while(strd[b]!='\0')
           {
               if(str[i][j]!=strd[b])
               {
                   j++;
                   b=0;
                   break;
               }
               else
               {
                   j++;
                   b++;
               }
           }
           if(strd[b]=='\0')
           {
               puts(str[i]);
           }
        }
    }
    }
}

