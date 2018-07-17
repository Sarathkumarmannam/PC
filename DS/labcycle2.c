//A program to union and intersection of linked list
//reference is codeforwin.org
//creating and traversing a singly linked list

struct node* CreateList(struct node *,int n);
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*lst1,*lst2,*head1,*head2,*temp;
void Display(struct node *);
void Union(struct node*,struct node*);
void Intersection(struct node*,struct node*);
int main()
{
int n;
printf("Enter number of elements in a linked list ONE\t");
scanf("%d",&n);
lst1=CreateList(head1,n);
printf("Enter number of elements in a linked list TWO\t");
scanf("%d",&n);
lst2=CreateList(head2,n);
int ch;
printf("Enter 1 to Union and 2 for intersection\n");
scanf("%d",&ch);
do
{
switch(ch)
{
    case 1:
        Union(lst1,lst2);
        break;
    case 2:
        Intersection(lst1,lst2);
        break;
    default:
        printf("Choose a correct choice\nDo U want to continue(1|0)\n");
        scanf("%d",&ch);
}
while(ch!=0||ch<=2);
return(0);
}
 void Union(struct node* lst1,struct node* lst2)
 {
     temp
     struct node* U=NULL;
     U=(struct node*)malloc(sizeof(struct node));
     while()
 } 
struct node* CreateList(struct node* head,int n)
{
    int i;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory not allocated");
        exit(-1);
    }
    head->next=NULL;
    temp=head;
    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Memory is not found");
            break;
        }
        else
        {
            printf("Enter data of node %d:\t",i);
            scanf("%d",&newnode->data);
            newnode->next=NULL;//make newnode next pointer to null
            temp->next=newnode;//store address of new node in previous node
            temp=temp->next;//move to newnode so to make newnode as previous node
        }
    }
    printf("List successfully created\n");
    printf("---------------------\n");
    return head;
}
void Display(struct node *start)
{
    temp=start;
    temp=temp->next;
    int i=1;
    while(temp!=NULL)
    {
        printf("List %d data is %d;\n",i,temp->data);
        temp=temp->next;
    i++;
    }
}

