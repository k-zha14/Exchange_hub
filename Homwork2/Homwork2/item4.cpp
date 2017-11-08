#include <iostream>
#include "List.h"
#include <cstring>

using namespace std;

struct doublevalue
{
	int a,b;
};

int main(){
	int n,max=0;
	List<int> a;
	List<doublevalue> ashadow;
	scanf("%d", &n);
	char code[2];
	for(int i=0;i<n;i++){
		scanf("%s", &code);
		switch (code[0])
		{
		case 'E':
			{
			int temp;
			scanf("%d",&temp);
			a.PushFront(temp);
			if(i==0){
				doublevalue point;
				point.a = temp;
				point.b = 1;
				ashadow.PushFront(point);
			}
			else{
				doublevalue point;
				point.a = temp;
				point.b = 1;
				doublevalue top = ashadow.front();
				while ((point.a >= top.a)&&(ashadow.size()>0))
				{
					ashadow.PopFront();
					point.b +=top.b;
					top = ashadow.front();
				}
				ashadow.PushFront(point);
			}
			break;
			}
		case 'D':
			{
			int backup = a.PopBack();
			doublevalue top2 = ashadow.PopBack();
			if(top2.b>1){
				top2.b--;
				ashadow.PushBack(top2);
			}
			printf("%d\n",backup);
			break;
			}
		case 'M':
			{
			doublevalue top3 = ashadow.PopBack();
			printf("%d\n",top3.a);
			ashadow.PushBack(top3);
			break;
			}
		}

	}
	//system("pause");
}
