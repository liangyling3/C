//An palindromic prime is simultaneous a prime number and palindromic (symmetric).
//For example, 131 is a prime and also a palindromic. 
//Given a positive number n, write a program that displays the first n palindromic primes. 
//Display 10 numbers per line. 

#include <stdio.h>
int judge1(int num){
	//�ж��Ƿ�Ϊ����
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
	//ȡ�������
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
	//�ж��Ƿ�Գ�
	if (num == reverse(num)) return 1;
	else return 0;
}

int main(){
	int num, i = 2, k = 0;
	scanf("%d",&num);
	for(;k < num; ++i){
	//�˴���Ƕ�׽��ж�·���㣺���жϼ򵥵��������ų�������������ٽ�����һ������ 
	//��ֱ�ӽ�������������ͬʱ�жϣ��ᵼ������ʱ����� 
		if (judge2(i) == 1){ 
			if(judge1(i) == 1){
				printf("%d ",i);
				++k;//�����������������м��� 
				if (k % 10 == 0 && k != 0) printf("\n");//������з� 
			}
		}
	}
}
		

