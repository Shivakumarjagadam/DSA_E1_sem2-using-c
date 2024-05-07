#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node *next;
 };
 struct node *start=NULL;              //all insertion,deletion,length_ll,reverse_ll 
 struct node *create(struct node *);   //were allocated.....
 struct node *display(struct node*);
 struct node *insert_beg(struct node *);
 struct node *insert_end(struct node*);
 struct node *insert_val(struct node *);
 struct node *del_beg(struct node*);
 struct node *del_end(struct node *);
 struct node *del_val(struct node*);
 struct node *length_ll(struct node*);
 struct node *reverse_ll(struct node*);
 struct node *mid(struct node*);
 int main(){
    int choice;
    do{
    printf("***MAIN MENU***\n1.create linked list\n2.display\n3.insert_beg\n4.insert_end\n5.insert_val\n6.del_beg\n7.del_end\n8.del_val\n9.length of ll\n10.reverse ll..\n11.exit");
    scanf("%d",&choice);
    switch(choice){
    case 1:
    start=create(start);
    printf("linked list created\n");
    break;
    case 2:
    start=display(start);
    break;
    case 3:start=insert_beg(start);
    break;
    case 4:start=insert_end(start);
    break;
    case 5:start=insert_val(start);
    break;
    case 6:start=del_beg(start);
    break;
    case 7:
    start=del_end(start);
    break;
    case 8:start=del_val(start);
    break;
    case 9:start=length_ll(start);    //length of linked list....
    break;
    case 10:start=reverse_ll(start);//reverse of linked list..
    break;
    case 11:start=mid(start);//r
    break;
    default:printf("try again:\n\n");
    }
    }while(choice!=11);

    return 0;
 }
 struct node *create(struct node *start){
    struct node *current,*newnode;
    int num;
    printf("enter a data and -1 to stop:");
    scanf("%d",&num);
    while(num!=-1){    
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(start==NULL){
        newnode->next=NULL;
        start=newnode;
    }
    else {
        current=start;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
        newnode->next=NULL;
    }
     printf("enter num to continue/stop(-1)");
    scanf("%d",&num);
    }
     
    return start;
    
 }
 struct node *display(struct node *start){
    struct node *current;
    current=start;
    while(current->next!=NULL){
        printf("%d\t",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
    return start;
 }
 struct node *insert_beg(struct node *start){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("entre data\n");
    scanf("%d",&newnode->data);
    newnode->next=start;
    start=newnode;
    return start;
 }
 struct node *insert_end(struct node *start){
    struct node *current,*newnode;
    current=start;
    newnode=(struct node*)malloc(sizeof(struct node));
    int num;
    printf("enter data\n");
    scanf("%d",&num);
    while(current->next!=NULL){
        current=current->next;
    }
    newnode->data=num;
    current->next=newnode;
    newnode->next=NULL;
    return start;
 }
 struct node *insert_val(struct node *start){
    struct node *current,*newnode,*prev;
    int val;
    current=start;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter an element from list (to insert data on the element) ");
    scanf("%d",&val);
    while(current->data!=val){
        prev=current;
        current=current->next;

    }
    printf("enter data to insert:\n");
    scanf("%d",&newnode->data);
    newnode->next=current;
    prev->next=newnode;
    return start;
 }
 struct node *del_beg(struct node *start){
    struct node *current;
    current=start;
    start=start->next;
    free(current);
    return start;
 }
 struct node *del_end(struct node *start){
    struct node *current,*prev;
    current=start;
    while(current->next!=0){
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    free(current);
    return start;
    
    }
    struct node *del_val(struct node *start){
    struct node *current,*prev;
    current=start;
    int val;
    printf("enter an element to delete:");
    scanf("%d",&val);
    while(current->data!=val){
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    free(current);
    return start;
    }
    struct node *length_ll(struct node *start){
      int count=0;
      struct node *current;
      current=start;
      while(current!=0){

         count++;
         current=current->next;
      }
      printf("length of linked list:%d\n",count);
      return start;
    }
    struct node *reverse_ll(struct node *start){
      struct node *temp,*prev=0,*nextnode;
      temp=nextnode=start;
      while(nextnode!=0){
         nextnode=nextnode->next;
         temp->next=prev;
         prev=temp;
         temp=nextnode;
      }
      start=0;
    }
   //  struct node *mid(struct node*start){
   //    struct node *newnode,*temp;
   //    int num,sum=0,avg,c=0;
   //    newnode=(struct node*)malloc(sizeof(struct node));
   //    newnode->data=num;
   //    temp=start;
   //    while(temp->next!=NULL){
   //       temp=temp->next;
   //       c++;
   //       sum=sum+c;

   //    }
   //    avg=sum/c;
   //    int i=1;
   //    temp=start;
   //    while(i!=avg){
   //       temp=temp->next;
   //       i++;
   //    }
   //    printf("middle elements:%d\n",avg);
   //    newnode->next=temp->next;
   //    temp->next=newnode;
   //    return  start;
   //  }
   struct node *mid(struct node*start){
      struct node *newnode,*temp;
      int num,sum=0,avg,c=0;
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=num;
      temp=start;
      while(temp->next!=NULL){
         temp=temp->next;
         c++;
         sum=sum+c;

      }
      avg=sum/c;
      int i=1;
      temp=start;
      while(i!=avg){
         temp=temp->next;
         i++;
      }
      printf("middle elements:%d\n",avg);
      newnode->next=temp->next;
      temp->next=newnode;
      return  start;
    }