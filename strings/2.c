#include<stdio.h>
struct node{
    int data;
    struct node *next;
}*tail;
struct node *start=NULL;
struct node *create(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_pos(struct node *start);
struct node *del_beg(struct node *start);
struct node *del_end(struct node *start);
struct node *del_pos(struct node *start);
int main(){
 int op;
 do{
    printf("1.crreate cll\n2.display\n3.insert_beg\n4.insert_end\n5.insert_pos\n6.del_beg\n7.del_end\n8.del_pos\n9.exit");
 
 
    printf("enter choice:");
 scanf("%d",&op);
 if(op==1){
    start=create(start);
 }
 else if(op==2){
    start=display(start);
 }
else if(op==3){
    start=insert_beg(start);
 }
else if(op==4){
    start=insert_end(start);
 }
else if(op==5){
    start=insert_pos(start);
 }
else if(op==6){
    start=del_beg(start);
 }
 else if(op==7){
    start=del_end(start);
 }
 else if(op==8){
    start=del_pos(start);
 }
else
printf("try again");
 }while(op!=9);

    return 0;
}
struct node *create(struct node *start){
 struct node *newnode;
 int num;
 printf("enter number/-1 to stop\n");
 scanf("%d",&num);
 while(num!=-1){
 newnode=(struct node*)malloc(sizeof(struct node));
//  printf("enter data");
//  scanf("%d",&newnode->data);
newnode->data=num;
if(start==NULL){
    start=tail=newnode;
   // tail->next=start;
}
else{
   // current=start;
tail->next=newnode;
tail=newnode;
//tail->next=start;
}
tail->next=start;

 printf("enter number/-1 to stop\n");
 scanf("%d",&num);
 }

    return start;
}
struct node *display(struct node *start){
    struct node *current;
    current=start;
    while(current->next!=start){
        printf("%d\t",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
    return start;
}
struct node *insert_beg(struct node *start){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&newnode->data);
    newnode->next=start;
    start=newnode;
    tail->next=start;

    return start;
}
struct node *insert_end(struct node *start){
    struct node *newnode;
    printf("enter data");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    tail->next=newnode;
    tail=newnode;
    tail->next=start;
    return start;
}
struct node *insert_pos(struct node *start){
    int pos,i=1;
    struct node *temp,*prev,*newnode;
    temp=start;
    printf("enter position");
    scanf("%d",&pos);
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&newnode->data);
    while(i<pos){
        prev=temp;
        temp=temp->next;
        i++;
        }
        prev->next=newnode;
        newnode->next=temp;

        return start;

}
struct node *del_beg(struct node *start){
    struct node *temp;
    temp=start;
    start=start->next;
    tail->next=start;
    free(temp);
    return start;
}
struct node *del_end(struct node *start){
    struct node *prev,*temp;
    temp=start;
    while(temp->next!=start){
        prev=temp;
        temp=temp->next;
    }
    prev->next=start;

    free(temp);
    return start;
}
struct node *del_pos(struct node *start){
    int pos,i=1;
    struct node *temp,*prev;
    temp=start;
    printf("enter position");
    scanf("%d",&pos);
    while(i<pos){
        prev=temp;
        temp=temp->next;
        i++;
        }
      prev->next=temp->next;
        return start;

}
