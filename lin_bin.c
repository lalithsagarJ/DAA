/*PROGRAM BY LALITH SAGAR J
	LINEAR SEARCH USING 
		1.ITTERATIVE METHOD
		2.RECURSSIVE METHOD
	
	BINARY SEARCH USING 
		3.ITTERATIVE METHOD
		4.RECURSSIVE METHOD      */
#include<stdio.h>
#include<stdlib.h>
int loc=-1,mid;
int input(int a[50]){
	int n;
	printf("\nenter the number of elements:");
	scanf("%d",&n);
	int ele;
	printf("enter the elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	return n;
}

void print_rec(int n,int a[50],int ele,int l){
	if(l<0)
		printf("\nelement not present");
	else
		printf("%d is present in position %d",ele,l+1);
} 

int lin_ite(int n,int a[50]){
	int ele,i,p;
	loc=-1;
	printf("enter the search element:");
	scanf("%d",&ele);
	for( i=0;i<n;i++)
		if(a[i]==ele){
			loc=i;
			break;
		}
	if(i==n)
		printf("\nelement not present\n");
	else
		print_rec(n,a,ele,loc);
	return 0;
}

int lin_rec(int n,int a[50],int i,int ele){
	loc=-1;
	while(i!=n){
		if(a[i]==ele){
			loc=i;
			break;
		}
		else{
			i++;
			lin_rec(n,a,i,ele);
		}
	}
	return loc;
}
int bin_ite(int n,int a[50]){
	int ele,beg=0,end=n-1;
	loc=-1;
	printf("enter the search element:");
	scanf("%d",&ele);
	while (beg<=end){
		mid=(beg+end)/2;
		if(a[mid]==ele){
			loc=mid;
			break;
		}
		else if(a[mid]>ele)
			end=mid-1;
		else if(ele>a[mid])
			beg=mid+1;
	}
	print_rec(n,a,ele,loc);
	return 0;
}	
int bin_rec(int n,int a[50],int ele,int beg,int end){
	loc=-1;
	if(beg<=end){
		mid=(beg+end)/2;
		if(a[mid]==ele){
			loc=mid;
		}
		else if(ele>a[mid]){
			beg=mid+1;
			bin_rec(n,a,ele,beg,end);
		}
		else{
			end=mid-1;
			bin_rec(n,a,ele,beg,end);
		}
	}
	return loc;
}
int main(){
	int ch,n,ele,i,a[50],p;
	while(1){
		printf("\noptions\n1.linear search  using iterartion\n2.linear search  using recurssion\n3.binary search using iterartion\n4.binary search using recurssion");
		printf("\nchoice:");
		scanf("%d",&ch);	
		switch(ch){
			case 1:n=input(a);
				lin_ite(n,a);
			break;
			case 2:n=input(a);
				printf("enter the search element:");
				scanf("%d",&ele);
				p=lin_rec(n,a,0,ele);
				print_rec(n,a,ele,p);
			break;
			case 3:n=input(a);
				bin_ite(n,a);
			break;
			case 4:n=input(a);
				printf("enter the search element:");
				scanf("%d",&ele);
				p=bin_rec(n,a,ele,0,n-1);
				print_rec(n,a,ele,p);
			break;
			default:printf("\ninvalid choice");
		}
		printf("\nenter 0 to quit:");
		scanf("%d",&i);
		if(i==0)
			exit(0);	
	}
	return 0;
}
	
