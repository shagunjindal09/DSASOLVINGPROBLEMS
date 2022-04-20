#include<stdio.h>
#include<conio.h>

typedef struct node{
    int info;
    struct node *next;
}node;
int main()
{
    int ch;
    node *head=NULL,*ptr,*temp;
    int data;
    while(1){
        printf("Menu\n");
        printf("1. insert at beg\n2. Traversing\n 3. insert at end\n 4. searching\n5. insert after element\n6.exit\n");
        printf("\nenter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter the element you want to insert");
            scanf("%d",&data);
            temp=(node *)malloc (sizeof(node));
            temp->info=data;
            if(head!=NULL){
                temp->next=head;
            }
            else{
                temp->next=NULL;
            }
            head=temp;
            printf("successfully insertred");
            break;
            case 2:
            temp=head;
        while(temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
        break;

        case 3:
        temp=head;
        printf("enter data you want to insert");
        scanf("%d",&data);
        ptr=(node *)malloc (sizeof(node));
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        break;

        case 4:
        temp=head;
        printf("enter the data you want to search");
        scanf("%d",&data);
        if(temp==NULL){
            printf("no data found\n");

        }
        while(temp!=NULL){
            if(data==temp->info){
                printf("data found\n");
                break;
            }
            else{
                temp=temp->next;
            }
        }
    break;
    case 5:
   printf("enter the data you want to insert\n");
   scanf("%d",&data);
   ptr=head;
   if(ptr==NULL){
       printf("No data found");
       break;
   }
   while(ptr!=NULL){
       if(data==ptr->info){
           break;
       }
       ptr=ptr->next;
   }
   if(ptr==NULL){
       printf("no element found");
   }
   else{
       printf("enter the data");
       scanf("%d",&data);
       temp=(node*) malloc(sizeof(node));
       temp->info=data;
       temp->next=ptr->next;
       ptr->next=temp;
       printf("insert node successfully\n");
   }
    break;


    case 6:exit(1);
          break;

     default:
    printf("you entered the wrong");
    }

        }
    
    return 0;
}
