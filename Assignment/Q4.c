#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct node *head, *tail = NULL;


void addNode(int data) {

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = data;
    newNode->next = NULL;


    if(head == NULL) {

        head = newNode;
        tail = newNode;
    }
    else {

        tail->next = newNode;

        tail = newNode;
    }
}


void customSort() {
    struct node *temp = head;
    struct node *head1 = NULL;
    struct node *tail1 = NULL;
    struct node *head2 = NULL;
    struct node *tail2 = NULL;


    while(temp!=NULL) {
        if(temp->val%2!=0) {
            if(head1==NULL) {
                head1 = temp;
                tail1 = temp;
            } else {
                tail1->next = temp;
                tail1 = temp;
            }
        } else {
            if(head2==NULL) {
                head2 = temp;
                tail2 = temp;
            } else {
                tail2->next = temp;
                tail2 = temp;
            }
        }

        temp = temp->next;
    }

    
    tail1->next = NULL;
    tail2->next = NULL;

    
    struct node *current1 = head1, *index1 = NULL;
    int temp1;

    if(head1 != NULL) {
        while(current1 != NULL) {
            
            index1 = current1->next;

            while(index1 != NULL) {
                
                if(current1->val < index1->val) {
                    temp1 = current1->val;
                    current1->val = index1->val;
                    index1->val = temp1;
                }
                index1 = index1->next;
            }
            current1 = current1->next;
        }
    }

    
    struct node *current2 = head2, *index2 = NULL;
    int temp2;

    if(head2 != NULL) {
        while(current2 != NULL) {
            
            index2 = current2->next;

            while(index2 != NULL) {
                
                if(current2->val > index2->val) {
                    temp2 = current2->val;
                    current2->val = index2->val;
                    index2->val = temp2;
                }
                index2 = index2->next;
            }
            current2 = current2->next;
        }
    }

    
    struct node *t = head2;
    while(t->next != NULL) {
        t = t->next;
    }

    if(head2 != NULL) {
        t->next = head1;
    } else {
        head = head1;
    }
}


void display() {

    struct node *current = head;
    if(head == NULL) {
        printf("List is empty \n");
        return;
    }
    while(current != NULL) {

        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);


    for(int i=0; i<n; i++) {
        addNode(rand()%100+1);
    }


    printf("\nMain list: \n");
    display();


    customSort();


    printf("\nSorted list: \n");
    display();


}

