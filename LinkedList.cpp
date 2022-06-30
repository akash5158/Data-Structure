#include<iostream>
using namespace std;
class N{
	public:
   		int value;
  		N* next;
};
int main(){
  N* head;
  N* one=new N();
  N* two=new N();
  N* three=new N();
  one->value=1;
  two->value=2;
  three->value=3;
  head=one;
  one->next=two;
  two->next=three;
  three->next=NULL;
  while(head!=NULL){
    cout<<head->value<<" ";
    head=head->next;
  }
}
