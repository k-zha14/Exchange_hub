#include <iostream>

using namespace std;

struct node
{
	int elem;
	node *left;
	node *right;
};

struct binTree
{
	node *data;
	int *pre;
	int *post;
	int len;
};
//rebuild the tree
node* rebuildTree(int *pre, int *post, int leng){
	//build root node
	binTree* stack = new binTree[leng];
	int top = 0;
	binTree r,rtemp;
	r.pre = pre;
	r.post = post;
	r.data = new node;
	node* root = r.data;
	r.len = leng;
	stack[top++] = r;
	//go to the loop
	while (top>0)
	{
		r = stack[--top];
		r.data->elem = r.pre[0];
		//special
		if(r.len == 1){
			r.data->left = NULL;
			r.data->right = NULL;
			break;
		}
		int index =0 ;
		for(;index<r.len;index++){
		if(r.pre[index] == *(r.post+r.len-2))
			break;
		}
		//left
		if(index == 2) {
			r.data->left = new node;
			r.data->left->elem = r.pre[1];
			r.data->left->left = NULL;
			r.data->left->right = NULL;
		}
		else
		{
			rtemp.len = index-1;
			rtemp.pre = r.pre+1;
			rtemp.post = r.post;
			rtemp.data = new node;
			r.data->left = rtemp.data;
			stack[top++] = rtemp;
		}

		if((r.len-index)==1){
			r.data->right = new node;
			r.data->right->elem = r.pre[index];
			r.data->right->left = NULL;
			r.data->right->right = NULL;
		}
		else
		{
			rtemp.len = r.len-index;
			rtemp.pre = r.pre+index;
			rtemp.post = r.post+index-1;
			rtemp.data = new node;
			r.data->right = rtemp.data;
			stack[top++] = rtemp;
		}
	
	}
	return root;
}
//mid-traversal without recursion
void printInTree(node* root,int n){
	node* p = root;
	node** stack = new node*[n];
	int top = 0;
	while (!(top == 0)||p)
	{
		while (p)
		{
			stack[top++] = p;
			p = p->left;
		}
		if(!(top == 0)){
			p = stack[--top];
			printf("%d ",p->elem);
			p = p->right;
		}
	}
}

int main(){
	//init
	int n;
	scanf("%d",&n);
	int *pre = new int[n];
	int *post = new int[n];
	for(int i = 0; i<n ; i++){
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i<n ; i++){
		scanf("%d", &post[i]);
	}
	node* root = rebuildTree(pre,post,n);
	printInTree(root,n);
	system("pause");
	return 0;
}
