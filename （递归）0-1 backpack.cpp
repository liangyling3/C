/* 0-1 backpack ����һ����Ʒ��ÿ����Ʒ�����Լ��������ͼ۸����޶����������ڣ��������ѡ�񣬲���ʹ����Ʒ���ܼ۸���ߡ������������Դ�����ѡ������ʵ���Ʒ�����ڸ��������С�
������n����Ʒ����Ʒj������Ϊwj���۸�Ϊpj�����Ǽٶ�������Ʒ�������ͼ۸��ǷǸ��ġ��������ܳ��ܵ��������ΪW��
����޶�ÿ����Ʒֻ��ѡ��0����1�����������Ϊ0-1�������⡣

�㷨: ���ǽ���������������Y��ǰ���£�ǰj����Ʒ���ܼ۸����ܴﵽ�����ֵ����ΪA(j, Y)�� A(j, Y)�ĵ��ƹ�ϵΪ�� 
��A(0, Y) = 0
��A(j, 0) = 0
�����wj > Y, A(j, Y) = A(j - 1, Y)
�����wj �� Y, A(j, Y) = max { A(j - 1, Y), pj + A(j - 1, Y - wj) }
EXAMPLE INPUT 
     9     6    10    11     8     4     5     7    12    13
    11     6    12     9    14    10    13     8    15     7
    48
EXAMPLE OUTPUT 
	51
*/

/*��2017/12/20��һ��𰸣���

int knapsack(int prices[], int weights[], int maxWeight) {
	static int count[10] = {0};
	int value, maxPrices = 0;
	for (int i = 0; i < 10; ++ i) {
		if (maxWeight <= 0) return 0;
		if (maxWeight - weights[i] < 0) continue;
		if (count[i] != 0) continue;
		count[i] ++;
		value = prices[i] + knapsack(prices, weights, maxWeight - weights[i]); 
		if (value > maxPrices) maxPrices = value;
	}
	return maxPrices;
} 

�ҵ��뷨������һ��count���飬ÿ��ʹ����i֮��Ը�count[i]���м������´��ٵ����iʱ������continue�������ѭ��
Ϊʲô�����ڵ�һ����ѭ���У���������ȷ�ģ����Ǵ�ѭ���е�i���е�1ʱ����ʱ��i�Ѿ����ı��ˣ������˼������� 
*/

/*�Ľ��뷨��ʹһ�������ڵݹ��ڸı䣬��ÿ��ѭ���ڱ����¸�ֵ
ʵ�ַ�������һ�������ֽ�Ϊ�������������Ӵ��ݲ�����������*/

/* ��2017/12/21��������Ĵ𰸰��������յĴ𰸣��˲�����.jpg */
#include <stdio.h>

void read(int array[], int length) {//��Ŀ�����Ĳ��� 
	for (int i = 0; i < length;  ++ i) {
		scanf("%d", &array[i]);
	}
}

int getvalue(int prices[], int weights[], int maxWeight, int num) {
	int value, maxPrices = 0;
	for (int i = num; i < 10; ++ i) {
		/*�������ֵС�ڵ���0ʱ��ֹѭ��*/
		if (maxWeight <= 0) return 0;
		/*ע��˴��״��ж�weights[i]����������ʱ��weights[i+1]
		�ǿ������������ģ�����ֱ�ӷ���0*/
		if (maxWeight - weights[i] < 0) continue;
		value = prices[i] + getvalue(prices, weights, maxWeight - weights[i], i+1); 
		if (value > maxPrices) maxPrices = value;
	}
	return maxPrices;
}

int knapsack(int prices[], int weights[], int maxWeight) {
	return getvalue(prices, weights, maxWeight, 0);
}

int main() {//��Ŀ�����Ĳ��� 
	int prices[10];
	read(prices, 10);
	int weights[10];
	read(weights, 10);
	int maxWeight;
	scanf("%d", &maxWeight);
	
	printf("%d", knapsack(prices, weights, maxWeight)); 
}


