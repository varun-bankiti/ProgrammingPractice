/*
Program to reverse a given linked list without recursion

Author: Varun Kumar Reddy B

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node * next;
}Node;

Node * reverseList(Node * head){
	Node * current=head;
	Node * next; Node * previous=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=previous;
		previous=current;
		current=next;
	}
	return previous;
}

void printList(Node * head){
	while(head!=NULL){
		cout <<head->data<<" ";
		head=head->next; 
	}
	cout <<endl;
}
Node* newNode(int data){
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}
int main(){
  Node * root = newNode(1);
	root->next=newNode(2);	
	root->next->next=newNode(3);
	root->next->next->next=newNode(4);
	root->next->next->next->next=newNode(5);
	cout <<"Original list: ";
	printList(root);
	root=reverseList(root);
	cout <<"Reversed list: ";
	printList(root);
return 0;
}
