#include <iostream>
#include <cstring>
#include <string>
#define NUM 10039
using namespace std;

struct Snode
{
	string name;
	int num;
	Snode *next;	//hash collision
	Snode( Snode *n, string str, int cnt): next(n),num(cnt),name(str){};
};
int main(){
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	int n;
	hash<string> h;			//invlove hash function
	scanf("%d", &n);
	string str;
	int hashcode;
	//initialize the bucket
	Snode **bucket = new Snode*[NUM];
	memset(bucket, 0, sizeof(Snode*)*NUM);
	//record the max
	Snode *max;
	for(int i=0; i<n;i++){
		cin >> str;
		hashcode = (h(str)%NUM);
		if(bucket[hashcode] == NULL){
			bucket[hashcode] = new Snode(NULL, str, 1);
			if (i == 0)
			{
				max = bucket[hashcode];
			}
		}
		else
		{
			Snode *tempnode = bucket[hashcode];
			while (true)
			{
				if(tempnode->name.compare(str) == 0){
					tempnode->num++;
					if(tempnode->num > max->num)
						max = tempnode;
					break;
				}
				if(tempnode->next == NULL){
					tempnode->next = new Snode(NULL, str, 1);
					break;
				}
				tempnode = tempnode->next;
			}
		}

	}
	//output
	cout << max->name << " "<< max->num;
	return 0;
}
