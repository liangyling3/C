#include<stdio.h>
int main(){
	int num[10],i;
	//����һ������ ,ע�������Ǵ�0��ʼ������  
	for (;i<10;++i) scanf("%d",&num[i]);
	i=0;
	for(;i<10;++i) printf("%d ",num[9-i]);
}

