#include<stdio.h>
using namespace std;



struct Node
{
int data;
struct Node *next;
};
typedef struct Node node;

//Function prototypes
int selectOption();
node* createNode();
void printList(node *head);
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);
node* insert_nth(node *head, node *nn, int pos);
node* delete_head(node *head);
node* delete_tail(node *head);
node* delete_nth(node *head,int pos);
node* insert_random(node* head);
node* coustomOrder(node* head);


int node_count = 0;

int main()
{
node *head = NULL, *nn;


int ch, pos;
ch = selectOption();

while(ch)
{
if(ch == 1)
{
nn = createNode();
head = insert_head(head, nn);
}
else if(ch == 2)
{
printf("enter position: ");
scanf("%d",&pos);
if(pos >= 1 && pos <= node_count + 1)
{
nn = createNode();
head = insert_nth(head, nn, pos);
}
else
{
printf("invalid position.\n\n");
}

}
else if(ch == 3)
{
nn = createNode();
head = insert_tail(head, nn);
}
else if(ch == 4)
{

head = delete_head(head);
}
else if(ch == 5)
{

head = delete_tail(head);
}

else if(ch == 6)
{
int pos;
cin>>pos;
if(pos>node_count || pos<1)
cout<<"invalid position"< else
head = delete_nth(head,pos);
}
else if(ch == 7)
{
head= insert_random(head);
}
else if(ch == 8)
{
printf("list size: %d\n",node_count);
}
else if(ch == 9)
{
    printf("coustom_order");

}
else
{
printf("invalid option. please try again...\n\n");
}
ch = selectOption();
}
}

int selectOption()
{
int ch;
printf("1. insert (head)\n");
printf("2. insert (nth)\n");
printf("3. insert (tail)\n");
printf("4. delete (head)\n");
printf("5. delete (tail)\n");
printf("6. delete (nth)\n");
printf("7. insert_random \n");
printf("8. print list size\n");
printf("9. coustom_Order\n");
printf("0. exit\n\n");

printf("enter your option: ");
scanf("%d",&ch);
return ch;
}

node* createNode()
{
node *temp;
temp = new node();
temp->next = NULL;
printf("enter value: ");
scanf("%d",&temp->data);
return temp;
}

void printList(node *head)
{
node *temp;
temp = head;

while(temp != NULL)
{
printf("%d ",temp->data);
temp = temp->next;
}
printf("\n\n");
}

node* insert_head(node *head, node *nn)
{
if(head != NULL)
{
nn->next = head;
}
head = nn;
node_count++;
return head;
}

node* insert_tail(node *head, node *nn)
{
if(head == NULL)
{
head = insert_head(head, nn);
}
else
{
node *temp;
temp = head;
while(temp->next != NULL)
{
temp = temp->next;
}
temp->next = nn;
node_count++;
}

return head;
}

node* insert_nth(node *head, node *nn, int pos)
{
if(pos == 1)
{
head = insert_head(head, nn);
}
else if(pos == node_count + 1)
{
head = insert_tail(head, nn);
}
else
{
node *temp;
temp = head;
int i;
for(i = 1; i < pos-1; i++)
{
temp = temp->next;
}
nn->next = temp->next;
temp->next = nn;
node_count++;
}

return head;
}


node* delete_head(node *head)
{ if(head==NULL)
cout<<"Nothing to delete"<
node* temp=head;
head=head->next;
delete(temp);
node_count--;
return head;
}


node* delete_tail(node *head)
{ if(node_count<2)
head=delete_head(head);
else
{
node* temp=head;
while( (temp->next)->next!=NULL)
{
temp=temp->next;
}
node* garbage=temp->next;
temp->next=NULL;
delete(garbage);

node_count--;

}
return head;

}


node* delete_nth(node *head,int pos)
{
if(pos==1)
head=delete_head(head);
else if(pos==node_count)
head=delete_tail(head);nnn
else
{
node* temp=head;
int count=1;
while(pos---2>0)
{
temp=temp->next;
count++;
}
node* garbage=temp;
temp->next=(temp->next)->next;
delete(garbage);
node_count--;

}
return head;

}

node* coustomOrder(node* head)
{
int n,i,val,temp,j,cin;
cout<<"Enter number of value n: ";
cin>>n;
int arr[101]
int arr2[101]
for(int i=1;i<=100; i++) 
{
int val=(rand()%100)+1;
node*temp=new node();
temp->next = NULL;
temp->data = val;
head = insert_tail(head,temp);
arr[val]++
arr2[val]++
}
printList(head);

int max, idx;
for(int i=0; i<n; i++)
{
    max = -99;
    for(int j=1; j<=100; i++){
        if(arr[j]>max){
            max = arr[j];
            val=j;
        }
        
    }

}
for(j=1;i<=max;i++){
    node*temp = new node();
    temp->next = NULL;
    temp->data = val;
    


}







