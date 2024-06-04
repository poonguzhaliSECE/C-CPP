#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *next;
};
void insertAtBeg(struct node**head,int data)
{
 struct node*nn;
 nn=(struct node*)malloc(sizeof(struct node));
 nn->data=data;
 nn->next=NULL;
 if(*head==NULL)
 {
 	*head=nn;
 }	
 else{
 	nn->next=*head;
 	*head=nn;
     }
 void display(struct node*head)
 {
 	if(*head!=NULL)
 	{
 		printf("%d",head->data);
 		head=head->next;
	 }
	 else
	 {
	 	printf("NULL");
	 }
 }
}
int main()
{
  struct node**head=NULL;
  int data;
  scanf("%d",&data);
  insertAtBeg(&head,data);
  display(head);
}
