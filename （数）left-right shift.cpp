#include <stdio.h>

void printInt(int val) {
	printf("%d", val); 
}

void printBit(char val, int bitPos) {
	int bit = (val >> bitPos) & 1;
	printInt(bit);
}

void printBits(char val) {
	int i = 0;
	while (i < 8) {
		printBit(val, 7 - i);
		i = i + 1;
	}
}

int main(){
	char letter;
	scanf("%c",&letter);
	int num = (int)letter;
	printBits(num);
	printf("\n");
	printBits((num >> 5) << 3);//移动操作，可多重叠加 
}

