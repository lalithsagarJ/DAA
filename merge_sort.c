#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int n,int a[n],int l,int q,int r){
	int n1,n2;
	n1=q-l+1;
	n2=r-q;
	int left[n1],right[n2],i,j,k;
	for(i=0;i<n1;i++)
		left[i]=a[l+i];
	for(j=0;j<n2;j++)
		right[j]=a[q+j+1];
	i=0;
	j=0;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			a[k]=left[i];
			i++;
		}
		else{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=left[i];
		i++;k++;
	}
	while(j<n2){
		a[k]=right[j];
		j++;k++;
	}
}
void mergesort(int n,int a[n],int l,int r){
	if(l<r){
		int q=(l+r)/2;
		mergesort(n,a,l,q);
		mergesort(n,a,q+1,r);
		merge(n,a,l,q,r);
	}
}
int main(){
	int n,start,end,t_t;
	start=clock();
	printf("\nenter the no of elements:");
	scanf("%d",&n);
	int a[n];
	printf("\nenter the elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(n,a,0,n-1);
	printf("\nthe sorted order is :");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	end=clock();
	t_t=end-start;
	printf("\nstart= %d\tend= %d\ntotal time= %d",start,end,t_t);
	return 0;
}
