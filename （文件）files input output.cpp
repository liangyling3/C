/*Read information about three computers, and print the information about the cheapest one. 

EXAMPLE INPUT
	Microsoft Surface 9000
	Lenovo ThinkPad 8000
	Apple MacBook 10000
EXAMPLE OUTPUT
	Lenovo ThinkPad 8000*/

#include <stdio.h> 
#include <string.h> 
//禁止使用print scanf函数 
 
struct ComputerInfo 
{ 
    char brand[20]; 
    char model[20]; 
    int price; 
}; 
 
//依次读入字符串brand、字符串model、价格price
void readComputerInfo(FILE * fin, struct ComputerInfo info[3], int times) {
	int i;
	for (i = 0; i < times; ++ i) 
		fscanf(fin, "%s %s %d", info[i].brand, info[i].model, &info[i].price);
}

//返回值的类型是定义的ComputerInfo类型
struct ComputerInfo getMinInPrice(struct ComputerInfo info[3], int times)
{
	int priceMin = info[0].price, i;
	for (i = 0; i < times; ++ i) {
		if (info[i].price < priceMin)
			priceMin = info[i].price;
	}
	for (i = 0; i < times; ++ i) {
		if (info[i].price == priceMin)
			return info[i];
	}
}

//打印函数
void printComputerInfo(FILE * fout, struct ComputerInfo minInfo) {
	fprintf(fout, "%s %s %d", minInfo.brand, minInfo.model, minInfo.price);
}

void printMinInPrice(FILE * fin, FILE * fout) { 
    struct ComputerInfo info[3]; 
    readComputerInfo(fin, info, 3); 
    struct ComputerInfo min = getMinInPrice(info, 3); 
    printComputerInfo(fout, min); 
}
 
int main() { 
    FILE * fin = stdin; 
    FILE * fout = stdout; 
    printMinInPrice(fin, fout); 
} 



