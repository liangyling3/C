/*Description

Search a specified number in a given nonnegative series.If the number is found, return the index (start from 0), otherwise return -1. All numbers in the series are different.

Input Format

The first line is an integer indicating the number of test cases below.  Each test case line is ended with ¡®-1¡¯, and the number before "-1" is the specific value that you need to search in the rest of the line.

There are at most 100 numbers in each series. Each number is between 0 and 1000.

Output Format

The search results, with each in one line.

Sample Input
    2
    3 5 19 234 12 -1    
    32 987 1 20 1 -1    

Sample Output
	-1
	2
*/

#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		int num[100], i, j, count = 0;
		for (i = 0; ; ++ i) {
			scanf("%d",&num[i]);
			if (num[i] == -1) break;
		}
		for (j = 0; j < i-1; ++ j) {
			if(num[j] == num[i-1]) {
				printf("%d",j);
				count ++;
			}
		}
		if (count == 0) printf("-1");
		printf("\n");
	}
} 
