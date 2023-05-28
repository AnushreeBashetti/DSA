#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100
void print_array(int a[size],int n);
void bubblesort(int a[size],int n);
void selectionsort(int a[size],int n);
void insertionsort(int a[size],int n);
void timereq(int a[size],int n);
int main()
{
    int a[size],n,rnum;
    int first,last;
    FILE *fp,*fp1,*fp2;
    fp=fopen("input.txt","w");
    //fp1=fopen("output.txt","w");
    //fp2=fopen("log.txt","a");
    if(fp==NULL)
    {
        printf("file not created");
        exit(0);
    }
    if(fp1==NULL)
    {
        printf("file not created");
        exit(0);
    }
    if(fp2==NULL)
    {
        printf("file not created");
        exit(0);
    }

    printf("Enter the lower and upper limit\n");
    scanf("%d%d",&first,&last);
    printf("Enter number of random numbers to be generated\n ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%(last+1-first)+first;
        fprintf(fp,"%d\t",a[i]);

    }
    fclose(fp);
    print_array(a,n);
    timereq(a,n);
    return 0;
}

void print_array(int a[size],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void bubblesort(int a[size],int n)
{
    FILE *fp1;
    fp1=fopen("output.txt","w");
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
   }
  }
  }
  printf("\nAfter bubble sorting we get\n");
  for(i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    fprintf(fp1,"%d ",a[i]);
    }
    fclose(fp1);
}

void selectionsort(int a[size],int n)
{
   int indexofmin,temp,i,j;
   for(int i=0;i<n;i++)
   {
       for(j=i+1;j<n-i-1;j++)
       {
       indexofmin=i;

       {
           if(a[j]<a[indexofmin])
           {
               indexofmin=j;
           }
       }
       temp=a[i];
       a[i]=a[indexofmin];
       a[indexofmin]=temp;
   }
   }
   printf("\nAfter selection sorting we get\n");
   for(i=0;i<n;i++)
   {
       printf("%d ",a[i]);
   }
}

void insertionsort(int a[size],int n)
{
    int key,i,j;
    for(i=1;i<n;i++)
    {
       j=i-1;
       key=a[i];
       while(j>=0 && a[j]<key )
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=key;
    }
    printf("\nAfter insertion sorting we get\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}

void timereq(int a[size],int n)
{
    FILE *fp2;
    fp2=fopen("log.txt","a");
    float duration;
    clock_t start,end;
    start=clock();
    bubblesort(a,n);

    end=clock();
    duration=(float)(end-start);
    fprintf(fp2,"\nduration for bubble sort %f\n",duration);
    start=clock();
    selectionsort(a,n);
    end=clock();
    duration=(float)(end-start);
    fprintf(fp2,"\nduration is for selection sort %f\n",duration);
    insertionsort(a,n);
    end=clock();
    duration=(float)(end-start);
    fprintf(fp2,"\nduration is for insertion sort %f\n",duration);
    print_array(a,n);
    fclose(fp2);
}

