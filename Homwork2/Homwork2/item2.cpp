#include <iostream>
using namespace std;
struct point
{
	int x,y;
};

int main(){
	int n;
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	scanf("%d",&n);
	point* glist = new point[n];
	for(int i=0;i<n;i++){
		scanf("%d %d",&glist[i].x,&glist[i].y);
	}


}
