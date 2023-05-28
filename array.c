#include<stdio.h>
int search(int a[], int n)
{
    int i,j,count;
    for(i=0;i<n;i++)
    {
         if (a[i] == -1)
            continue;
        count=1;
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
                a[j] = -1;
            }
        }
         printf("\n%d has occurred %d times\n",a[i],count);
    }
    return count;
}
int main()
{
    int n,i,a[25],z;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
   z= search(a,n);

    return 0;
}
