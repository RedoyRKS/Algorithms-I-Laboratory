#include <bits/stdc++.h>
using namespace std ;

struct node {
	int val ;
	node* next ;
} ;

node* insetAtEnd (node* head, int value) {
	node* t = head ;


	if (head == NULL) {
		//cout << value << " inserted\n" ;
		head = new node() ;
		head->val = value ;
		head->next = NULL ;

		return head ;
		//cout << temp->val ;
	}

	node* n = new node() ;
	while (t->next!= NULL) {
		t = t->next ;
	}

	n->val = value ;
	n->next = NULL ;
	t->next = n ;

	return head ;
}

node* deleTe (node* head, node* de) {
	node* t = head ;

	if (head == de) {
		node* p = head ;
		head = head->next ;
		delete(p) ;
		return head ;
	}

	while (t->next!= de) {
		t = t->next ;
	}

	node* o = t->next ;
	t->next = o->next ;
	delete (o) ;

	return head ;

}

node* search_(node* head, int value) {
	node* t = head ;

	while (t != NULL) {
		if (t->val == value) {
			return t ;
		}
		t = t->next ;
	}
	return NULL ;
}
node* notMoreThanTwo (node* head, int value) {
	node* t = head ;

	if (t == NULL) {
		cout << value << " inserted\n" ;
		head = insetAtEnd(head, value) ;
	}else {
		node* k = search_ (head, value) ;
		if (k != NULL) {
			cout << value << " deleted\n" ;
			head= deleTe (head, k) ;
		}
		else {
			cout << value << " inserted\n" ;
			head = insetAtEnd(head, value) ;
		}
	}

	return head ;

}

int main() {
	int N ;
	cin >> N ;

	//node* head = new node() ;
	node* head = NULL ;
	/*head->val = 2 ;
	head->next = NULL ;*/
	for(int i=0; i<N; i++) {
		int v = rand() % 101;
		head =notMoreThanTwo(head, v) ;
	}
}