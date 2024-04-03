#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertNode(struct node **head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : " );
    scanf("%d", &newnode -> data);
    newnode -> next = 0;
    if(*head == 0){
        *head = newnode;
    }
    else{
        struct node *temp = *head;
        while(temp -> next != 0){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

void mergeList(struct node *head1, struct node *head2, struct node **mhead){
    struct node *ptr1 = head1, *ptr2 = head2;
    *mhead = (struct node *)malloc(sizeof(struct node));
    struct node *ptr3 = *mhead;

    // For first element
    if(ptr2 -> data > ptr1 -> data){			
		ptr3->data=ptr1->data;
		ptr1=ptr1->next;           
    }
    else{	
        ptr3->data=ptr2->data;
        ptr2=ptr2->next;
	}

	// For remaining elements
    while(ptr1 != 0 && ptr2 != 0){
        if(ptr2 -> data > ptr1 -> data){
            ptr3 -> next = ptr1;
            ptr1 = ptr1 -> next;
        }
        else{
            ptr3 -> next = ptr2;
            ptr2 = ptr2 -> next;
        }
        ptr3 = ptr3 -> next;
    }
        
    while(ptr1 != 0){
        ptr3 -> next = ptr1;
        ptr1 = ptr1 -> next;
        ptr3 = ptr3 -> next;
    }
    while(ptr2 != 0){
        ptr3 -> next = ptr2;
        ptr2 = ptr2 -> next;
        ptr3 = ptr3 -> next;
    }

    ptr3 -> next = 0;
}


void display(struct node *head){
    if(head == 0){
        printf("List is empty\n");
        return;
    }
    printf("The list is : ");
    struct node *temp = head;
    while(temp != 0){
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    struct node *head1, *head2, *mergedListHead;
    head1 = head2 = 0;
    insertNode(&head1);
    insertNode(&head1);
    insertNode(&head1);
    insertNode(&head2);
    insertNode(&head2);
    insertNode(&head2);
    display(head1);
    display(head2);
    mergeList(head1, head2, &mergedListHead);
    display(mergedListHead);
}