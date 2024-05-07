//doubly linked list...
#include<stdio.h>
#include<stdlib.h>          //implementation of doubly linked list....
  struct node{
    int data;
    struct node *next,*prev;

  };
  struct node *head,*tail,*newnode;

  struct node *head=NULL;
  struct node *create_dll(struct node *);
  struct node *display(struct node *);
  struct node *insert_beg(struct node *);
  struct node *insert_end(struct node *);
  struct node *insert_at_pos(struct node*);
  struct node *del_beg(struct node *);
  struct node *del_end(struct node *);
  struct node *del_at_pos(struct node*);
  struct node *reverse_dll(struct node*);


  int main(){
    int val;
    
    do{

   printf("***MAIN--MENU***\n1.create a doubly linked list\n2.display doubly linked list\n3.insert at beg\n4.insert at end \n5.insert at position\n6.delete at beg\n7.delete at eng\n8.delete at pos.\n9.reverse doubly linked list\n10.exit ");
    scanf("%d",&val);
    switch(val){
      case 1:
     head=create_dll(head);
     printf("liked list created\n display values:\n");
     break;
     case 2:
     head=display(head);
     break;
     case 3:
     head=insert_beg(head);
     break;
     case 4:head=insert_end(head);
     break;
     case 5:head=insert_at_pos(head);
     break;
     case 6:head=del_beg(head);
     break;
     case 7:head=del_end(head);
     break;
     case 8:head=del_at_pos(head);
     break;
     case 9:head=reverse_dll(head);
     break;
     case 10:printf("thank you\n");
     break;
     default:printf("try again\n");
    }
    
    }while(val!=10);

    return 0;

  }
  struct node *create_dll(struct node *head){
    head=0;
    struct node *temp;
    int num;
    printf("entre data /-1 to stop\n");
    scanf("%d",&num);
    while(num!=-1){
    
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
    }
    else{
    //tail=temp=head;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    printf("enter to data continue /-1 to stop:\n");
    scanf("%d",&num);
  }
  return head;
  
  
  }
  struct node *display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return head;
  }
  struct node *insert_beg(struct node *head){
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        
        
        return head;
  }
  struct node *insert_end(struct node *head){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    // temp->next=newnode;
    // newnode->prev=temp;
    // temp=newnode;



return head;
    
  }
  struct node *insert_at_pos(struct node *head){
    struct node *newnode;
    int pos,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter position\n");
    scanf("%d",&pos);
    if(pos<1||pos>15)
    printf("INVALID POSTION\n");
    // else if(pos==1){
    //   insert_beg();
    // }
    
    else{
      struct node *temp,*nextnode;
      temp=head;
      printf("enter data\n");
      scanf("%d",&newnode->data);
      while(i<pos-1){
        temp=temp->next;
        i++;
      }
      // nextnode=temp->next;
      // newnode->prev=temp;
      // newnode->next=temp->next;
      // temp->next=newnode;
      newnode->next=temp->next;
      temp->next->prev=newnode;
      temp->next=newnode;
      newnode->prev=temp;
    }
    return head;
  }
struct node *del_beg(struct node *head){
  struct node *temp;
  temp=head;
  head=head->next;
  head->prev=0;
  free(temp);
  return head;
}
struct node *del_end(struct node *head){
  struct node *temp;

  if(tail==0)
  printf("list is empty");
  else{
    
   temp=tail;
    tail->prev->next=0;
    tail=tail->prev;
    free(temp);
  }
  return head;
}
struct node *del_at_pos(struct node *head){
  struct node *temp;
  int pos,i=1;
  printf("enter position\n");
  scanf("%d",&pos);
  // if(i==1){
  //   del_beg();
  // }
  
  temp=head;
  
  while(i<pos){
    temp=temp->next;
    i++;
  }
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  free(temp);
  return head;
}
struct node *reverse_dll(struct node *head){
  struct node *current,*nextnode;
  current=head;
  printf("\nbefore %d\t%d\n\n",head->data,tail->data);
  
  while(current!=0){
    nextnode=current->next;
    current->next=current->prev;
    current->prev=nextnode;
    current=nextnode;

  }
  current=head;
  head=tail;
  tail=current;
  printf("after %d\t%d\n",head->data,tail->data);
  return head;

}