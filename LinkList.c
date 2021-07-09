#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
int data;
struct Node *link;///assignment possible nahi ha edhar
}Node;

Node* createNode()
{
    Node *p;
    p=malloc(sizeof(Node));
    p->link=NULL;
    return p;
}


void insertFirst(int item,Node **s)
{   Node *p;
    p=malloc(sizeof(Node));

   if(*s==NULL){
   *s=p;
   (*s)->data=item;///Arrow operator has higher priority.
   (*s)->link=NULL;
   }
   else
   {
       p->link=*s;
       *s=p;
       (*s)->data=item;
   }
}
void editParticular(int item,int listNo,Node **s)
{

    if(*s==NULL)
    {
       printf("\nList is empty");
        getch();
    }
    else{
    int cnt=1;
    Node *t=*s;///first node address assigned to temp pointer

    while(cnt!=listNo&&t->link!=NULL)
    {
        t=t->link;
        cnt++;
    }
    if(cnt==listNo)
    t->data=item;
    else{
        printf("List Number is out of List");
        getch();}
    }
}
void insertParticular(int item,int listNo,Node **s)
{
    Node *p=malloc(sizeof(Node));
    p->data=item;
    p->link=NULL;

    if(*s==NULL)
    {

       if(listNo==1)
        *s=p;
       else
       printf("List Number is out of List");
        getch();
    }
    else if(listNo==1)
    {
        p->link=(*s);
        *s=p;
    }
    else{
    int cnt=1;
    Node *r,*t=*s;///first node address assigned to temp pointer
    while(cnt!=listNo&&t->link!=NULL)
    {   r=t;
        t=t->link;
        cnt++;
    }
    if(cnt==listNo){
    r->link=p;
    p->link=t;}
    else{
        printf("List Number is out of List");
        getch();}

    }
}
void insertLast(int item,Node **s)
{
    Node *p=malloc(sizeof(Node));
    p->link=NULL;
    p->data=item;
    if(*s==NULL)
       {
           *s=p;
       }
    else
    {  Node *t=*s;
         while(t->link!=NULL)
         t=t->link;

       t->link=p;

    }

}
void deleteFirstNode(Node **s)
{
    if(*s==NULL){
        printf("\nList is Empty");
        getch();
    }

    else{
    *s=(*s)->link;
    free(*s);
    }
}
void deleteLastNode(Node **s)
{  if(*s==NULL){
        printf("\nList is Empty");
        getch();
    }
   else{
    Node *r=NULL,*t=*s;
    ///*r will have previous node address of *t
    while(t->link!=NULL)
    {
        r=t;
        t=t->link;
    }
    r->link=NULL;
    free(t);
   }
}
void deleteParticularNode(int listNo,Node **s)
{
    if(*s==NULL){
        printf("List Number is out of List");
        getch();
        return;}
    else{
    int cnt=1;
    Node *r,*t=*s;///first node address assigned to temp pointer
    while(cnt!=listNo&&t->link!=NULL)
    {   r=t;
        t=t->link;
        cnt++;
    }
    if(cnt==listNo){
    r->link=t->link;
    free(t);}
    else{
        printf("List Number is out of List");
        getch();}
    }

}
int getNodeData(int listNo,Node **s)
{
    if(*s==NULL)
    return -1;
    else{
    int cnt=1;
    Node *t=*s;///first node address assigned to temp pointer

    while(cnt!=listNo&&t->link!=NULL)
    {
        t=t->link;
        cnt++;
    }if(cnt==listNo)
      return t->data;
     else{
        printf("List Number is out of List");
        getch();
      return -1;}
    }
}
int countList(Node **s)
{   if(*s==NULL)
     return 0;
    else{
    int cnt=0;
    Node *t=*s;///first node address assigned to temp pointer
    cnt++;
    while(t->link!=NULL)
    {
        t=t->link;
        cnt++;
    }
    return cnt;
    }
}
void freeListItems(Node **s)
{   if(*s==NULL)
    return;
    else{
    Node *r,*t=*s;

    while(t->link!=NULL)
    {   r=t;
        t=t->link;
        free(r);
    }
    //free(*s);
    free(t);
    }
}
int main()
{
Node *start=NULL;
int item,listNo;

   printf("SELECT OPTIONS");
   getch();
while(1)
{

  int l=countList(&start);


   system("cls");
printf("Number of List Item:%d\n",l);
printf("List Items:\n");
for(int i=1;i<=l;i++)
    printf("%d ",getNodeData(i,&start));

printf("\n1.Insert First Node\n");
printf("2.Insert Last Node\n");
printf("3.Insert Particular Node\n");///@workHere in if(lintNo==1) part
printf("4.Delete First Node\n");
printf("5.Delete Last Node\n");///problem AND countElement problem
printf("6.Delete Particular Node\n");
printf("7.Get a List Data\n");
printf("8.Edit List Item\n");
printf("10.Exit\n");
printf("\n");
int gate;
printf("Enter your choice:\n");
scanf("%d",&gate);
switch(gate)
{
case 1:
    printf("Enter List item:");
    scanf("%d",&item);
    insertFirst(item,&start);
   break;
case 2:
    printf("Enter List item:");
    scanf("%d",&item);
    insertLast(item,&start);
   break;
case 3:
    printf("Enter List item:");
    scanf("%d",&item);
    printf("Enter List Number:");
    scanf("%d",&listNo);
    insertParticular(item,listNo,&start);
   break;
case 4:
    deleteFirstNode(&start);
   break;
case 5:
    deleteLastNode(&start);
   break;
case 6:
    printf("Enter List number to delete:");
    scanf("%d",&listNo);
    deleteParticularNode(listNo,&start);
   break;
case 7:
    printf("Enter List number:");
    scanf("%d",&listNo);
    printf("Data:%d",getNodeData(listNo,&start));
   break;
case 8:
    printf("Enter List number:");
    scanf("%d",&listNo);
    printf("Enter New Item:");
    scanf("%d",&item);
    editParticular(item,listNo,&start);
    break;
case 10:

    freeListItems(&start);
  //free(start);
    getch();
    exit(0);
default:   
    printf("Enter number 1 to 7 or 10\n");
        getch();

}

}
}
