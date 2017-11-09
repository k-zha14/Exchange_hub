#include <iostream>

using namespace std;
struct point
{
	int x,y;
};

int crossMulti(point a, point b, point c){
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int distance(point a, point b){
    return (a.x-b.x)^2 + (a.y-b.y)^2;
}
int main(){
	int n,k=0;
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	scanf("%d",&n);
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
    for (int j = 1; j < n-1; j++) {
        k=j;    //set the initial point
        for(int m = j+1; m < n; m++){
            if((crossMulti(glist[m],glist[k],glist[0])>0)||((crossMulti(glist[m],glist[k],glist[0])==0
            &&(distance(glist[k],glist[0]) < distance(glist[m],glist[0]))))){
                k=m;    //dozen points in the same line
            }
        }
        temp = glist[k];
        glist[k] = glist[j];
        glist[j] = temp;
    }
    //initial pop in
    point* s = new point[n];
    int top = 0;
    for(int i = 0; i < 3; i++){
        s[top] = glist[i];
        top++;
    }
    //imitate the Stack
    for(int i = 3; i < n; i++){
        while(crossMulti(glist[i],s[top],s[top-1])>0) //Situation:in the same line?
        top--;
        s[++top] = glist[i];
    }
   for(int i =0 ; i < (top+1) ; i++){
        temp = s[i];
        printf("%d  %d\n",temp.x,temp.y);
    }
    system("pause");
}
