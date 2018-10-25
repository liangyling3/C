/*Description

Suppose there are five kinds of coins:  5 角、 1 角、 5 分、 2 分和 1 分. Now we want to give change to the customer with as few coins as possible. Write a program to compute how many coins do we need.

 

假定有 5 角、 1 角、 5 分、 2 分和 1 分共 5 种硬币，在 给顾客找硬币时，一般都会尽可能地选用硬币个数最小的方法。 例如，当要给某顾客找 7 角 2 分钱时，会给他一个 5 角， 2 个 1 角 和 1 个 2 分的硬币。试编写一个程序，输入的是要找给顾客的零 钱（以分为单位），输出的是应该找回的各种硬币数目，并保 证找回的硬币数最少。

 

Input Format

A line contains the total amount (以分为单位)



Output Format

Five lines that contain the number of  5 角、 1 角、 5 分、 2 分和 1 分 coins, respectively.

Sample Input

    101

Sample Output
 	2
	0
	0
	0
	1
*/

/*（2018/1/7）模拟题 什么年代了 还硬币 还1分2分5分的硬币 怕不是活在梦里
    我好菜 我不会递归.jpg*/

/*尝试使用递归……失败……完全不知道怎么计数…！！ 
#include <stdio.h>

struct ARR arr{
	int number[5];
};

struct ARR getMin(int val[], int value) {
	struct ARR arr;
	int min 
	for (int i = 0; i < 5; ++ i) {
		arr = 
	}
}

int main() {
	int value;
	scanf("%d", &value);
	int val[5] = {50,10,5,2,1};
	struct ARR results;
	for (int i = 0; i < 5; ++ i) results.array[i] = 0;
	
}*/


/*（2018/1/8）经过俞因的指导（ …） 由于此题的特殊性：一定是先大后小的情况（大数值的硬币数量一定小于小数值的硬币，且有“1”的硬币）， 所以考虑不使用递归，直接计数*/
#include <stdio.h>

int main() {
	int value[5] = {50,10,5,2,1};
	int num[5] = {0};
	int val;//总价值 
	scanf("%d", &val);
	for (int i = 0; val > 0; ++i) {
		while (val >= value[i]) {
			num[i] ++;
			val -= value[i]; 
		}
	}
	for (int i = 0; i < 5; ++ i) printf("%d\n", num[i]);
}

/*某大佬的答案  emm思路很简洁 
#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",n/50);
	n%=50;
	printf("%d\n",n/10);
	n%=10;
	printf("%d\n",n/5);
	n%=5;
	printf("%d\n",n/2);
	n%=2;
	printf("%d\n",n);
	return 0;
}*/ 
