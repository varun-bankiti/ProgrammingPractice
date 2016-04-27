/*
Program to find the Daimeter of a Binary Tree.

Author: Varun Kumar Reddy B
*/

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node * left;
	node * right;
}Node;
int daimeterOfTree(Node * node, int * height){
	if (node==NULL){
		*height=0;
		return 0;
	}
	int leftDiameter=0,rightDiameter=0,leftHeight=0,rightHeight=0;
	leftDiameter=daimeterOfTree(node->left,&leftHeight);
	rightDiameter==daimeterOfTree(node->right,&rightHeight);
	*height=max(leftHeight,rightHeight)+1;
	return max(leftHeight+rightHeight+1,max(leftDiameter,rightDiameter));
}
Node* newNode(int data){
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
int main(){
  Node * root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5); 
  root->right->left = newNode(6);
  root->right->right = newNode(7); 
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9); 
  root->left->right->left = newNode(10); 
  root->left->right->right = newNode(11); 
  root->right->left->left = newNode(12);
  root->right->left->right = newNode(13); 
  root->right->right->left = newNode(14); 
  root->right->right->right = newNode(15); 
  int height=0;	
  cout <<"Daimeter of Tree is: "<<daimeterOfTree(root,&height)<<endl;
  
return 0;
}
