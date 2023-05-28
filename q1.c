#include<stdio.h>
#include<stdlib.h>

int stringlength(char a[100])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}

void main()
{
    FILE *p;
    char str[100][100];
    int i,j,n,a,longest;
    printf("Enter number of lines");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
       p=fopen("file1","r");
    }
    a=stringlength(str[0]);
    longest=a;
    for(i=1;i<=n;i++)
    {
        a=stringlength(str[i]);
        if(a>longest)
        {
            longest=a;
            j=i;
        }
    }
    printf(" The longest line is: ");
    puts(str[j]);
}
