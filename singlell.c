#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;
struct node* insert_at_beg(struct node *);
struct node* insert_at_end(struct node *);
struct node* delete_at_beg(struct node *);
struct node* delete_at_end(struct node *);
struct node* insert_at_pos(struct node *,int pos);
struct node* delete_at_pos(struct node *,int pos);
void display(struct node *);
//void displayrev(struct node *);
struct node *temp,*temp1,*newnode,*cur,*prev;
main()
{
int ch,pos;
head=NULL;
   while(1)
   {
     printf("1) insert at beginning\n");
     printf("2) insert at the end\n");
     printf("3) delete from beginning\n");
     printf("4) delete from the end\n");
     printf("5) display linked list\n");
     printf("6) insert at position\n");
     printf("7) delete at position\n");
     printf("8) display linked list in reverse order\n");
     printf("9) exit\n");
     printf("\n\n-> Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:newnode=(struct node*)malloc(sizeof(struct node));
             printf("Enter data: ");
             scanf("%d",&newnode->data);
             head=insert_at_beg(newnode);
             break;
    case 2: newnode=(struct node*)malloc(sizeof(struct node));
             printf("Enter data: ");
             scanf("%d",&newnode->data);
             head=insert_at_end(newnode);
             break;
    case 3: if(head==NULL)
             printf("The linked list is empty---cant delete\n");
             else
             {
                head=delete_at_beg(head);
             }
             break;
    case 4: if(head==NULL)
             printf("The linked list is empty---cant delete\n");
             else
             {
                head=delete_at_end(head);
             }
             break;
    case 5: display(head);break;
    case 6:  newnode=(struct node*)malloc(sizeof(struct node));
             printf("Enter data: ");
             scanf("%d",&newnode->data);
             printf("Enter position: ");
             scanf("%d",&pos);
             head=insert_at_pos(newnode,pos);
             break;
    case 7:  if(head==NULL)
             printf("The linked list is empty---cant delete\n");
             printf("Enter position: ");
             scanf("%d",&pos);
             head=delete_at_pos(head,pos);
             break;
    //case 8: displayrev(head);break;
    case 9: exit(0);break;
    default: printf("Invalid choice\n");
     }
   }
}

struct node* insert_at_beg(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     newnode->next=head;
     head=newnode;
     return(head);
   }
}


struct node* insert_at_end(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;

     }
     temp->next=newnode;
        newnode->next=NULL;
        return(head);

   }
}

void display(struct node *head)
{
   if(head==NULL)
   {
     printf("The linked list is empty\n");
   }
   else
   {
      temp=head;
      while(temp!=NULL)
      {
         printf("%d  ",temp->data);
         temp=temp->next;
      }
      printf("\n");

   }
}

struct node* delete_at_beg(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           head=head->next;
           printf("node deleted=%d\n",temp->data);
           free(temp);
           return(head);

       }
    }

}


struct node* delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           while(temp->next!=NULL)
           {
               temp1=temp;
               temp=temp->next;
           }
           printf("node deleted=%d\n",temp->data);
           free(temp);
           temp1->next=NULL;
           return(head);
       }
    }
}
struct node* insert_at_pos(struct node *newnode, int pos)
{
   int count=1;
   prev=NULL;
   if(head==NULL)
   {
    printf("Invalid");
   }
        if(head->next==NULL)
        {
        newnode->next=head;
        return(head);
        }
        if(pos==1)
        {
        newnode->next=head;
        return(head);
        }
        prev=NULL;
        cur=head;
        while(cur!=NULL&&count!=pos)
        {
        prev=cur;
        cur=cur->next;
        count++;
        }
        if(count==pos)
        {
            prev->next=newnode;
            newnode->next=cur;
            return(head);
        }
}

struct node* delete_at_pos(struct node *newnode, int pos)
{
   int count=1;
   prev=NULL;
   if(head==NULL)
   {
    printf("Invalid");
   }
        if(head->next==NULL&&pos==1)
        {
            head=NULL;
            free(head);
        }
        prev=NULL;
        cur=head;
        while(cur!=NULL&&count!=pos)
        {
        prev=cur;
        cur=cur->next;
        count++;
        }
        if(count==pos)
        {
            prev->next=cur->next;
            return(head);
        }
}
/*void displayrev(struct node *head)
{
   if(head==NULL)
   {
     printf("The linked list is empty\n");
   }
   else
   {
      temp=head;
      while(temp->next!=NULL)
           {
               temp1=temp;
               temp=temp->next;
           }
      while(temp!=NULL)
      {
         printf("%d  ",temp->data);
         temp=temp->next;
      }
      printf("\n");

   }
}*/


