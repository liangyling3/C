/*Description

What is the sum of all the integers (0 <= integer <= 100) that are on the main diagonal or antidiagonal of a given square matrix?

Details

In the first line of the input is a number n (1 <= n <= 10) representing the number of the test cases.

Each case contains n + 1 lines, with one line representing the size (1 <= size <= 10) of the square matrix, and the following n lines representing the square matrix.

    2
    3
    1 0 1
    0 1 0
    1 0 1
    4
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16

In this input:

- There would be two test cases.
- In the first test case, the matrix would be of size 3, and the sum to output would be 5 (= 1 + 1 + 1 + 1 + 1)
- In the second test case, the matrix would be of size 4, and the sum to output would be 68 (= 1 + 4 + 6 + 7 + 10 + 11 + 13 + 16)

Thus the corresponding output would be:
	5
	68
*/ 

#include <stdio.h>

int add() {
	int len;
	scanf("%d", &len);
	int arr[10][10], sum = 0;//创建一个二维数组 
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			scanf("%d", &arr[i][j]);
			if (i>0 && i < len-1 && j> 0 && j<len-1) sum += arr[i][j];//排除掉四边的数值 
		}
	}
	sum = sum + arr[0][0] + arr[len-1][0] + arr[len-1][len-1] + arr[0][len-1];//加上四角的数值 
	return sum;
}

int main() {
	int times;
	scanf("%d", &times);
	for (int i = 0; i < times; ++ i) {
		int sum = add();
		printf("%d\n", sum);
	}
}
