#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
 struct node*next;
};
void main()
{struct node*sp=(struct node*)0;
 struct node*push(struct node*,int);
 struct node*pop(struct node*);
 void display(struct node*);
 int search(struct node*,int),opt,item,ans;
 while(1)
 {
  printf("\n1.Push \n2.Pop \n3.Display \n4.search \n5.exit \n");
  printf("Your option:");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1 : printf("Item to push:");
            scanf("%d",&item);
            sp=push(sp,item);
            break;
   case 2 : sp=pop(sp);
            break;
   case 3 : display(sp);
            break;
   case 4 : printf("Item to search:");
            scanf("%d",&item);
            ans=search(sp,item);
            if(ans==1)
             printf("found..");
            else
             printf("Not found..");
            break;
   case 5 : exit(0);
   }
   }//end of while
   }//end of main
   
//function to push a node in a linked list
struct node*push(struct node*list,int data)
{struct node*t;
  t=(struct node*)malloc(sizeof (struct node));
  t->data=data;
  t->next=list;
  list=t;
  return list;
}

//function to pop a node
struct node*pop (struct node*list)
 {struct node*t=list;
   if(list!=(struct node*)0)
      {printf("poped item:%d",list->data);
        list=list->next;
        free(t);
      }
   else
     printf("list is null");
   return list;
 } 
 
 //function to display list contents
 void display (struct node* list)
  {
   while(list!=(struct node*)0)
    { 
      printf("%d,",list->data);
      list=list->next;
    }
  return;
  }  
 
//function to search an item
int search(struct node* list, int item)
 {
   while(list!=(struct node*)0 && item!=list-> data)
         list=list->next ;
   if(list==(struct node*)0)
     return 0;
   else
     return 1;
 }      
                  
