//An palindromic prime is simultaneous a prime number and palindromic (symmetric).
//For example, 131 is a prime and also a palindromic. 
//Given a positive number n, write a program that displays the first n palindromic primes. 
//Display 10 numbers per line. 

#include <stdio.h>
int judge1(int num){
	//判断是否为质数
	int i = num - 1, x;
	for(; i > 1; --i){
		if(num % i != 0) x = 1;
		else{
			x = 0; 
			break;
		}
	}
	if (x == 1 || num == 2) return 1;
	else return 0;
}

int reverse(int x){
	//取倒序的数
	int sum = 0;
	for(;x > 0;){
		int rem = x % 10;
		sum *= 10;
		sum += rem;
		x /= 10;
	}
	return sum;
}

int judge2(int num){
	//判断是否对称
	if (num == reverse(num)) return 1;
	else return 0;
}

int main(){
	int num, i = 2, k = 0;
	scanf("%d",&num);
	for(;k < num; ++i){
	//此处用嵌套进行短路运算：先判断简单的条件，排除掉绝大多数，再进行下一步运算 
	//若直接进行两个条件的同时判断，会导致运算时间过长 
		if (judge2(i) == 1){ 
			if(judge1(i) == 1){
				printf("%d ",i);
				++k;//对满足条件的数进行计数 
				if (k % 10 == 0 && k != 0) printf("\n");//输出换行符 
			}
		}
	}
}
		

