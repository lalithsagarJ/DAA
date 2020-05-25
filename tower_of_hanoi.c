/*PROGRAM BY LALITH SAGAR J 
	TOWER OF HANOI */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void towerofhanoi(int n,char s,char a,char d){
	if(n==1){
		printf("\nmove the disk 1 from %c to %c",s,d) ;
		return ;
	}
	towerofhanoi(n-1,s,d,a);
	printf("\nmove %d from %c to %c",n,s,d);
	towerofhanoi(n-1,a,s,d);
}

int main(){
	int n,st,et,t_t;
	printf("\nenter the no of of disks:");
	scanf("%d'",&n);
	st=clock();
	towerofhanoi(n,'A','B','C');
	et=clock();
	t_t=et-st;
	printf("\nstart time =%d\tend time =%d\ntotal time =%d\n",st,et,t_t);
	return 0;
}
