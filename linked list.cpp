 struct node{
 	int data;
 	struct node *next;
 };
 struct node *head,*nn,*temp;
 struct node * nn=(struct node*)malloc(sizeof(struct node));
 printf("Enter the data : ");
 scanf("%d",&nn->data);
 nn->data=data;
 nn->next=NULL;
 return nn;
//insertion at begining
 
