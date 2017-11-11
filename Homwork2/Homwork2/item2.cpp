#include <iostream>

using namespace std;
struct point
{
	int x,y;
};

long long crossMulti(point a, point b, point c){
    return 1ll*((a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y));
}
long long dis(point a, point b){
    return 1ll*(a.x-b.x)^2 + (a.y-b.y)^2;
}
int main(){
	int n,k=0;
    point temp;
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	scanf("%d",&n);
    //fread(&n, sizeof(int), 1, stdin);
    point* glist = new point[n];
/*
    for (int i=0; i<n; i++) {
        fread(&glist[i].x, sizeof(int), 1, stdin);
        fread(&glist[i].y, sizeof(int), 1, stdin);
    }
    */

    for(int i=0;i<n;i++) {
        scanf("%d %d", &glist[i].x, &glist[i].y);
    }

    //find the littlest point, pay attention to this swap,ok!
    for (int i = 1; i < n ; i++) {
        if((glist[i].y<glist[k].y)||((glist[i].y==glist[k].y)&&(glist[i].x<glist[k].x)))
            k=i;
    }
    temp = glist[0];
    glist[0] = glist[k];
    glist[k] = temp;
    //list by the angle,need to improve
    /* this is time-cost is about O(n^2)
    for (int j = 1; j < n-1; j++) {
        k=j;    //set the initial point
        for(int m = j+1; m < n; m++){
            if((crossMulti(glist[m],glist[k],glist[0])>0)||((crossMulti(glist[m],glist[k],glist[0])==0
            &&(dis(glist[m],glist[0]) < dis(glist[k],glist[0]))))){
                k=m;    //dozen points in the same line
            }
        }
        temp = glist[k];
        glist[k] = glist[j];
        glist[j] = temp;
    }
     */

    //initial pop in
    point* s = new point[n];
    int top = 0;
    for(int i = 0; i < 3; i++){
        s[top] = glist[i];
        top++;
    }
    //very important
    while (crossMulti(s[0],s[1],s[2])==0){
        s[1] = s[2];
        s[2] = glist[top];
        top++;
    }
    //imitate the Stack,ok!
    int ttop = 2;
    for(int i = top; i < n; i++) {
        while (crossMulti(glist[i], s[ttop], s[ttop - 1]) >= 0) //Situation:in the same line,add =
            ttop--;
        s[++ttop] = glist[i];
    }
   for(int i =0 ; i < (ttop+1) ; i++){
        point temp = s[i];
        printf("%d %d\n",temp.x,temp.y);
    }
    //system("pause");
    return  0;
}
