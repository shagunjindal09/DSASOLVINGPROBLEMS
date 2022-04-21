#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct nodetype{
int info;
struct nodetype *next;
}node;
void createEmptyList(node **head);
void traverseInOrder(node *head);
void traverseInReverseOrder(node *head);
void InsertAtBeginning(node **head,int item);
void InsertAtEnd(node **head,int item);
void deleteFromBeginning(node **head);
void insertAfterElement(node *head,int item,int after);
node *search(node *head,int item);
void deleteFromEnd(node **head);
//void deleteFromSpecifiedPos

void main(){
node *head;
int choice,element,after,pri;
clrscr();
createEmptyList(&head);
while(1){
printf("operations available are\n");
printf("1.Insert at beginnning\n");
printf("2.traverse in order\n");
printf("3.delete from beginning\n");
printf("4.serach element\n");
printf("5.insertAtEnd\n");
printf("6.traverseinReverseOrder\n");
printf("7.insertafter element\n");
printf("8.delete from end\n");
printf("9.for exit\n");
printf("enter choice 1 or 2 or 3 or 4 or 5 or 6 0r 7or 8 or 9\n");
scanf("%d",&choice);
switch(choice){
case 1:
printf("\n enter element");
scanf("%d",&element);
InsertAtBeginning(&head,element);
break;
case 2:
if(head==NULL)
printf("\nList is empty");
else
traverseInOrder(head);
break;
//printf("press any key to continue");
case 3:
printf("for delete the element from beginning\n");
deleteFromBeginning(&head);
break;
case 4:
printf("search for element");
pri=search(head,element);
printf("%d",pri);
break;

case 5:
printf("enter element");
scanf("%d",&element);
InsertAtEnd(&head,element);
break;
case 6:
if(head==NULL)
printf("\nList is empty");
else
traverseInReverseOrder(head);
printf("\nenter any key to continue");
break;

case 7:
printf("enter element you want to insert\n");
scanf("%d",&element);
printf("after which element\n");

 insertAfterElement(head,element,after);
		   break;
case 8:
deleteFromEnd(&head);
break;

case 9: exit(1);
break;
getch();
break;
}
}
}
void createEmptyList(node **head){
*head =NULL;
}
 void InsertAtBeginning(node **head,int item){
 node *ptr;
 ptr=(node*)malloc(sizeof(node));
 ptr->info=item;
 if(*head==NULL)
 ptr->next=NULL;
 else
 ptr->next=*head;
 *head=ptr;
 }
 void traverseInOrder(node *head){
 while(head!=NULL){
 printf("\n%d",head->info);
 head=head->next;
 }
 }
 void deleteFromBeginning(node **head){
 node *ptr;
 if(*head==NULL){
 return;
 }
 else
 {
 ptr=*head;
 *head= ptr->next;
 free(ptr);
 }
 }
 node *search(node *head,int item){
 scanf("%d",&item);
 while((head!=NULL) && (head->info!=item))
 head=head->next;
 return head;
 }
 void InsertAtEnd(node **head,int item){
 node *ptr,*loc;
 ptr=(node*)malloc(sizeof(node));
 ptr->info=item;
 ptr->next=NULL;
 if(*head==NULL)
 *head=ptr;
 else{
 loc=*head;
 while(loc->next!=NULL)
 loc=loc->next;
 loc->next=ptr;
 }
 }
 void traverseInReverseOrder(node *head){
 if(head->next!=NULL)
 {
 traverseInReverseOrder(head->next);
 }
 printf("\n %d",head->info);
 }
 void insertAfterElement(node *head,int item,int after){
 node *ptr,*loc;
 loc=search(head,after);
 if(loc==(node*)NULL)
 return;
 ptr=(node*)malloc (sizeof(node));
 ptr->info=item;
 ptr->next=loc->next;
 loc->next=ptr;
 }
 void deleteFromEnd(node **head){
 node *ptr,*loc;
 if(*head==NULL)
 return;
 else if((*head)->next==NULL)
 {
 ptr=*head;
 *head=NULL;
 free(ptr);
 }
 else
 loc=*head;
 ptr=(*head)->next;
 while(ptr->next!=NULL){
 loc=ptr;
 ptr=ptr->next;
 }
 loc->next=NULL;
 free(ptr);
 }
