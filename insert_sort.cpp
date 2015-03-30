#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

#define MAX 10000

void Insertion_sort(int A[],int n)
{
 int temp,j;

 for(int i=1;i<n;i++)
 {
  temp=A[i];
  j=i-1;
  while(j>=0 && temp<A[j])
  {
   A[j+1]=A[j];
   j--;
  }
  A[j+1]=temp;
 }

}

int main()
{
 int A[MAX],n = MAX;
 for(int i=0;i<MAX;i++)
  A[i]=rand();
  clock_t start,end;
  double runTime;
  start = clock();
 Insertion_sort(A,n);
  end = clock();
 cout<<"Sorted array:\n";
 for(int i=0;i<n;i++)
  cout<<A[i]<<" ";
  runTime = (end - start) / (double) CLOCKS_PER_SEC ;
  cout<<"\nRun time is "<<runTime<<" seconds\n";
 return 0;
}
