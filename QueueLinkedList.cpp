#include <iostream>
using namespace std;
struct N{
	int data;
	N* next;
	N(int d)
	{
		data=d;
		next=NULL;
	}
};

struct Queue{
	N *front, *rear;
	Queue()
	{
		front=rear=NULL;
	}

	void enQueue(int x)
	{
		N* temp=new N(x);
		if (rear==NULL){
			front=rear=temp;
			return;
		}
		rear->next=temp;
		rear=temp;
	}
	void deQueue()
	{
		if (front==NULL)
			return;
		N* temp=front;
		front=front->next;
		if (front==NULL)
			rear=NULL;

		delete(temp);
	}
};

int main()
{

	Queue q;
	q.enQueue(100);
	q.enQueue(200);
	q.deQueue();
	q.deQueue();
	q.enQueue(300);
	q.enQueue(400);
	q.enQueue(500);
	q.deQueue();
	cout<<(q.front)->data << endl;
}
