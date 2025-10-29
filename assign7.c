#include<stdio.h>
#include<stdlib.h>
//Disjoint set representation 
//structure to represent an object of a set in linked representation
struct node
{
 int value;
 struct rep*repptr;//pointer to header node of the list
 struct node*next;
};

//structure to represent header node of linked representation of set
struct rep
{ 
 struct node*head;
 struct node*tail;
};

//structure to store key and object node pointer
struct nodaddr
{
 int key;
 struct node* obj_node_ptr;
 struct nodaddr*next;
};
 
 struct nodaddr*ndr=0; //list to store keys and object node pointer
 
//function to create a set for an object
void makeset(int a )
{//create a object node pointer
 struct nodaddr*t=(struct nodaddr*)malloc(sizeof(struct nodaddr));
 
 //create a new set
 struct rep*newset=(struct rep*)malloc(sizeof(struct rep));
 struct node*n=(struct node*)malloc(sizeof(struct node));
 
 //fill values
 n->value=a;
 n->repptr=newset;
 n->next=0;
  
 //initialize head and tail
 newset->head=newset->tail=n;
 
 //to store object node pointer and key
 t->obj_node_ptr=n;
 t->key=a;
 t->next=ndr;
 ndr=t;
}

//function to return pointer of the representation (header node)of the set
//containing x
struct rep * find(int X)
{
 struct nodaddr * t=ndr;
 while (t!=0 && t->key!=X)
    t=t->next;
  return t->obj_node_ptr->repptr;
}

//to find union of 2 sets corresponding to objects given
void unionset(int key1, int key2)
{
 struct rep *set1, *set2;
 struct node *t1;
 set1=find(key1);
 set2=find(key2);
 if(set1==set2)
   printf("\n%d & %d belongs to same set\n", key1,key2);
 else
 {
  //changing the header pointer of objects of set2 to that of set1
  t1=set2->head;
  while(t1!=0)
   {t1->repptr=set1;
    t1=t1->next;
   }
 set1->tail->next=set2->head;
 set1->tail=set2->tail; //set the tail of set1 to tail of set2
 free(set2);
 }
}

//function to display a set
void display_set(int a )
{
 struct rep*r;
 struct node*t;
 r=find (a);
 t=r->head;
  printf("set members containing %d:",a);
  while(t!=0)
  { printf("%d, ",t->value);
    t=t->next;
  }
}

void main()
{
 makeset(50);
 makeset(60);
 makeset(70);
 makeset(80);
 makeset(90);
 printf("find(50)=%X",find(50));
  printf("\n find(60)=%X",find(60));
  printf("\n find(70)=%X",find(70));
  printf("\n find(80)=%X",find(80));
  unionset(50,60);
  printf("\nafter union of 50 & 60 find(60)=%X", find(60));
  unionset(70,80);
  printf("\nafter union of 70 & 80 find(80)=%X", find(80));
  unionset(60,80);
  printf("\nafter union of set containing 60 & 80 find(80)=%X\n", find(80));
  display_set(80);

}
  
