#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
int main()
{
    int l,u,n,num,i;
    FILE *fp;
    printf("\nenter range lower and upper:");
    scanf("%d%d",&l,&u);
    printf("\nenter count:");
    scanf("%d",&n);
    fp=fopen("inp.txt","w");
    if(fp==NULL)
    {
        printf("\nerror");
        exit(0);
    }
   // srand(time(0));
    printf("\nThe random numbers are: ");
    for(i=0;i<n;i++)
    {
        num=(rand() % (u-l+1))+l;
        printf("\n%d",num);
        fprintf(fp,"%d\t",num);
    }
    printf("\n\nNumbers have been printed in file successfully\n");
    fclose(fp);
}
