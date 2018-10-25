/*Input����һ����n�׵�ľͷ����һ��price table��table���£�
	���� i 1 2 3 4 5 6 ������
	�۸� Pi 1 5 8 9 10 17������
��˼�����ԣ����ǳ���Ϊ1�׵�ľͷ������1Ԫ����5�׵Ŀ�����10Ԫ����������
Output����һ��cut�ķ�����ʹ���׬��Ǯ��ࡣ

����Ȼ������ݹ����Ҫ˼·������һ��֮�󣬷ֳ����Σ�һ���Ұ�table�ļ�Ǯ���ˣ���һ���ҵ���һ���µ������⣬��
����Ϊ�ҵĺ������µĲ������������͵ݹ����𣿵�����������һ����ô�У�û�����Ǿ����������ֵ����maxi =1 to n Pi + Cut(n-i).
EXAMPLE INPUT 
	1 2 3 4 5 6
	1 5 8 9 10 17
	17 16 15 14 13 12 11 10 9 8
EXAMPLE OUTPUT 
	47
	44
	42
	39
	35
	34
	30
	27
	25
	22
*/

/*��2017/12/19����ʦ�Ͽν������⣬�����������˺ܾ�orz */ 
#include <stdio.h>

void readPriceTable(int prices[][2], int priceCount) {
	for (int i = 0; i < priceCount; ++ i) {
		scanf("%d", &prices[i][0]);
	}
	for (int i = 0; i < priceCount; ++ i) {
		scanf("%d", &prices[i][1]);
	}
}

//�𰸲���  start 
#define min(x,y) (x > y ? y : x)

int getMaxCuttingPrice(int prices[][2], int priceCount, int rodLength) {
	int maxMoney = 0;//�������з����е����ֵ
	//Ҫ�и��Ӧ��pricecount��rodlength�ַ�������һ��ѭ����ÿ�ַ������������
	for (int i = 1; i <= min(priceCount, rodLength); ++ i) {
		//�ݹ飬�и�һ�γ���С�ڵ���priceCount��ľ֮�����µĶ����и�
		int money = prices[i-1][1] + getMaxCuttingPrice(prices, priceCount, rodLength - i);
		if (money > maxMoney) 
			maxMoney = money;
	}
	return maxMoney;
}
//end 

void test(int prices[][2], int priceCount) {
	int rodLength;
	scanf("%d", &rodLength);
	printf("%d\n", getMaxCuttingPrice(prices, priceCount, rodLength));
}


int main() {
	int prices[6][2];
	readPriceTable(prices, 6);
	
	for (int i = 0; i < 10; ++ i) {
		test(prices, 6);
	}
}
