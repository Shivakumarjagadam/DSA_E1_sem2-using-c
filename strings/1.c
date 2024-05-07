#include<stdio.h>
 struct node {
    int data;
    struct node *next;//implementation of single linked list...
     };

struct node *start=NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *insert_pos(struct node*start);
struct node *del_beg(struct node *start);
struct node *del_end(struct node *start);
struct node *del_pos(struct node *start);
struct node *reversell(struct node *start);
struct node *length_ll(struct node *start);
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
     case 5:start=insert_pos(start);
     break;
    case 6:start=del_beg(start);
    break;
    case 7:
    start=del_end(start);
    break;
    case 8:start=del_pos(start);
    break;
    case 9:start=length_ll(start);    //length of linked list....
    break;
    case 10:start=reversell(start);//reverse of linked list..
    break;
    // case 11:printf("thank you\n");
    // break;
    default:printf("try again:\n\n");
    }
    }while(choice!=11);


    return 0;
}
struct node *create(struct node *start){
    int num;
    struct node *newnode,*current;  
    printf("enter number/-1 to stop");
    scanf("%d",&num);
    while(num!=-1){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
   
    if(start==NULL){
        start=current=newnode;
        
    }
    else{
        // current=start;
        // while(current->next!=NULL){
        //     current=current->next;
        // }
        current->next=newnode;
        current=newnode;
        
        
    }
     newnode->next=0;
    printf("enter number/-1 to stop");
    scanf("%d",&num);

    }
    return start;


}
struct node *display(struct node*start){
    struct node*current;
   current=start;
   while(current!=NULL){
    printf("%d\t",current->data);
    current=current->next;

   }
   //printf("%d\n",*current);
   return start;
}
struct node *insert_beg(struct node *start){
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter number:");
scanf("%d",&newnode->data);
newnode->next=start;
start=newnode;
    
    return start;
}
struct node *insert_end(struct node *start){
struct node *newnode,*current;
current=start;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter number:");
scanf("%d",&newnode->data);
while(current->next!=0){
current=current->next;
}
current->next=newnode;
newnode->next=0;

    return start;
}
struct node *insert_pos(struct node*start){
    int pos,i=1;
    struct node *temp,*newnode;
    temp=start;
    printf("enter position");
    scanf("%d",&pos);
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;

    return start;
}
struct node *del_beg(struct node *start){
    struct node *temp;
    temp=start;
    start=start->next;
    free(temp);
    return start;
}
struct node *del_end(struct node *start){
    struct node *temp,*prev;
    temp=start;
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;
    }
    prev->next=0;
    free(temp);
    return start;
}
struct node *del_pos(struct node *start){
struct node *temp,*prev;
temp=start;
int pos,i=1;
printf("enter pos to delete");
scanf("%d",&pos);

while(i<pos){
    prev=temp;
    temp=temp->next;
    i++;
}
prev->next=temp->next;
free(temp);
    return start;
}
struct node *reversell(struct node *start){
    struct node *prev=0,*temp,*nextnode;
    temp=nextnode=start;
    while(nextnode!=0){
        nextnode=nextnode->next;
        temp->next=prev;
        prev=temp;
        temp=nextnode;
    }
    start=prev;
}