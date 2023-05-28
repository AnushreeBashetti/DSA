#include<stdio.h>
int stack[100],choice,n,i,x,top,num;
void push(int array[100],int c);
void pop(void);
void display(int arra[100]);

int main()
{
    top=-1;
    int choice,num,a[100],c=0;
    FILE *fp,*stk,*inp;
    fp=fopen("inp.txt","a");
    inp=fopen("input.txt","a");

    if(fp==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    printf("\nEnter stacksize:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        //printf("\n%d",num);
        fprintf(inp,"%d\n",a[i]);
    }
    printf("\n1->Push  2->Pop  3->Display  4->Exit");

    do{
        printf("\nEnter choice:");
        scanf("%d",&choice);
        fprintf(fp,"Choice selected= %d\n",choice);
        switch(choice)
        {
            case 1:push(a,c);
             c++;
            break;

            case 2:pop();
            break;

            case 3:display(a);
            break;

            case 4:break;
        }
    }while(choice!=4);

    return(0);
}

void push(int array[100],int c)
{
    FILE *fp1,*fpp,*stk;
    fp1=fopen("pushlog.txt","a");
    fpp=fopen("operationlog.txt","a");
    if(top==n-1)
    {
        printf("\nStack overflow");
    }
    else{
        top++;
        //fscanf(stk,"%d",num);
        stack[top]=array[c];
    }
    fprintf(fp1,"%d\n",array[c]);
    fprintf(fpp,"Pushed data = %d\n",array[c]);
    fclose(fp1);
    fclose(fpp);
    fclose(stk);
}

void pop()
{
    FILE *fp2,*fpp;
    fp2=fopen("poplog.txt","a");
    fpp=fopen("operationlog.txt","a");

    if(top==-1)
    {
        printf("\nStack underflow");
    }
    else{
        printf("\nPopped data is:%d",stack[top]);
        top--;
    }
    fprintf(fp2,"%d\n",stack[top]);
    fprintf(fpp,"Popped data = %d\n",x);
    fclose(fp2);
    fclose(fpp);

}

void display(int arr[100])
{
     FILE *stk;
     stk=fopen("stack.txt","a");
    for(i=top;i>=0;i--)
    {
        printf(
               "%d\n",arr[i]);
        fprintf(stk,"%d\n",arr[i]);
    }
    fclose(stk);
}

