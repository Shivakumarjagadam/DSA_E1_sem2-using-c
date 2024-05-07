#include<stdio.h>
#include<stdlib.h>

    struct node{
        int data;
        struct node *next;
    };
    struct node *start=NULL;
    struct node *create_11(struct node *);
    struct node *display(struct node *);
    struct node *insert_beg(struct node*);
    struct node *insert_end(struct node *);
    struct node *insert_mid(struct node *);
    struct node *delete_beg(struct node*);
   struct node *delete_end(struct node*);
    struct node *delete_before(struct node*);
 int main()
 {
        int val;
        do{
            printf("main menu\n1.create a t:\n2.display the t:\n3.insert the node at beginning:\n4.insert node at the end:\n5.insert some where in middle:\n6.delete node atv beginning:\n7.delete node at end:\n8.delete node at some where:\n9.exit");
            scanf("%d",&val);
            switch(val){
                case 1:start=create_11(start);
                printf("t created:\n");
                break;
                case 2:start=display(start);
                break;
                case 3:start=insert_beg(start);
                break;
                case 4:start=insert_end(start);
                break;
                case 5:
                start=insert_mid(start);
                break;
                case 6:
                start=delete_beg(start);
                break;
                case 7:
                start=delete_end(start);
                break;
                case 8:
                start=delete_before(start);
                case 9:
                printf("thank you:\n");
                break;
                default:
                printf("try again....\n");
                break;
                       }             
        }while(val!=9);
        return 0;
 }
struct node *create_11(struct node *start){
        struct node *new_node,*current;
        int num;
        printf("enter -1 to stop\n");
        scanf("%d",&num);
        while(num!=-1){
            new_node=(struct node*)malloc(sizeof(struct node));
            new_node->data=num;
            if(start==NULL){
                new_node->next=NULL;
                start=new_node;
            }
            else{
                current=start;
                while(current->next!=NULL){
                    current=current->next;
                }
                current->next=new_node;
                new_node->next=NULL;
            }
            printf("enter data:");
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
        printf("\n");
        return start;
    }

    struct node *insert_beg(struct node *start){
        struct node *new_node;
        int num;
        printf("enter a number to insert\n:");
        scanf("%d",&num);
        new_node=(struct node*)malloc(sizeof(struct node*));
        new_node->data=num;
        new_node->next=start;
        start=new_node;
        return start;

    }
    struct node *insert_end(struct node *start){
        struct node *new_node,*current;
        new_node=(struct node*)malloc(sizeof(struct node));
        current=start;
        while(current->next!=NULL)
        {
        current=current->next;
        }
    printf("entre data to insert:\n");
    scanf("%d",&new_node->data);
    current->next=new_node;
    new_node->next=NULL;
    return start;
    }
    struct node *insert_mid(struct node *start){
        struct node *new_node,*current,*prev;
        current=start;
        new_node=(struct node*)malloc(sizeof(struct node));
        int val;
        printf("entre elementof the t at where you want to insert the new_node: \n");
        scanf("%d",&val);     
           while(current->data!=val){
            prev=current;
            current=current->next;
        }
        printf("enter data to insert\n");
        scanf("%d",&new_node->data);
        prev->next=new_node;
        new_node->next=current;
        return start;

    }
    struct node *delete_beg(struct node *start){
        // struct node *current,*prev;
        // current =start;
        // while(current->next!=NULL){
        //     prev=current;
        //     current=current->next;
        // }
        // prev->next=NULL;
        // free(current);
        // return start;
        struct node *current;
        current=start;
        start=start->next;
        free(current);
        return start;
    }
struct node *delete_before(struct node *start){
        struct node *prev,*current;
        int val;
        printf("enter an element to delete in t:\n");
        scanf("%d",&val);
        while(current->data!=val){
            prev=current;
            current=current->next;
        }
        prev->next=current->next;
        free(current);
        return start;
    }
struct node *delete_end(struct node *start){
    struct node *current,*prev;
    current=start;
    while(current->next!=NULL){
        prev=current;
        current=current->next;

    }
    prev->next=NULL;
    free(current);
    return start;
}
