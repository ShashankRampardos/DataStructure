#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
///Enhenced Array DataStructure

struct ArrayAdt* createArray(int capacity);

void deleteArrayElement(int index,struct ArrayAdt*);
void insertArray(int index,int data,struct ArrayAdt *a);
void displayAllArray(struct ArrayAdt*);
void printArrayElement(int index,struct ArrayAdt*);

void editArray(int index,int data,struct ArrayAdt *);
int countArray(struct ArrayAdt*);
void appendElement(int data,struct ArrayAdt*);
void searchElement(int data,struct ArrayAdt*);
///Remember:Avoid Global Declaration of variable most of the time.
struct ArrayAdt///we could use typedef also
{
   int *p;
   int capacity;
   int lastIndex;
};
///---------------------------------------------
struct ArrayAdt* createArray(int capacity)
{
  struct ArrayAdt *A=(struct ArrayAdt*)malloc(sizeof(struct ArrayAdt));
  A->capacity=capacity;
  A->p=(int*)malloc(sizeof(int)*capacity);
  A->lastIndex=-1;

  return A;
}
///-------------------------------------------
void insertArray(int index,int data,struct ArrayAdt *a)
{
  if(index<0||index>a->lastIndex+1)
    printf("InvalidArrayIndex");
  else if(a->capacity==a->lastIndex+1)
    printf("OverFlow");
  else
  {
      for(int i=a->lastIndex+1;i>index;i--)
    {
        a->p[i]=a->p[i-1];
    }
    a->p[index]=data;
    a->lastIndex++;
   }

}

///--------------------------------------------
void deleteArrayElement(int index,struct ArrayAdt *a)
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

}
///-------------------------------------------
void displayAllArray(struct ArrayAdt *a)
{

    if(a->lastIndex==-1)
    printf("Array is Empty");
    printf("\n");
    for(int i=0;i<a->lastIndex+1;i++)
    {
        printf("%d ",a->p[i]);
    }
}
///-------------------------------------------
void printArrayElement(int index,struct ArrayAdt *a)
{
    if(index<0||index<=a->lastIndex)
    printf("\n%d ",a->p[index]);
    else
    printf("\nInvalidIndexOfArray");
}
///------------------------------------------
void editArray(int index,int data,struct ArrayAdt *a)
{
  if(index<0||index<=a->lastIndex)
    a->p[index]=data;
  else
    printf("InvalidArrayIndex");

}
///------------------------------------
int countArray(struct ArrayAdt* a)
{
     return (a->lastIndex+1);
}
///--------------------------------
void appendElement(int data,struct ArrayAdt* a)
{
     a->p[a->lastIndex+1]=data;
     a->lastIndex++;
}
void searchElement(int data,struct ArrayAdt *a)
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
int main()
{  int n;
    printf("Enter size of Array:");
    scanf("%d",&n);
struct ArrayAdt *const a=createArray(n);
//insertArray(0,43,a);
//displayAllArray(a);
while(1)
{

    short list;
    int data,index;
    printf("Total Array Elements:%d",countArray(a));///At this point "a" pointer value is same(unchanged & secure)///(problem solved)
    printf("\n1.Insert Array Element");
    printf("\n2.Display All Array Elements");
    printf("\n3.Print Array Element");
    printf("\n4.Update Array Element");
    printf("\n5.Delete Array Element");
    printf("\n6.Search Array Element");
    printf("\n7.Append Element");
    printf("\n8.Exit");

///printf("Total Array Elements:%d Address:%u",countArray(a),a);///At this point a pointer value is same(unchanged & secure) also.///(problem solved)
    printf("\n\nChoose Operation(Enter List number):");
    ///list=1;///if I Hard quote list(switch variable) then no problem but, if I uncomment below scanf(); statement then "a" pointer value gets corrupted///(problem solved)
    scanf("%hi",&list);///I written wrong formate specifier of short int as %d instead of %hi which caused program to crash(value of "a" pointer gets corrupted).
    ///changed formate specifier
///printf("Total Array Elements:%d Address:%u",countArray(a),a);///Now this line will display corrupted "a" pointer value which proves that line 144 creating problems, value is corrupted by scanf() in line number 144
    switch(list)
    {
    case 1:

        printf("Enter Array Index and Array Data");
        scanf("%d%d",&index,&data);
        //printf("Total Array Elements:%d Address:%u",countArray(a),a);
        insertArray(index,data,a);
        //displayAllArray(a);
        break;
    case 2:
        printf("Array Elements:");
        displayAllArray(a);
        break;
    case 3:
        printf("Enter Index of Array Element to Display");
        scanf("%d",&index);
        printArrayElement(index,a);
        break;
    case 4:
        printf("Enter Index of array Element to Update:");
        scanf("%d",&index);
        printf("Enter Data:");
        scanf("%d",&data);
        editArray(index,data,a);
        break;
    case 5:
        printf("Enter Index of array element to Remove:");
        scanf("%d",&index);
        deleteArrayElement(index,a);
        break;
    case 6:
        printf("Enter value to search in:");
        scanf("%d",&data);
        searchElement(data,a);
        break;
    case 7:
        printf("Enter value to append data in array:");
        scanf("%d",&data);
        appendElement(data,a);
        break;
    case 8:
        getch();
        exit(0);
    default:
        printf("Enter Value 1 to 8");
    }
  getch();
  system("cls");
}
  /*insertArray(0,111);
    insertArray(1,112);
    insertArray(2,113);
    insertArray(3,114);
    displayAllArray();

    insertArray(1,115);
    displayAllArray();
    deleteArrayElement(2);
    displayAllArray();
    printArrayElement(7);*/
}
