/*�ж������ķ�������*/
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

//��2������x-1����x�Ƿ��ܹ������� 
int isPrime1(int num){
	int i, ret = 1;
	if(num > 2) {
		for(i = 2; i < num; ++ i) {
			if(num % i == 0) ret = 0;
		}
	}
	return ret;
}

//ȥ��ż������3������x-1����x�Ƿ��ܹ�������
int isPrime2(int num) { 
	int i, ret = 1;
	if(num > 2){
		for(i = 3; i < num; i+=2){
			if(num % i == 0) ret = 0; 
		}
	}
	return ret;
} 

//ȥ��ż������3������sqrt��x������x�Ƿ��ܹ�����
int isPrime3(int num) {
	int i, ret = 1;
	if(num > 2){
		for (i = 3; i < sqrt(num); i+=2){
			if (num % i == 0) ret = 0;
		}
	}
	return ret;
}

