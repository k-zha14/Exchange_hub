#include <iostream>
#include "Stack.h"

using namespace std;

struct node
{
	int elem;
	int* left;
	int* right;
};

void binaryTreeOrdering(int* pre,int* post,int length){
	if(length == 1){
		printf("%d\n",pre[0]);
		return;
	}
	int index =0 ;
	for(;index<length;index++){
		if(pre[index] == *(post+length-2))
			break;
	}
	//left
	binaryTreeOrdering(pre+1,post,index-1);
	//output
	printf("%d\n",pre[0]);
	//right
	binaryTreeOrdering(pre+index,post+index-1,length-index);
}

int main(){
	//init
	int n;
	scanf("%d",&n);
	int *pre = new int[n];
	int *post = new int[n];
	for(int i = 0; i<n ; i++){
		scanf("%d",&pre[i]);
	}
	for(int i = 0; i<n ; i++){
		scanf("%d", &post[i]);
	}
	//recursion, maybe not a good idea
	Stack<node> tree;
	while (!tree.isEmpty())
	{

	}
	system("pause");

}
