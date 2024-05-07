//3.circular_linked

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;

}*head,*tail;
struct node *head=NULL;
struct node *create_cll(struct node *);
struct node *display(struct node*);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node*);
 struct node *insert_pos(struct node *);
 struct node *del_beg(struct node*);
 struct node *del_end(struct node *);
 struct node *del__pos(struct node*);
 //struct node *length_ll(struct node*);
 struct node *reverse_cll(struct node*);
int main(){
    int val;
        do{
   printf("***MAIN--MENU***\n1.create a circular linked list\n2.display circular linked list\n3.insert at beg\n4.insert at end \n5.insert at position\n6.delete at beg\n7.delete at eng\n8.delete at pos.\n9.reverse doubly linked list\n10.exit ");
    scanf("%d",&val);
    switch(val){
      case 1:
     head=create_cll(head);
     printf("circular liked list created\n display values:\n");
     break;
     case 2:
     head=display(head);
     break;
     case 3:
     head=insert_beg(head);
     break;
     case 4:head=insert_end(head);
     break;
     case 5:head=insert_pos(head);
     break;
     case 6:head=del_beg(head);
     break;
     case 7:head=del_end(head);
     break;
     case 8:head=del__pos(head);
     break;
     case 9:head=reverse_cll(head);
     break;
     case 10:printf("thank you\n");
     break;
     default:printf("try again\n");
    }
    
    }while(val!=10);

    return 0;

  
}
struct node *create_cll(struct node *head){
 head =0;
 struct node *newnode;
 int num;
 printf("enter data \n");
 scanf("%d",&num);
 while(num!=-1){
  newnode=(struct node*)malloc(sizeof(struct node));

  newnode->data=num;
  if(head==0){
    tail=head=newnode;
    tail->next=head;
  }
  else{
    tail->next=newnode;
    tail=newnode;
    tail->next=head;
  }
  printf("enter a data/ -1 to stop\n");
  scanf("%d",&num);
 }
 return head;
}

 struct node *display(struct node *head){
        struct node *temp;
        if(head==0)
        printf("empty list:\n");
        else{
            temp=head;
            while(temp->next!=head){
                printf("%d\t",temp->data);
                temp=temp->next;
            }
            printf("%d\n",temp->data);
     printf("diplayed\n");
        } 
 
    return head;
}
struct node *insert_beg(struct node *head){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    tail->next=newnode;
    return head;
}
struct node *insert_end(struct node *head){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    tail->next=newnode;
    newnode->next=head;
return head;
}
struct node *insert_pos(struct node *head){
 struct node *newnode,*nextnode,*temp;
 int pos,i=1;
 temp=head;
 printf("enter pos:\n");
 scanf("%d",&pos);
 if(pos<1||pos>15)
 printf("invalid position\n");
 else{
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("enter data\n");
 scanf("%d",&newnode->data);
 while(i<pos-1){
    temp=temp->next;
    i++;
 }
 nextnode=temp->next;
 newnode->next=nextnode;
 temp->next=newnode;
 temp=newnode;
 }
 return head;
}
struct node *del_beg(struct node *head){
 struct node *temp;
 temp=head;
 head=head->next;
 tail->next=head;
 free(temp);


return head;
}
 struct node *del_end(struct node *head){
struct node *temp,*prev;
temp=head;
while(temp->next!=head){
    prev=temp;
    temp=temp->next;
}
prev->next=head;
free(temp);
 
 
return head;
        }
struct node *del__pos(struct node *head){
    struct node *temp,*prev;
    temp=head;
int pos,i=1;
    printf("enter position:\n");
    scanf("%d",&pos);
    if(pos<1||pos>15)
    printf("invalid position");
    else{
        while(i<pos){
            prev=temp;
                temp=temp->next;
                i++;
        }
        prev->next=temp->next;
        free(temp);

    }
      return head;
  }
  struct node *reverse_cll(struct node *head){
    struct node *prev,*nextnode,*current;
    current=tail->next;
    nextnode=current->next;           //reverse unable to process...
    printf("\nbefore \n%d\t%d\n",current->data,tail->data);
    if(tail==0)
    printf("empty list:\n");
    else{
        while(current!=tail){
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
    printf("\nafter \n%d\t%d\n",current->data,tail->data);

    return head;
    
  }
