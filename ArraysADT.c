#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
///Enhenced Array DataStructure

void shiftRight(int point);
void deleteArrayElement(int point);
void insertArray(int index,int data);
void displayAllArray();
void printArrayElement(int index);
void deleteArrayElement(int index);
void editArray(int index,int data);
struct
{
   int arr[100];
   int capacity;
   int loaderIndex;
}A={{0},100,0};

///---------------------------------------------
void insertArray(int index,int data)
{
  if(index<A.capacity)
   if(!(index<=A.loaderIndex))//if part written in else by mistake so ! operator used..
    printf("ArrayIndexOutOfBound");
   else{

       if(A.loaderIndex==index){
       A.arr[index]=data;
       A.loaderIndex++;
       }
       else{
            shiftRight(index);
            A.arr[index]=data;
            A.loaderIndex++;
       }
   }
   else
    printf("ArrayIndexOutOfBound");
}
///--------------------------------------------
void shiftRight(int point)
{

    for(int i=A.loaderIndex;i>point;i--)
    {
        A.arr[i]=A.arr[i-1];
    }

}
///--------------------------------------------
void deleteArrayElement(int point)
{   if(point<A.loaderIndex){
    for(int i=point;i<A.loaderIndex-1;i++)
    {
        A.arr[i]=A.arr[i+1];
    }
    A.loaderIndex--;}
    else
        printf("ArrayIndexOutOfBound");
}
///-------------------------------------------
void displayAllArray()
{   if(A.loaderIndex==0)
    printf("Array is Empty");
    printf("\n");
    for(int i=0;i<A.loaderIndex;i++)
    {
        printf("%d ",A.arr[i]);
    }
}
///-------------------------------------------
void printArrayElement(int index)
{   if(index<A.loaderIndex)
    printf("\n%d ",A.arr[index]);
    else
    printf("\nArrayIndexOutOfBound");
}
///------------------------------------------
void editArray(int index,int data)
{
  if(index<A.loaderIndex)
    A.arr[index]=data;
  else
    printf("ArrayIndexOutOfBound");

}
int main()
{

while(1)
{
    short list;
    int data,index;

    printf("1.Insert Array Element");
    printf("\n2.Display All Array Elements");
    printf("\n3.Print Array Element");
    printf("\n4.Update Array Element");
    printf("\n5.Delete Array Element");
    printf("\n6.Exit");


    printf("\n\nChoose Operation(Enter List number):");
    scanf("%d",&list);

    switch(list)
    {
    case 1:

        printf("Enter Array Index and Array Data");
        scanf("%d%d",&index,&data);
        insertArray(index,data);
        break;
    case 2:
        printf("Array Elements:");
        displayAllArray();
        break;
    case 3:
        printf("Enter Index of Array Element to Display");
        scanf("%d",&index);
        printArrayElement(index);
        break;
    case 4:
        printf("Enter Index of array Element to Update:");
        scanf("%d",&index);
        printf("Enter Data:");
        scanf("%d",&data);
        editArray(index,data);
        break;
    case 5:
        printf("Enter Index of array element to Remove:");
        scanf("%d",&index);
        deleteArrayElement(index);
        break;
    case 6:
        getch();
        exit(0);
    default:
        printf("Enter Value 1 to 5");

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
