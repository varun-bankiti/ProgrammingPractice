/*
Program to print the Level order traversal of a binary tree in spiral form.

Author: Varun Kumar Reddy B
*/

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node * left;
	node * right;
}Node;
void levelOrder(Node * node){
	if(node==NULL)return;
	queue<Node *>q;
	q.push(node);
	while(!q.empty()){
		Node * tmp=q.front();
		q.pop();
		cout <<tmp->data<<" ";
		if(tmp->left!=NULL)q.push(tmp->left);
		if(tmp->right!=NULL)q.push(tmp->right);
	}
	cout <<endl;
}
void levelOrderSpiral(Node * node){
	if(node==NULL)return;
	deque<pair<Node *, int> > d;
	int level=0;
	d.push_back(make_pair(node, level));
	while(!d.empty()){
		if(level&1){
			while(level==d.front().second){
				Node * tmp=d.front().first;
				cout <<tmp->data<<" ";
				if(tmp->left!=NULL)d.push_back(make_pair(tmp->left,level+1));
				if(tmp->right!=NULL)d.push_back(make_pair(tmp->right,level+1));
				d.pop_front();			
			}
		}
		else{
			while(level==d.back().second){
				Node * tmp=d.back().first;
				cout <<tmp->data<<" ";
				if(tmp->right!=NULL)d.push_front(make_pair(tmp->right,level+1));
				if(tmp->left!=NULL)d.push_front(make_pair(tmp->left,level+1));
				d.pop_back();			
			}
		}
		level++;
	}
	cout <<endl;
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
  cout <<"Level Order: ";	
  levelOrder(root); 
  cout <<"Level Order in  Sprial Form: ";
  levelOrderSpiral(root); 
return 0;
}
