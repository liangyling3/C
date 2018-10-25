/*An emirp (prime spelled backwards) is a prime number whose reversal is also a prime.
For example, 17 is a prime and 71 is also a prime. So 17 and 71 are emirps. 
Given a positive number n, write a program that displays the first n emirps. Display 10 numbers per line.
EXAMPLE INPUT 
	103
EXAMPLE OUTPUT 
	2 3 5 7 11 13 17 31 37 71 
	73 79 97 101 107 113 131 149 151 157 
	167 179 181 191 199 311 313 337 347 353 
	359 373 383 389 701 709 727 733 739 743 
	751 757 761 769 787 797 907 919 929 937 
	941 953 967 971 983 991 1009 1021 1031 1033 
	1061 1069 1091 1097 1103 1109 1151 1153 1181 1193 
	1201 1213 1217 1223 1229 1231 1237 1249 1259 1279 
	1283 1301 1321 1381 1399 1409 1429 1439 1453 1471 
	1487 1499 1511 1523 1559 1583 1597 1601 1619 1657 
	1669 1723 1733  */

#include <stdio.h>
int judge(int num){
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
	//对一个数进行倒序 
	int sum = 0;
	for(;x > 0;){
		int rem = x % 10;
		sum *= 10;
		sum += rem;
		x /= 10;
	}
	return sum;
}

int main(){
	int num, i = 2, k = 0;
	scanf("%d",&num);
	for(;k < num; ++i){
		int i2 = reverse(i);
		if (judge(i) == 1 && judge(i2) == 1){ 
			printf("%d ",i);
			++k;//对满足条件的数进行计数 
			if (k % 10 == 0 && k != 0) printf("\n");//每十个数输出一个换行符 
		}
	}
}
		
	
