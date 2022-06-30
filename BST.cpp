#include<iostream>
using namespace std;
class N{
	public:
		int data;
		N *left,*right;
	N(int val){
	  data=val;	
	  left=NULL;
	  right=NULL;
	}
};
  
N* insertBST(N *root,int val){
	if(root==NULL){
	  return new N(val);
	}
	else if(val<root->data)
	    root->left=insertBST(root->left,val);
	else
	 	root->right=insertBST(root->right,val);
	return root;
}
N* searchInBST(N* root,int val){
	if(root==NULL)
	 return NULL;
	if(root->data==val)
	  return root;
	else if(root->data>val)
	  return searchInBST(root->left,val);
	else
	  return searchInBST(root->right,val);
}
void inorder(N *root){
	if(root==NULL)
	 return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
N* inoderSucc(N* root){
	N* curr=root;
	while(curr && curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
N* deleteInBST(N* root,int key){
	if(key<root->data)
	  root->left=deleteInBST(root->left,key);
	else if(key>root->data)
	  root->right=deleteInBST(root->right,key);
	else{
		if(root->left==NULL){
			N* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			N* temp=root->left;
			free(root);
			return temp;
		}
		 N* temp=inoderSucc(root->right);
		 root->data=temp->data;
		 root->right=deleteInBST(root->right,temp->data);
	} 
	return root;
}
int main(){
	N *root=NULL;
	cout<<"creating BST"<<endl;
	root=insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,7);
	insertBST(root,2);
	inorder(root);
	cout<<endl<<"searching in BST :"<<endl;
	if(searchInBST(root,7)==NULL)
	  cout<<"key is not present"<<endl;
	else
	  cout<<"key is present"<<endl;
	cout<<"deletingin BST :\n";
	 deleteInBST(root,5);
	inorder(root);
	
}
