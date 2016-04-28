/*
Program to find the Width of a Binary Tree.

Author: Varun Kumar Reddy B
*/

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node * left;
	node * right;
}Node;
Node* newNode(int data){
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
int maxWidth(Node *root){
    if (root == NULL)  return 0;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
	long unsigned int maxWidth=s1.size();
    while (!s1.empty() || !s2.empty()){
        while (!s1.empty()){
            struct node *temp = s1.top();
            s1.pop();
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
        while (!s2.empty()){
            struct node *temp = s2.top();
            s2.pop();
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
		maxWidth=max(maxWidth,max(s1.size(),s2.size()));
    }
	return maxWidth;
}
int main(){
	Node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(8);
	root->right->left = newNode(10);
	root->right->right->left  = newNode(6);
	root->right->right->right  = newNode(7);
	cout << "Maximum Width of the Tree is: "<<maxWidth(root)<<endl; 
return 0;
}
