/* This program only just for circular singly linked list 								 */
/* Firstly, it asks the user number of element of linked list and creates a linked list  */
/* and then asks the user operation that wants to delete or insert 						 */
/* after it do operation according to user selection... also display and				 */
/* determine size of list before processing and after processing...						 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* decleration for linked list */
typedef struct node{
    char current[3];
    int volts;
    struct node * next;
}node_t;
/* Function prototypes */
node_t* create_node(int n);
int size_list(node_t *first);
void display_list(node_t *first);
node_t* insert_node(node_t* head,int size,char *current, int volts, int position);
node_t* delete_node(node_t* head,int size,int position);

int main(){
	node_t *head, *new_head, *del_node;
	char current[3];
    int i,n,size,place,choice,volt;

    printf("To create enter how many nodes >> ");
    scanf("%d",&n);
    head=create_node(n);
    size=size_list(head);
	printf("\nEnter 1 for inserting or 2 for deletion>> ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			    printf("Enter a position to insert to linked list >> ");
				scanf("%d",&place);
				printf("Now enter current and volt >>\n");
				scanf("%s",current);
				scanf("%d",&volt);
				new_head=insert_node(head,size,current,volt,place);
    			printf("\nSize of new list= %d\n",size_list(new_head));
   			   	display_list(new_head);
   			   	break;
		case 2:
				printf("Enter a position to deletion to linked list >> ");
				scanf("%d",&place);
				del_node=delete_node(head,size,place);
    			size_list(del_node);	
   			   	display_list(del_node);
   			   	break;
		default:	
				printf("Wrong choice!\n"); 
				break;  	
	}

    return 0;
    free(head);
    free(new_head);
}

node_t* create_node(int n){
	
    int i;
	node_t *head, *p, *new;
    head=(node_t*)malloc(sizeof(node_t));
    head->next=NULL;
    printf("Current and volts >>\n");
	scanf("%s",head->current);
	scanf("%d",&(head->volts));
	p=head;
	for(i=2;i<=n;++i){
		new=(node_t*)malloc(sizeof(node_t));
		new->next=NULL;
		printf("Current and volts >>\n");
		scanf("%s",new->current);
		scanf("%d",&(new->volts));
		p->next=new;
		p=new;
	}
	p->next=head;
	return head;
}

int size_list(node_t *first){

    node_t *temp;
    int i=1;
    temp=first;
    first=first->next;
    while(first!=temp){
        first=first->next;
        ++i;
    }
    printf("\nSize of linked list= %d\n",i);
    return i;
}
void display_list(node_t *first){
	node_t *head;
	head=first;
	printf("%s  %d\n",first->current,first->volts);
	first=first->next;	
	while(first!=head){
		printf("%s  %d\n",first->current,first->volts);
		first=first->next;	
	}	
}

node_t* insert_node(node_t* head,int size,char *current, int volts, int position){

	node_t *old, *new, *last;
	int i=2;

	if(position==size+1){
		old=head;
		while(old->next!=head)
			old=old->next;
		old->next=(node_t*)malloc(sizeof(node_t));
		strcpy(old->next->current,current);
		old->next->volts=volts;
		old->next->next=head;
	}	
	else if(position==1){
		last=head;
		while(last->next!=head)
			last=last->next;
		new=(node_t*)malloc(sizeof(node_t));
		strcpy(new->current,current);
		new->volts=volts;
		new->next=head;
		head=new;
		last->next=head;

	}
	else{

		new=(node_t*)malloc(sizeof(node_t));
		strcpy(new->current,current);
		new->volts=volts;
		new->next=NULL;
		old=head;
		for(i=2;i<=position-1;++i)
			old=old->next;
		new->next=old->next;
		old->next=new;
	}
	
	return head;
}
node_t* delete_node(node_t* head,int size,int position){
	
	node_t *old, *temp;	
	int i;
	if(position==1){
		old=head;
		while(old->next!=head)
			old=old->next;
		old->next=head->next;	
		free(head);
		head=old->next;
		/*old=head;
		head=head->next;
		free(old);
		temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=head;*/		
	}
	else if(position==size){
		old=temp=head;
		while(old->next!=head){
			temp=old;
			old=old->next;
		}	
		temp->next=head;
		free(old);
	}
	else{
		old=head;
		for(i=2;i<=position-1;++i)
			old=old->next;
		temp=old->next;	
		old->next=temp->next;
		free(temp);
	}
	printf("head: %s  %d\n",head->current,head->volts);		
	return head;

}






