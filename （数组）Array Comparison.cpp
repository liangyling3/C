/*Description

Compare two arrays and count the number of different elements. The rule is to count from the last element to the first one.  If the size of the two arrays are different,  then the extra elements in the longer array are ignored.

For example:

The number of different element between {1,3,5} and {77,21,1,3,5} is 0.

The number of different element between {21,1,2,5} and {77,21,1,3,5} is 1.

 

比较两个数组，要求从数组最后一个元素开始逐个元素向前比较，如果2个数组长度不等，则只比较较短长度数组个数元素。请编程实现上述比较，并返回比较中发现的不相等元素的个数。

 

Input Format

The first line contains the length of the first array len1 (0≤len1≤20)

The next len1 lines contain the len1 elements of the first array, each of which is an integer.

The next line contains the length of the first array len2 (0≤len2≤20)

The next len2 lines contain the len2 elements of the second array, each of which is an integer.

Output Format

The number of different elements.

Sample Input

    2
    13
    12
    3
    12
    4
    13

Sample Output
	2
*/

#include <stdio.h>
#define min(x,y) x < y ? x : y

int compare(int arr1[], int arr2[], int len1, int len2) {
	int i = len1-1, j = len2-1, count = 0;
	for (; i >= 0 && j >= 0; --i, --j) {//从后向前比较 
		if (arr1[i] != arr2[j]) count++;
	}
	return count;
}

int main() {
	int len1, len2;
	int arr1[20], arr2[20];
	scanf("%d",&len1);
	int i, j;
	for (i = 0; i < len1; ++i) 
		scanf("%d",&arr1[i]);
	scanf("%d",&len2);
	for (j = 0; j < len2; ++j) 
		scanf("%d",&arr2[i]);
	int diff = compare(arr1,arr2,i,j);	
	printf("%d",diff);
}
