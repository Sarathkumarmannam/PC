#include<stdio.h>
#include<stdlib.h>
typedef struct CNode
{
    int data;
    struct CNode *next;
}node;
node *H,*first;
void insert();
void create();
int NoOfNodes();
void display();
int main()
{
    //Execution Starts Here...!!
    create();
    display();
    insert();
    display();
}
void insert()
{
    int pos;
    node* INode=(node*)malloc(sizeof(node));
    printf("Enter data to insert");
    scanf("%d",&INode->data);
    printf("Where do you want to Insert..Enter your Position\n");
    scanf("%d",&pos);
    if(pos>NoOfNodes())
    {
        printf("Invalid Position\n");
       return;
    }
    else if(pos==1)
    {

        INode->next=H;
        H=INode;
        node* temp=INode;
        int count=1;
        while(temp->next!=INode)
        {   //traverse till last node
            temp=temp->next;
        }
        temp->next=H;
    }
    else if(pos!=NoOfNodes())
    {
        //Insert at last
        node* t=H;
        int count=1;
        while(count!=NoOfNodes())
        {   //traverse till last node
            t=t->next;
            count++;
        }
        //place this node in this Circular list
        INode->next=H;
        t->next=INode;

    }
    else 
    {
        node* t=H;
        int count=1;
        while(count!=pos-1)
        {   //traverse till last node
            t=t->next;
            count++;
        }
        INode->next=t->next;
        t->next=INode;
    }
}
void display()
{
    //Print's CircularList..
    node *t=H;
    printf("%d ",t->data);
    t=t->next;
    while(t!=H){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
void create()
{   //creates a circular list
    //NOTE:NO memory assigned for head pointer
    first=(node*)malloc(sizeof(node));
    H=first;
    printf("Enter data of  node\t");
    scanf("%d",&first->data);
        first->next=H;
    int flag;
    printf("Do you want one more node:(1|0) \n");
    scanf("%d",&flag);
    while(flag!=0)
    {
        node* newnode=(node*)malloc(sizeof(node));
        printf("Enter data of new node\t");
        scanf("%d",&newnode->data);
        first->next=newnode;
        newnode->next=H;
        first=newnode;
        printf("Do you want one more node:(1|0) \n");
        scanf("%d",&flag);
    }
    printf("Congrats!! Cirular Linked List is successfully created\n");
}
int NoOfNodes()
{
    //returns no.of nodes in the circular linked list
    int count=0;
    if(H==NULL)
    {
        printf("No Elements in the list\n");
        return 0;
    }
    node *t=H;
    do{
        count++;
        t=t->next;

    }
    while(t!=H);
    return count;

}
