#include <iostream>

using namespace std;

struct line			//入边
{
	int nodebefore;	//指向前点
	int weight;		//该边权重
    line *next;     //此节点下一入边
	line(){
		next = NULL;
	}
};

struct vertex	   //节点
{
	int nodeid;	   //id号
	int getout;     //出度
	line *inedge;    //入边
	int sumweigh;	//标记权重
	vertex *child;	//记录子节点
	vertex(){
		inedge = NULL;
		sumweigh = 0;
		child = NULL;
	}
	

};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vertex *totalvertex = new vertex[n];
	line *temp = new line[m];
	//stack
	vertex **stack = new vertex*[n+1];
	int top = 0;
	//record the max
	vertex *max = totalvertex;
	//initialize nodeid
	for(int i=0; i<n ; i++){
		totalvertex[i].nodeid = i+1;
		totalvertex[i].getout = 0;
	}
	//establish the graph
	for(int i=0; i<m ; i++){
		int a=0,b=0,c=0;
		scanf("%d %d %d",&a,&b,&c);
		temp[i].nodebefore = a;
		temp[i].weight = c;
		//update getout
		totalvertex[a-1].getout++;
		//update *last
		temp[i].next = totalvertex[b-1].inedge;
		totalvertex[b-1].inedge = temp+i;
	}
	//topologicalsort
	for(int i=0; i<n;i++){
		if(totalvertex[i].getout == 0){
			stack[++top] = totalvertex+i;
		}
	}
	while (top != 0)
	{
		vertex *tempvertex = stack[top--];
		//cout << tempvertex.nodeid;
		while (tempvertex->inedge != NULL)
		{
			int num = tempvertex->inedge->nodebefore - 1;
			totalvertex[num].getout--;
			//update vertex weigh
			int a = tempvertex->inedge->weight+tempvertex->sumweigh;
			int b = totalvertex[num].sumweigh;
			if(a>b){
				totalvertex[num].sumweigh = a;
				totalvertex[num].child = tempvertex;
				//update the max
				if(max->sumweigh < totalvertex[num].sumweigh)
					max = totalvertex + num;
				else if( max->sumweigh == totalvertex[num].sumweigh)
					if(totalvertex[num].nodeid < max->nodeid)
						max = totalvertex + num;
			}
			if (totalvertex[num].getout == 0)
			{
				stack[++top] = totalvertex + num;
			}
			tempvertex->inedge = tempvertex->inedge->next;
		}
	}
	//output
	printf("%d ",max->nodeid);
	while (max->child != NULL)
	{
		printf("%d ",max->child->nodeid);
		max->child = max->child->child;
	}
	return 0;
}
