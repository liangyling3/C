/*Input：有一个长n米的木头，和一个price table，table如下：
	长度 i 1 2 3 4 5 6 。。。
	价格 Pi 1 5 8 9 10 17。。。
意思很明显，就是长度为1米的木头可以买1元，长5米的可以卖10元，依次类推
Output：找一个cut的方法，使最后赚的钱最多。

很显然，这个递归的主要思路是我切一刀之后，分成两段，一段我按table的价钱卖了，另一段我当成一个新的子问题，继
续作为我的函数的新的参数，这样不就递归了吗？但是问题是这一刀怎么切，没错，我们就来个找最大值，即maxi =1 to n Pi + Cut(n-i).
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

/*（2017/12/19）老师上课讲过的题，回来还是做了很久orz */ 
#include <stdio.h>

void readPriceTable(int prices[][2], int priceCount) {
	for (int i = 0; i < priceCount; ++ i) {
		scanf("%d", &prices[i][0]);
	}
	for (int i = 0; i < priceCount; ++ i) {
		scanf("%d", &prices[i][1]);
	}
}

//答案部分  start 
#define min(x,y) (x > y ? y : x)

int getMaxCuttingPrice(int prices[][2], int priceCount, int rodLength) {
	int maxMoney = 0;//储存所有方法中的最大值
	//要切割，对应有pricecount或rodlength种方法，用一个循环将每种方法都计算出来
	for (int i = 1; i <= min(priceCount, rodLength); ++ i) {
		//递归，切割一段长度小于等于priceCount的木之后，余下的段再切割
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
