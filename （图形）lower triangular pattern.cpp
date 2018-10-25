#include <stdio.h>  

int main(){
	int num;//num此处为矩形边元素个数 
	scanf("%d",&num);
	for (int i = 1; i <= num; ++i){//初始化i值为1，便于计算 
		for (int j = num - i; j > 0; --j) printf(" ");//输出空格；规律：第n行输出边长-n个空格（嵌套循环） 
		for (int k = 0; k < i; ++k) printf("%d",i - k);	
		printf("\n");//每行输出一个换行符 
	}
}
 

