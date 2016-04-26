/*
Program to print Lowest Common Ancestor of Two given nodes in a Binary Search Tree.

Author: Varun Kumar Reddy B

*/

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node * left;
	node * right;
}Node;

Node * lowestCommonAncestor(node * root, int n1, int n2){
	while(root!=NULL){
		if(root->data >n1 && root->data>n2)
			root=root->left;
		else if(root->data<n1 && root->data<n2)
			root=root->right;
		else
			break;
	}	
	return root;
}
Node* newNode(int data){
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
int main(){
	Node *root        		 = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    Node *t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

return 0;
}
