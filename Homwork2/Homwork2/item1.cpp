#include <iostream>
#include "string"
#include "Stack.h"

using namespace std;
int main(){
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	//input
	int n,m,flag=0,flag2=0;
	scanf("%d %d", &n, &m);
	int *a = new int[n];
	Stack<int> s(m);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	string *txt = new string[2*n];
	for (int i = 0; i < n; i++)
	{
		if((i+1) == s.top()){
			int temp = s.pop();
			char str[12];
			sprintf(str,"%d O\n",temp);
			txt[i+flag] = string(str);
			flag2++;
		}
		else
		{
		while(((i+flag-flag2)<(n-1))&&((i+1)<a[i+flag-flag2])){
			int temp = a[i+flag-flag2];
			//overload
			if(!s.push(temp)){
				cout << "No" << endl;
				system("pause");
				return 0;
			}
			char str[12];
			sprintf(str,"%d I\n",temp);
			txt[i+flag] = string(str);
			flag++;
		}
		if((i+1)==a[i+flag-flag2]){
			int temp = a[i+flag-flag2];
			char str[12];
			sprintf(str,"%d P\n",temp);
			txt[i+flag] = string(str);
		}
		else 
		{
			cout << "No" << endl;
			system("pause");
			return 0;
		}
	}
	}
	for (int i = 0; i < n+flag; i++){
		cout << txt[i];
	}

	//test
	//printf("%d", col[3]);
	system("pause");
}
