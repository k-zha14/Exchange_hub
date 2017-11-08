#include <iostream>
using namespace std;

//definite the double direction chain node 
struct Node
{
	int data;
	Node *pre;
	Node *nex;
};

int main(){
	//accelerate input
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	//initialize the input
	int n,m;
	scanf("%d %d",&n, &m);
	int *code = new int[n];
	for(int i =0; i<n;i++){
		scanf("%d", &code[i]);
	}
	//initialize the head node and selfloop
	Node *head,*next;
	head = new Node();
	head->nex = head;
	head->pre = head;
	next = head;
	for(int i =0;i<n;i++){
		if (i==0)
		{
			head->data = code[i];
		}
		else{
			next = new Node();
			next->data = code[i];
			Node *temp = head->nex;
			head->nex = next;
			next->pre = head;
			next->nex = temp;
			temp->pre = next;
			for(int j=0;j<m;j++){
				head = head->nex;
			}
		}
	}
	//output
	for(int i=0;i<n;i++){
		printf("%d ", next->data);
		next = next->pre;
	}
}
