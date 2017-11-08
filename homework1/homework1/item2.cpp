#include <iostream>
#include <cstring>
using namespace std;

bool test(int num1, int* employeeF, int top, int* employeeT){
		return (0<=employeeF[num1]) && (employeeF[num1]<top) && (num1==employeeT[employeeF[num1]]);
	}

int main(){
	//accelerate inputing
	setvbuf(stdin, new char[1 << 20], _IOFBF, 1<<20);
	//input 1st line 
	int n, m, sum= 0, an =0, aq =0;
	scanf("%d %d", &n, &m);
	//initialize the employee and top
	int top =0;
	int *employee = new int[n];
	int *employeeF = new int[n+1];
	int *employeeT = new int[n];
	memset(employee, -1, 4*n); // set -1
	memset(employeeF, -1, 4*(n+1));
	memset(employeeT, -1, 4*n);
	//read test code 
	for(int i=0; i<m ;i++){
	char code[2];
	scanf("%s", &code);
	switch (code[0])
	{
		int num1,num2;
	case 'I':
		scanf("%d %d", &num1,&num2);
		if(!test(num1,employeeF,top,employeeT)){
			//memorize the code
			employee[num1-1] = num2;
			sum++;
			//establish the loop
			employeeT[top] = num1;
			employeeF[num1] = top++;
		}
		else{
			employee[num1-1] = num2;
		}
		break;
	case 'O':
		scanf("%d", &num1);
		if( test(num1,employeeF,top,employeeT) ){
			//-1 this employee
			employee[num1-1] = -1;
			sum--;
			//unloop
			if(--top){
				//exchange the position
				employeeF[employeeT[top]] = employeeF[num1];
				employeeT[employeeF[num1]] = employeeT[top];
			}
		}
		else{
			employee[num1-1] = -1;
		}
		break;
	case 'C':
		if(sum == 0){
		}
		else{
		top = 0;
		sum = 0;
		}
		break;
	case 'N':
		an += top;
		break;
	case 'Q':
		scanf("%d", &num1);
		if(test(num1,employeeF,top,employeeT)){	
			aq += employee[num1-1];
		}
		else
			aq += -1;
		break;
	//default:
		//break;
	}
	}

	cout << (an +aq);
	//pause
	system("pause");
}

