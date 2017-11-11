#include <iostream>
#include <stack>
using namespace std;
template <class T>
int partition(T a[],int low,int high)
{
 T v=a[low];
 while(low<high)
 {  
  while(low<high && a[high]>=v) high--;
  a[low]=a[high];
  while(low<high && a[low]<=v) low++;
  a[high]=a[low];
 }
 a[low]=v;
 return low;
 
}
 
template <class T>
void QuickSort(T a[],int p,int q)
{
 stack<int> st;
 int j;
 do{
      while(p<q)
      {
         j=partition(a,p,q);   
         if( (j-p)<(q-j) )
         {
            st.push(j+1);
            st.push(q);
            q=j-1;
         }
         else
         {
           st.push(p);
           st.push(j-1);
           p=j+1;
         }   
      }
  if(st.empty()) return;
  q=st.top();st.pop();  
  p=st.top();st.pop();  
  //cout<<endl<<"p:"<<p<<" ";
  //cout<<"q:"<<q<<endl;
 }while(1);
}

void main()
{
 //int a[7]={7,6,5,4,3,2,1};
 //int a[7]={1,2,3,4,5,6,7};
 int a[7]={3,5,2,3,66,225,1};
 for(int i=0;i<7;i++)
  cout<<a[i]<<" ";
 QuickSort(a,0,6);
 cout<<endl;
 for(int i=0;i<7;i++)
  cout<<a[i]<<" ";
}  