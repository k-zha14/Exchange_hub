#include <iostream>
#include <cstring>
using namespace std;
//define structure vector
struct Myvector
{
	long x,y;
};
//
int crossv(Myvector a, Myvector b){	
	if ((a.x*b.y - b.x*a.y)<=0)
	{
		return 1;
	} else{
		return 0;
	}
}
//output the zone of node
int* zone(Myvector *line, Myvector *node, int n, int m){
	int *out = new int[m];
	memset(out,0,4*m);
	Myvector temp;
	for(int i =0; i<m; i++){
		int flag = 0, hi=n, mi, lo=0;
		while ( hi > lo)
		{
			mi = (hi + lo) >> 1;
			//calculate the node vector
			temp.x = node[i].x;
			temp.y = line[mi].y + node[i].y;
			flag = crossv(temp, line[mi]);
			flag >0 ? lo = mi+1 : hi = mi;
		}
		out[i] = lo;
	}
	return out;
}
//main function
int main(){
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	//input setting nums
	int n, m;
	scanf("%d %d", &n, &m);
	//initialize basical space
	Myvector *line = new Myvector[n];
	Myvector *node = new Myvector[m];
	//int *out = new int[m];
	for (int i = 0; i < n; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		line[i].x = x;
		line[i].y = -y;
	}
	for (int i = 0; i < m; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		node[i].x = x;
		node[i].y = y;
	}
	int *out = zone(line,node,n,m);
	//output
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", out[i]);
	}
	system("pause");
}
