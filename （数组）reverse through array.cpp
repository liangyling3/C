#include<stdio.h>
int main(){
	int num[10],i;
	//定义一个数组 ,注意数组是从0开始计数的  
	for (;i<10;++i) scanf("%d",&num[i]);
	i=0;
	for(;i<10;++i) printf("%d ",num[9-i]);
}

