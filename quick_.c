#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int n,int a[n],int l,int r){
	int i,j,pivot;
	i=l;j=r;pivot=l;
	while(i<j){
		do{
			i++;
		}while(a[i]<=a[pivot]);
		do{
			j--;
		}while(a[j]>a[pivot]);
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[l],&a[j]);
	return j;
}

int quick_sort(int n,int a[n],int l,int h){
	int np;
	if(l<h){
		np=partition(n,a,l,h);
		quick_sort(n,a,l,np);
		quick_sort(n,a,np+1,h);
	}
}

int main(){
	int n,start,end,t_t;
	start=clock();
	printf("\nenter how many elements:");
	scanf("%d",&n);
	int a[n];
	printf("\nenter the elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(n,a,0,n);
	printf("\nthe elements after sorting is:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	end=clock();
	t_t=end-start;
	printf("\nstart=%d\tend=%d\ntotal time=%d",start,end,t_t);
	return 0;
}	
