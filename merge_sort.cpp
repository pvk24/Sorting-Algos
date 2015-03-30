#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

#define MAX 10000

void merge(int[],int,int);
void merge_sort(int[],int,int,int);

int main()
{
 int A[MAX],n=MAX,lb,ub;

 lb=0;
 ub=n-1;

 for(int i=0;i<n;i++)
  A[i]=rand();
  clock_t start,end;
  double runTime;
  start = clock();
 merge(A,lb,ub);
  end = clock();
 cout<<"Sorted array\n";
 for(int i=0;i<n;i++)
  cout<<A[i]<<" ";
 runTime = (end - start) / (double) CLOCKS_PER_SEC ;
  cout<<"\nRun time is "<<runTime<<" seconds\n";

 return 0;
}

void merge(int A[],int lb,int ub)
{
 int mid;
 if(lb<ub)
 {
  mid=(lb+ub)/2;

  merge(A,lb,mid);
  merge(A,mid+1,ub);
  merge_sort(A,lb,mid,ub);
 }
}

void merge_sort(int A[],int lb,int mid,int ub)
{
 int h,i,temp[MAX],j,k;
 h=i=lb;
 j=mid+1;
 while(h<=mid && j<=ub)
 {
  if(A[h]<=A[j])
   temp[i++]=A[h++];
  else
   temp[i++]=A[j++];
 }
 if(h>mid)
 {
  for(k=j;k<=ub;k++)
   temp[i++]=A[k];
 }
 else
 {
  for(k=h;k<=mid;k++)
   temp[i++]=A[k];
 }

 for(k=lb;k<=ub;k++)
  A[k]=temp[k];
}
