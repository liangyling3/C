#include <stdio.h>  

int main(){
	int num;//num�˴�Ϊ���α�Ԫ�ظ��� 
	scanf("%d",&num);
	for (int i = 1; i <= num; ++i){//��ʼ��iֵΪ1�����ڼ��� 
		for (int j = num - i; j > 0; --j) printf(" ");//����ո񣻹��ɣ���n������߳�-n���ո�Ƕ��ѭ���� 
		for (int k = 0; k < i; ++k) printf("%d",i - k);	
		printf("\n");//ÿ�����һ�����з� 
	}
}
 

