#include <stdio.h>

void reverse(int x){
	int sum = 0;
	for(;x > 0;x /= 10){//思路:取余后乘以10，再两位依次相加 
		int rem = x % 10;
		sum *= 10;
		sum += rem;
	}
	printf("%d\n",sum);
}
		
int main(){
	for(int i = 0; i < 10; ++i){
		int num;
		scanf("%d",&num);
		reverse(num);
	}
}
