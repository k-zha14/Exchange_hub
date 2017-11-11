#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define eps 1e-15

struct point
{
	int x,y;
	double ang;
	long leng;
};

long long crossMulti(point a, point b, point c){
    return 1LL*(a.x-c.x)*(b.y-c.y) - 1LL*(b.x-c.x)*(a.y-c.y);
}
long long dis(point a, point b){
    return 1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y);
}
double calAngle(point a, point b, point c){
	if((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y) == 0)
		return -1;
    return ((double)(a.x-c.x)*(double)(b.y-c.y)-(double)(b.x-c.x)*(double)(a.y-c.y))/sqrt(double((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y)));
}
point p0;
int compare(const void *a, const void *b){
    point aa = *((point *)a);
    point bb = *((point *)b);
    long long result = crossMulti(aa, bb, p0);
    if(result<0){
        return 1;
    }else if(result>0){
        return -1;
    }else{
        if(aa.leng>bb.leng){
            return 1;
        }else if(aa.leng<bb.leng){
            return -1;
        }else{
            return 0;
        }
    }
    return 0;
}
int main(){
	int n,k=0;
    point temp;
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	// scanf("%d",&n);
    freopen(NULL, "rb", stdin);
    
    fread(&n, sizeof(int), 1, stdin);
    point* glist = new point[n];

    int *tmp = new int[2 * n];
    fread(tmp, sizeof(int), 2 * n, stdin);
    for (int i = 0; i < n;i++) {
        glist[i].x = tmp[2*i];
        glist[i].y = tmp[2*i+1];
    }
    //find the littlest point, pay attention to this swap,ok!
    for (int i = 1; i < n ; i++) {
        if((glist[i].y<glist[k].y)||((glist[i].y==glist[k].y)&&(glist[i].x<glist[k].x)))
            k=i;
    }
    temp = glist[0];
    glist[0] = glist[k];
    glist[k] = temp;

    p0 = glist[0];
    //calulate every poing angle and length and then
	point stand = glist[0];
	stand.y++;
	for(int i =1; i< n;i++){
		glist[i].leng = dis(glist[i],glist[0]);
	}
	//quick sort
    qsort(glist + 1, n - 1, sizeof(point), compare);
    //initial pop in
    point* s = new point[n];
    int top = 0;
    for(int i = 0; i < 3; i++){
        s[top++] = glist[i];
    }
    //very important
    while (crossMulti(s[0],s[1],s[2])==0){
        s[1] = s[2];
        s[2] = glist[top++];
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
    return  0;
}
