/*Read two integer numbers, and then output these two numbers as well as their bitwise and, bitwise or, and bitwise xor, all in binary form.
EXAMPLE INPUT 
	170 204
EXAMPLE OUTPUT 
	00000000000000000000000010101010
	00000000000000000000000011001100
	00000000000000000000000010001000
	00000000000000000000000011101110
	00000000000000000000000001100110*/
	
/*��2017/10/3����ҵҪ��Ĳ��ֲ��ѣ����Ǿ����˺þ���ʦд�Ĳ��֡�����Ļ�ö��������ķ�����*/
#include <stdio.h>

void printInt(int val) {
	printf("%d", val); 
}

//��ʮ������ת��Ϊ�������� 
void printBit(int val, int bitPos) { 
	int bit = (val >> bitPos) & 1;
	printInt(bit);
}

void printBits(int intVal) {
	int i = 0;
	while (i < 32) {
		printBit(intVal, 31 - i);
		i = i + 1;
	}
}

int main(){
	int num1,num2;
	scanf("%d%d",&num1,&num2);
	printBits(num1);
	printf("\n");
	printBits(num2);
	printf("\n");
	printBits(num1 & num2);//'&'��λ�룺����������������ͬλ�ã�ȫ1Ϊ1����0��0 
	printf("\n");
	printBits(num1 | num2);//'|'��λ������������������ͬλ�ã�ȫ0Ϊ0����1��1 
	printf("\n");
	printBits(num1 ^ num2);//'^'��λ�������������������ͬλ�ã���ͬΪ1����ͬΪ0 
}

