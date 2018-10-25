/*Description

Input N test cases. Each test case contains two strings X and Y, both consisting of only lower-case letters. Find Y in X, if Y is a substring of X, output 1, else output 0.

The first line is the number of test case N. Following N pairs of strings are input, each sperating by a blank space. 1<=N<=10, 1<=|X|<=50, 1<=|Y|<=50.

Each output ends with '\n'.

Sample Input
    2
    abcdefg abc
    abcdefg bce

Sample Output
	1
	0
*/

/*（2018/1/8）能纠结很久的永远都是很小的错误……（跪）*/
#include <stdio.h>
#include <string.h>

int compare(char arr1[], char arr2[]) {
	int len1 = strlen(arr1), len2 = strlen(arr2);
	int i, j, k;
	for (i = 0; i < len1; ++ i) {
		if (arr1[i] == arr2[0]) {
			int count = 0;
			for (j = i, k = 0; k < len2; ++j,++k) {
				if (arr1[j] == arr2[k]) count++;
			}
			if (count == len2) return 1;
		}
	}
	return 0;
}

int main() {
	int times;
	char arr1[50], arr2[50]; 
	scanf("%d",&times);
	while(times --) {
		scanf("%s%s",arr1,arr2);//使用scanf-%s读入时遇到空格或换行就停止了！！！gets（）是遇到换行才会停止！！ 
		printf("%d\n", compare(arr1, arr2));
	}
}


/*某大佬的答案 

#include <stdio.h>
#include <string.h>

int main()
{
 int T;
 scanf("%d",&T);
 while(T--)
 {
  char s1[70],s2[70];
  scanf("%s%s",s1,s2); 
  if(strstr(s1,s2)!=NULL) printf("1\n"); //？？？？？还有这种函数 ？？？？？？？ 
  else printf("0\n");
 }
 return 0;
}*/
