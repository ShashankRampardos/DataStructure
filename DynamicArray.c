#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
///Grow Able and Shrink Able Array DataStructure

struct DynamicArray* createArray();
void deleteArrayElement(int index,struct DynamicArray*);
void insertArray(int index,int data,struct DynamicArray *a);
void displayAllArray(struct DynamicArray*);
int getElement(int index,struct DynamicArray*);
void editArray(int index,int data,struct DynamicArray *);
int countArray(struct DynamicArray*);
void appendElement(int data,struct DynamicArray*);
void searchElement(int data,struct DynamicArray*);
void doubleArray(struct DynamicArray*);
void halfArray(struct DynamicArray*);

struct DynamicArray///we could use typedef also
{
   int *p;
   int capacity;
   int lastIndex;
};
///---------------------------------------------
struct DynamicArray* createArray()
{
  struct DynamicArray *A=(struct DynamicArray*)malloc(sizeof(struct DynamicArray));
  A->capacity=10;
  A->p=(int*)malloc(sizeof(int)*10);
  A->lastIndex=-1;

  return A;
}
///-------------------------------------------
void insertArray(int index,int data,struct DynamicArray *a)
{
  if(index<0||index>a->lastIndex+1)
    printf("InvalidArrayIndex");
  else
   {
     if(a->capacity==a->lastIndex+1)
       doubleArray(a);
      for(int i=a->lastIndex+1;i>index;i--)
    {
        a->p[i]=a->p[i-1];
    }
    a->p[index]=data;
    a->lastIndex++;
   }

}

///--------------------------------------------
void deleteArrayElement(int index,struct DynamicArray *a)
{   if(index<0||index>a->lastIndex)
     printf("InvalidArrayIndex");
    else
     {
    for(int i=index;i<a->lastIndex-1;i++)
    {
        a->p[i]=a->p[i+1];
    }
    a->lastIndex--;
     }
    if(a->lastIndex+1==a->capacity/2&&a->capacity>1)///if we write (a->lastIndex<a->capacity/2) halfArray() will be called unnecessarily initially
        halfArray(a);

}
///-------------------------------------------
void displayAllArray(struct DynamicArray *a)
{

    if(a->lastIndex==-1)
    printf("\nArray is Empty");
    else{
    printf("\nArrayElements: ");
    for(int i=0;i<a->lastIndex+1;i++)
    {
        printf("%d ",getElement(i,a));
    }
    }
}
///-------------------------------------------
int getElement(int index,struct DynamicArray *a)
{
    if(index<0||index<=a->lastIndex)
    return a->p[index];
    else
    return -1;
}
///------------------------------------------
void editArray(int index,int data,struct DynamicArray *a)
{
  if(index<0||index<=a->lastIndex)
    a->p[index]=data;
  else
    printf("InvalidArrayIndex");

}
///------------------------------------
int countArray(struct DynamicArray* a)
{
     return (a->lastIndex+1);
}
///--------------------------------
void appendElement(int data,struct DynamicArray* a)
{
    if(a->capacity==a->lastIndex+1)
       doubleArray(a);
     a->p[a->lastIndex+1]=data;
     a->lastIndex++;
}
void searchElement(int data,struct DynamicArray *a)
{   short judge=0;
    for(int i=0;i<a->lastIndex+1;i++)
    {
       if(a->p[i]==data){
        printf("\n%d is found at %d index",data,i);
        judge++;
       }
    }
    if(!judge)
        printf("Item not Found");
}
void doubleArray(struct DynamicArray* a)
{
    int *dbl=(int)malloc(sizeof(int)*a->capacity*2);
    for(int i=0;i<a->lastIndex+1;i++)
    {
        dbl[i]=a->p[i];
    }
    free(a->p);
    a->p=dbl;
    a->capacity=a->capacity*2;
}
void halfArray(struct DynamicArray* a)
{
    int *hlf=malloc(sizeof(int)*a->capacity/2);
    for(int i=0;i<a->lastIndex+1;i++)
    {
        *(hlf+i)=a->p[i];
    }
    free(a->p);
    a->p=hlf;
    a->capacity=a->capacity/2;
}
int main()
{  int n;
    //printf("Enter size of Array:");
    //scanf("%d",&n);
    //system("cls");
struct DynamicArray *const a=createArray();

while(1)
{

    short list;
    int data,index;
    printf("Total Array Elements:%d",countArray(a));
        displayAllArray(a);
    printf("\n1.Insert Array Element");
    printf("\n2.Print Array Element");
    printf("\n3.Update Array Element");
    printf("\n4.Delete Array Element");
    printf("\n5.Search Array Element");
    printf("\n6.Append Element");
    printf("\n10.Exit");

    printf("\n\nChoose Operation(Enter List number):");
    scanf("%hi",&list);///I written wrong formate specifier of short int as %d instead of %hi which caused program to crash(value of "a" pointer gets corrupted).

    switch(list)
    {
    case 1:

        printf("Enter Array Index and Array Data");
        scanf("%d%d",&index,&data);
        insertArray(index,data,a);
        break;
    case 2:
        printf("Enter Index of Array Element to Display");
        scanf("%d",&index);
        printf("Element:%d",getElement(index,a));
        break;
    case 3:
        printf("Enter Index of array Element to Update:");
        scanf("%d",&index);
        printf("Enter Data:");
        scanf("%d",&data);
        editArray(index,data,a);
        break;
    case 4:
        printf("Enter Index of array element to Remove:");
        scanf("%d",&index);
        deleteArrayElement(index,a);
        break;
    case 5:
        printf("Enter value to search in:");
        scanf("%d",&data);
        searchElement(data,a);
        break;
    case 6:
        printf("Enter value to append data in array:");
        scanf("%d",&data);
        appendElement(data,a);
        break;
    case 10:
        free(a->p);
        free(a);
        getch();
        exit(0);
    default:
        printf("Enter Value 1 to 6 or 10");
    }
  getch();
  system("cls");
}

}

