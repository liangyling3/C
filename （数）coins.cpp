/*Description

Suppose there are five kinds of coins:  5 �ǡ� 1 �ǡ� 5 �֡� 2 �ֺ� 1 ��. Now we want to give change to the customer with as few coins as possible. Write a program to compute how many coins do we need.

 

�ٶ��� 5 �ǡ� 1 �ǡ� 5 �֡� 2 �ֺ� 1 �ֹ� 5 ��Ӳ�ң��� ���˿���Ӳ��ʱ��һ�㶼�ᾡ���ܵ�ѡ��Ӳ�Ҹ�����С�ķ����� ���磬��Ҫ��ĳ�˿��� 7 �� 2 ��Ǯʱ�������һ�� 5 �ǣ� 2 �� 1 �� �� 1 �� 2 �ֵ�Ӳ�ҡ��Ա�дһ�������������Ҫ�Ҹ��˿͵��� Ǯ���Է�Ϊ��λ�����������Ӧ���һصĸ���Ӳ����Ŀ������ ֤�һص�Ӳ�������١�

 

Input Format

A line contains the total amount (�Է�Ϊ��λ)



Output Format

Five lines that contain the number of  5 �ǡ� 1 �ǡ� 5 �֡� 2 �ֺ� 1 �� coins, respectively.

Sample Input

    101

Sample Output
 	2
	0
	0
	0
	1
*/

/*��2018/1/7��ģ���� ʲô����� ��Ӳ�� ��1��2��5�ֵ�Ӳ�� �²��ǻ�������
    �Һò� �Ҳ���ݹ�.jpg*/

/*����ʹ�õݹ顭��ʧ�ܡ�����ȫ��֪����ô���������� 
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


/*��2018/1/8�����������ָ���� ���� ���ڴ���������ԣ�һ�����ȴ��С�����������ֵ��Ӳ������һ��С��С��ֵ��Ӳ�ң����С�1����Ӳ�ң��� ���Կ��ǲ�ʹ�õݹ飬ֱ�Ӽ���*/
#include <stdio.h>

int main() {
	int value[5] = {50,10,5,2,1};
	int num[5] = {0};
	int val;//�ܼ�ֵ 
	scanf("%d", &val);
	for (int i = 0; val > 0; ++i) {
		while (val >= value[i]) {
			num[i] ++;
			val -= value[i]; 
		}
	}
	for (int i = 0; i < 5; ++ i) printf("%d\n", num[i]);
}

/*ĳ���еĴ�  emm˼·�ܼ�� 
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
