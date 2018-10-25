/*Read two integer numbers, and then output these two numbers as well as their bitwise and, bitwise or, and bitwise xor, all in binary form.
EXAMPLE INPUT 
	170 204
EXAMPLE OUTPUT 
	00000000000000000000000010101010
	00000000000000000000000011001100
	00000000000000000000000010001000
	00000000000000000000000011101110
	00000000000000000000000001100110*/
	
/*（2017/10/3）作业要求的部分不难，但是纠结了好久老师写的部分…神奇的获得二进制数的方法…*/
#include <stdio.h>

void printInt(int val) {
	printf("%d", val); 
}

//将十进制数转化为二进制数 
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
	printBits(num1 & num2);//'&'按位与：两个二进制数，相同位置：全1为1，有0则0 
	printf("\n");
	printBits(num1 | num2);//'|'按位或：两个二进制数，相同位置：全0为0，有1则1 
	printf("\n");
	printBits(num1 ^ num2);//'^'按位异或：两个二进制数，相同位置：不同为1，相同为0 
}

