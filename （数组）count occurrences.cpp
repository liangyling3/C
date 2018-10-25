/*Read 100 integers.
Print all numbers once and their number of occurrences.
EXAMPLE INPUT 
      6      5      3      1      5      2      4      7      7      4
     10      1      3      5      4      5      2      1      9      1
      7      9      9      3      1     10      8      9      1      1
      7      3      4      6      5      8      4      0      8      6
      5      2      8      2      5      5      9      3      5      8
      3      1      6      6      6      3      0      2      7      7
     10      3      8      6      8      1      8      9      2      3
      5      2      1      6      7      7      6      1      5      9
      0      7     10      4      9      5      5      6      7      5
      7      1      8      0      1      2      7      6     10     10
EXAMPLE OUTPUT 
	6 11
	5 14
	3 9
	1 13
	2 8
	4 6
	7 12
	10 6
	9 8
	8 9
	0 4*/
	
#include <stdio.h>
int main() {
	int num[100], count[11], val[11];
	//依次为：数值数组、计数数组、打印数组
	int k = 0;
	for (int i = 0; i < 100; ++i) {
		scanf("%d",&num[i]);
		for (int j = 0; j < 1000; ++j) {
			if (num[i] == j)
				++count[j];//此处进行计数
			if (num[i] == j && count[j] == 1){
				val[k] = num[i];
				//避免重复，取得单个数值的输出顺序
				++k;
			}
		}
	}
	for (int j = 0; j < 11; ++j) {
		printf("%d %d\n",val[j],count[val[j]]);
	}
}
