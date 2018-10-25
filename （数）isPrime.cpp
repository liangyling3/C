/*判断素数的方法汇总*/
#include <stdio.h>
#include <math.h>

int isPrime1(int num);
int isPrime2(int num);
int isPrime3(int num);
int isPrime4(int num);

int main(){
	int num;
	scanf("%d",&num);
	printf("%d\n",isPrime1(num));
	printf("%d\n",isPrime2(num));
	printf("%d\n",isPrime3(num));
}

//从2遍历到x-1，看x是否能够整除； 
int isPrime1(int num){
	int i, ret = 1;
	if(num > 2) {
		for(i = 2; i < num; ++ i) {
			if(num % i == 0) ret = 0;
		}
	}
	return ret;
}

//去掉偶数，从3遍历到x-1，看x是否能够整除；
int isPrime2(int num) { 
	int i, ret = 1;
	if(num > 2){
		for(i = 3; i < num; i+=2){
			if(num % i == 0) ret = 0; 
		}
	}
	return ret;
} 

//去掉偶数，从3遍历到sqrt（x），看x是否能够整除
int isPrime3(int num) {
	int i, ret = 1;
	if(num > 2){
		for (i = 3; i < sqrt(num); i+=2){
			if (num % i == 0) ret = 0;
		}
	}
	return ret;
}

