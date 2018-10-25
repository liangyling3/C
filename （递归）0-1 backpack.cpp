/* 0-1 backpack 给定一组物品，每种物品都有自己的重量和价格，在限定的总重量内，我们如何选择，才能使得物品的总价格最高。问题的名称来源于如何选择最合适的物品放置于给定背包中。
我们有n种物品，物品j的重量为wj，价格为pj。我们假定所有物品的重量和价格都是非负的。背包所能承受的最大重量为W。
如果限定每种物品只能选择0个或1个，则问题称为0-1背包问题。

算法: 我们将在总重量不超过Y的前提下，前j种物品的总价格所能达到的最高值定义为A(j, Y)。 A(j, Y)的递推关系为： 
·A(0, Y) = 0
·A(j, 0) = 0
·如果wj > Y, A(j, Y) = A(j - 1, Y)
·如果wj ≤ Y, A(j, Y) = max { A(j - 1, Y), pj + A(j - 1, Y - wj) }
EXAMPLE INPUT 
     9     6    10    11     8     4     5     7    12    13
    11     6    12     9    14    10    13     8    15     7
    48
EXAMPLE OUTPUT 
	51
*/

/*（2017/12/20第一版答案）：

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

我的想法：定义一个count数组，每次使用了i之后对该count[i]进行计数，下次再到这个i时，则用continue跳过这次循环
为什么错？：在第一个大循环中，计数是正确的；但是大循环中的i进行到1时，这时的i已经被改变了，导致了计数错误。 
*/

/*改进想法：使一个变量在递归内改变，在每次循环内被重新赋值
实现方法：将一个函数分解为两个函数，增加传递参数数量计数*/

/* （2017/12/21）在俞因的答案帮助下最终的答案，菜不成声.jpg */
#include <stdio.h>

void read(int array[], int length) {//题目给出的部分 
	for (int i = 0; i < length;  ++ i) {
		scanf("%d", &array[i]);
	}
}

int getvalue(int prices[], int weights[], int maxWeight, int num) {
	int value, maxPrices = 0;
	for (int i = num; i < 10; ++ i) {
		/*承重最大值小于等于0时终止循环*/
		if (maxWeight <= 0) return 0;
		/*注意此处易错！判断weights[i]不满足条件时，weights[i+1]
		是可能满足条件的！不能直接返回0*/
		if (maxWeight - weights[i] < 0) continue;
		value = prices[i] + getvalue(prices, weights, maxWeight - weights[i], i+1); 
		if (value > maxPrices) maxPrices = value;
	}
	return maxPrices;
}

int knapsack(int prices[], int weights[], int maxWeight) {
	return getvalue(prices, weights, maxWeight, 0);
}

int main() {//题目给出的部分 
	int prices[10];
	read(prices, 10);
	int weights[10];
	read(weights, 10);
	int maxWeight;
	scanf("%d", &maxWeight);
	
	printf("%d", knapsack(prices, weights, maxWeight)); 
}


