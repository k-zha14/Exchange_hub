#include <iostream>
#include "Stack.h"

using namespace std;
struct point
{
	int x,y;
};

int crossMulti(){

}
int distance(){
    
}
int main(){
	int n,k=0;
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	scanf("%d",&n);
    Stack<node> s(n);
	point* glist = new point[n];
	for(int i=0;i<n;i++) {
        scanf("%d %d", &glist[i].x, &glist[i].y);
    }
    //find thi begin point, pay attention to this swap
    for (int i = 1; i < n ; i++) {
        if((glist[i].y<glist[k].y)||(glist[i].y==glist[k].y&&glist[i].x<glist[k].x))
            k=i;
    }
    point temp = glist[0];
    glist[0] = glist[k];
    glist[k] = temp;
    //list by the angle


}
