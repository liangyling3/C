/*Write a function that computes the sums of the digits in 10 positive integers, respectively.
Note that each integer can have arbitrary number of digits.
	EXAMPLE INPUT 
		1
		12
		123
		1234
		12345
		123456
		1234567
		234567
		34567
		4567
	EXAMPLE OUTPUT 
		1
		3
		6
		10
		15
		21
		28
		27
		25
		22*/
		
/*（2017/10/19）*/
#include <stdio.h>

//注意掌握此处整数位求和的方法 
void print_sum(int x){
	int sum = 0, rem;
	for (;x > 0;x /= 10){
		rem = x % 10;
		sum += rem;
	}
	printf("%d\n",sum);
}

int main(){
	int num;
	for (int i = 0; i < 10; ++i){
		scanf("%d",&num);
		print_sum(num);
	}
}	

