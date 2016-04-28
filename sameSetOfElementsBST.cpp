/*
Program to check whether two given Binary Search Trees have same set of elements(structure may be different).

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

bool inOrder(Node *root1,Node * root2){
	stack<Node *> s1,s2;
	Node * current1=root1;
	Node * current2=root2;
	int v1,v2;
	int switc=1;
	int over1=0,over2=0;
   while (true){
	if(switc==1){
		if(current1!=NULL){
		  s1.push(current1);                                               
		  current1 = current1->left;  
		}		    
		else                                                             
		{
		  if (!s1.empty())
		  {
			current1=s1.top();
			s1.pop();
			v1=current1->data;
			switc=2;
		    current1=current1->right;
		  }
		  else{
			switc=2;	
			over1=1;
			}
		}
	}
	else if(switc==2){
		if(current2!=NULL){
		  s2.push(current2);                                               
		  current2 = current2->left;  
		}
		    
		else                                                             
		{
		  if (!s2.empty())
		  {
			current2=s2.top();
			s2.pop();
			v2=current2->data;
			switc=3;
		    current2=current2->right;
		  }
		  else{
			over2=1;
			switc=3;
			}
		}		
	}
	else if(switc==3){
		if(v1!=v2 || (over1^over2))return false;
		else if(over1&&over2)return true;
		else switc=1;
	}
  }
  return false;
}     
 
int main(){
  Node *root1 = newNode(3);
  root1->left = newNode(2);
  root1->left->left = newNode(1); 
  Node *root2 = newNode(2);
  root2->left = newNode(1);
  root2->right = newNode(3);  
// root2->right->right = newNode(5);
  cout<<(inOrder(root1,root2)?"YES":"NO")<<endl; 
  return 0;
}
