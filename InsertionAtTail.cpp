#include<iostream>
using namespace std;
class N{
	public:
		int data;
		N* next;
	N(int val){
		data=val;
		next=NULL;
	}
};
void insertNode(N* &head,int val){
	N* n=new N(val);
	if(head==NULL){
		head=n;
		return;
	}
	N* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
void display(N* head){
	N* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int main(){
	N* head=NULL;
	insertNode(head,1);
	insertNode(head,2);
	display(head);
	int n;
	cout<<"enter a value you want insert : ";
	cin>>n;
	insertNode(head,n);
	display(head);
    return 0;
}
