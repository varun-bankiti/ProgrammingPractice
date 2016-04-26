/*
Program to print out all root-to-leaf paths one per line of the given Binary Tree.

Author: Varun Kumar Reddy B
*/

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node * left;
	node * right;
}Node;

void printPaths(Node * node,vector<int> path){
	if(node==NULL)return;
	path.push_back(node->data);
	if(node->left==NULL && node->right==NULL){
		for(vector<int>::iterator it = path.begin(); it != path.end(); ++it)
			cout<<*it<<" ";
		cout <<endl;
	}
	else{
		printPaths(node->left,path);
		printPaths(node->right,path);
	}
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
  vector<int>path;
  printPaths(root,path); 
return 0;
}
