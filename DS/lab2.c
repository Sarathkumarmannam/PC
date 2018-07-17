//a program on union and intersection of two single linked lists
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node* next; 
}box;
box *head1,*head2,*l1,*l2;
int count1=1,count2=1;

box* create(box* list,int *count)
    {//creates a list and counts the number of nodes in the list
        *count=1;
    box* head=NULL; 
    head=list;
    int ch;
    printf("Enter data of first node\n");
    scanf("%d",&list->data);
    list->next=NULL;
    printf("Do you want another node(1|0)\n");
    scanf("%d",&ch);
    while(ch!=0)
        {   //EXTENDS LIST UNTIL USER DOESN'T WANT ANOTHER NODE
        // CREATES A SINGLY LINKED LIST
        box* newnode=(box*)malloc(sizeof(box));
        printf("Enter data of node\n");
        scanf("%d",&newnode->data);
        list->next=newnode;
        newnode->next=NULL;
        list=newnode;
        *count=*count+1;
         printf("Do you want another node(1|0)\n");
        scanf("%d",&ch);
        }
        printf("A singly linked list is successfully created\n");
    return head;
}
void display(box* start)
{   
    //to display elements of any list
    box *temp=start;//assigning temp to a starting address of a chunk of memory 
    while(temp!=NULL)
    {//Here we traverse the temp Pointer
    printf("%d   ",temp->data);
    temp=temp->next;
    }
printf("\n--------------------\n");
}
int check(box *l,int d)
{
    //checks if the element to be placed in the list is already present or not...
    box *tU=l;
    while(tU!=NULL)
        {
            if(tU->data==d)
                return 1;
            else
            {
                tU=tU->next;
            }
        }
        return 0;
}
box* getnode()
{//returns a chunk of memory to called area..
    box *newnode=(box*)malloc(sizeof(box));
    newnode->next=NULL;
    return newnode;
}
void Union(box *list1,box *list2)
{
    box *U=(box*)malloc(sizeof(box));
    box *tempU=U;
    box *temp1=list1;
    box *temp2=list2;
    while(temp1!=NULL)
        {
            int flag;
            flag=check(U,temp1->data);
            if(flag==0)
            {
            tempU->data=temp1->data;
            box *newnode=getnode();
            tempU->next=newnode;
            tempU=newnode;
            }
            temp1=temp1->next;
        }
     while(temp2!=NULL)
        {
          //  printf("1");
            int flag;
            flag=check(U,temp2->data);
            if(flag==0)
            {
            tempU->data=temp2->data;
            box *newnode=getnode();
            tempU->next=newnode;
            tempU=newnode;
            }
            
            temp2=temp2->next;
        }
        display(U);
}
void Intersection(box *list1,box *list2)
{   //first we find smaller of two lists
    box *I=(box*)malloc(sizeof(box));
    box *tempI=I;
    box *temp1=count1<count2?list1:list2;
    box *temp2=NULL;
    box *tempS=NULL;
    if(temp1==list1)
        tempS=list2;
    else
        tempS=list1;//we now know smaller of lists
     while(temp1!=NULL)
        {   temp2=tempS;

        while(temp2!=NULL)
        {
            if(temp1->data==temp2->data)
                {
                    int flag=check(I,temp1->data);
                    if(flag==0)
                    {
                       
                        tempI->data=temp1->data;
                        printf("%d\t",tempI->data);
                        box *newnode=getnode();
                        tempI->next=newnode;
                        tempI=newnode;
                        break;
                    }
                                
                }
        
            temp2=temp2->next;
        }
        temp1=temp1->next;
        } 
        printf("\n");
  //display(tempI);
}
int main()
{
    l1=(box*)malloc(sizeof(box));//l1 is the first node of the list that's given a memory
    l2=(box*)malloc(sizeof(box));//l2 is the  ..............
    //head1 and head2 are NOT allocated memory dynamically
    head1=create(l1,&count1);//head1 takes the starting address of entire list 1
    system("clear");
    display(head1);//displays list1
    head2=create(l2,&count2);//head2 takes the.... of entire list 2
    system("clear");
    printf("List 1 is ");
    display(head1);
    printf("List 2 is ");
    display(head2);//displays list2
    printf("Union of lists is  ");
    Union(head1,head2);
    printf("Intersection of Lists  ");
    Intersection(head1,head2);
}