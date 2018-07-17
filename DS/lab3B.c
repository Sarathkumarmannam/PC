#include<stdio.h>
#include<stdlib.h>
typedef struct Cnode
{
    int data;
    struct Cnode* next;
}node;
int count1=0,count2=0;
node *head1,*l1,*tail;
//node *head1,*head2,*l1,*l2;
node* getnode()
{//returns a block of memory of size node
    node *newnode=(node*)malloc(sizeof(node));
    return newnode;
}
void display(node* h)
{   //displays a circular list
    node* temp=h;//I am not using temp to traverse but I am using head to traverse
    printf("%d\t",h->data);
    while(h->next!=temp)//checks if we reached end of circular list
    {
        h=h->next;//if not move to next node
        printf("%d\t",h->data);//print data in that memory 
    }
    printf("\n");
} 

void search(node* h)
{
    int check=0,flag=0;
    node *temp=h;
    printf("Enter data to search\n");
    scanf("%d",&check);
    while(h->next!=temp)
    {
        printf("....");
        if(check==h->data)
            flag=1;
        else
        h=h->next;
    }
    if(flag==1)
    printf("Data found\n");
    else    
    printf("Data not found\n");    
}
void sort(node *h)
{
    node* tn=h;
    while(h->next!=tn)
    {
    if(h->data>h->next->data)
    {
        node *t1,*t2,*t3;
        t1=h->next;//a1
        t2=h->next->next;//a2
        t3=h->next->next->next;//a3
        h->next->next->next=t1;//a2->next=a1
        h->next->next=t3;//a1=a3  h,a1,a2,a3->h,a2,a1,a3
        h->next=t2;//h=a2
    }
    else
    h=h->next;
    }    
    display(tn);
}
void insert(node *h)
{
    int drift=1;//to position of a node in a circular list..we use it in loop
printf("Enter Position to insert\n");
int pos;
scanf("%d",&pos);
node* newnode=getnode();//newnode's memory allocated dynamically
node *t=h;//here t is the NEW_HEAD of the LIST
printf("Enter data of newnode to insert ");
scanf("%d",&newnode->data);
if(pos>count1+1||pos==0)//checks if pos is out of bounds
    {
        printf("Please choose the right position\n");
    }
else if(pos==1)
{   //insertion code
    newnode->next=h;
    h=newnode;
    tail->next=h;//tail needs to be updated
    t=newnode;
}    
else if(pos==count1+1)
{   // insertion code
    tail->next=newnode;
    newnode->next=h;
    tail=newnode;        //updating tail to avoid errors
}
else
{
    while(drift!=pos-1)//we have to traverse to before position to insert node at a given position
    {
    h=h->next;//traversing...
    drift++;
    }
    newnode->next=h->next;//insertion code
    h->next=newnode;
}
count1=count1+1;
display(t);
}
node* create(node* h,int *count)//count pointer is used as we can't return two items at a time..
{
   
    node *tn=NULL;//temporary node is the NEWHEAD and 'h' is used to traverse through the list
    tn=h;
    int ch;
     *count=0;
    do{
        *count=*count+1;
    printf("Enter the data of node  ");
    scanf("%d",&h->data);
    h->next=tn;
    printf("Do you want on more node (1|0)");
    scanf("%d",&ch);
    if(ch==1)
    {   //if user requires a node we use getnode() function 
        node *newnode=getnode();
        h->next=newnode;
        newnode->next=tn;
        h=newnode;
        //we have placed a newnode in a circular list
    }
    else
    {
        tail=h; //clever usage of tail pointer reduces time in insert Function
        break;
    }
    }
    while(ch!=0);
    printf("Circular Linked List is successfully created\n");
    return tn;
}
void delete(node* h)
{
    int pos;
    //delete node at particular position
   node* tn=h;
   printf("Enter the position of the node to delete");
   //system("clear");
   scanf("%d",&pos);
    if(pos==1)
    {
        node *del=h;
        tail->next=h->next;
        tn=h->next;
        free(h);
   
    }
    else if(pos==count1)
    {   int drift=1;
      while(drift!=pos-1)//we have to traverse to before position to delete node at a given position
    {
    h=h->next;//traversing...
    drift++;
    }
    free(h->next);
    h->next=tn;
    
    }
    else
    {
       int drift=1;
      while(drift!=pos-1)//we have to traverse to before position to delete node at a given position
    {
    h=h->next;//traversing...
    drift++;
    }
    node *temp=h->next->next;//storing the address of next next node
    free(h->next);
    h->next=temp; 
    }
    display(tn);
}


   int main()
{
    
    l1=(node*)malloc(sizeof(node));
    head1=l1;
    head1=create(head1,&count1);
    //system("clear");
    int ch;
    do
    {
        printf("Make your choice\1n1.Display\n2.Insert\n3.Delete\n");
        printf("4.Search\n5.Sort\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        printf("Circular List 1 is  ");
        display(head1);
        break;
        case 2:
        insert(head1);
        break;
        case 3:
        delete(head1);
        break;
        case 4:
        search(head1);
        break;
        case 5:
        sort(head1);
        break;
        default:
        printf("Enter correct choice\n");       
        }
    }while(ch>0&&ch<6);
}