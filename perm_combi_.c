/*PROGRAM BY LALITH SAGAR J
	PERMUTATION AND COMBINATION*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int permutation(int n,int r);
int combination(int n,int p,int r);
int fact(int n){
	int f=1;
	if(n>0)
		f=n*fact(n-1);
	return f;
}

int main(){
	int n,r,st,et,t_t;
	printf("\nenter the values of  n and r:");
	scanf("%d%d",&n,&r);
	st=clock();
	int p=permutation(n,r);
	int c=combination(n,p,r);
	et=clock();
	t_t=et-st;
	printf("\npermutation of %dP%d=%d\n",n,r,p);
	printf("\ncombination of %dC%d=%d\n",n,r,c);
	printf("\nstart time=%d\tendtime=%d\ntotal time=%d\n\n",st,et,t_t);
	return 0;
}

int permutation(int n,int r){
	if((n-r)<0){
		printf("\ninvalid\n");
		exit(0);
	}
	return fact(n)/fact(n-r);
}

int combination(int n,int p,int r){
	return p/fact(r);
}
