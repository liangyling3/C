/*Longest common subsequence problem (最长公共字串)
如果字符串一的所有字符按其在字符串中的顺序出现在另外一个字符串二中，则字符串一称之为字符串二的子串。
·注意，并不要求子串（字符串一）的字符必须连续出现在字符串二中。请编写一个函数，输入两个字符串，求它们的最长公共子序列，并打印出最长公共子序列。
	例如：输入两个字符串BDCABA和ABCBDAB，字符串BCBA和BDAB都是是它们的最长公共子序列，则输出它们的长度4。

当然这里，我们也是要先找递归的。假设我的两个sequence，一个是X，长度为n；另一个是Y，长度为m。 
现在假设我有两个point，一个是i，指在X的最后一个元素上，另一个是j，指在Y的最后一个元素上。我们的递归应该是分三种情况的。 
  ·如果X[i] == Y[j] 那么LCS(X[i],Y[j]) = LCS(X[i-1],Y[j-1]) + 1
	这个很明显，因为发现了一组公共元素，就看剩下的有多少公共元素。
  ·如果X[i] != Y[j] 那么 LCS(X[i],Y[j]) = max( LCS(X[i-1], Y[j]), LCS(X[i], Y[j-1]) )
	这个其实也很容易相同，就是如果发现不同的，就去掉X或Y的最后一个，然后和另一个完整的比较，这样去掉X还是Y的最后一个，就有两种可能，所以就是要找中间max的一个。
  ·如果 i=0 或者 j=0，就return 0
	因为有一个sequence已经完了。
EXAMPLE INPUT
	BDCABA
	ABCBDAB
EXAMPLE OUTPUT 
	4*/ 
	
/*（2017/12/19） 是自己做的！！！多么不容易啊(Ｔ ▽Ｔ) */
#include <stdio.h>

//答案部分 start 
#include <string.h>
#define max(x, y) (x > y ? x : y)

int LCS(char text1[], char text2[]) {
	int maxlength = 0, length1 = 0, length2 = 0;
	char store;
	int i = strlen(text1) - 1, j = strlen(text2) - 1;
	//递归头
	if (i == -1 || j == -1)	return 0;
	//尾端两个字符相同，则最长公子串长度为去掉尾端字符后，两段的最长公子串长度加上去掉的1
	else if (text1[i] == text2[j]) {
		text1[i] = text2[j] = 0;
		maxlength = LCS(text1, text2) + 1;
	}
	//尾端两个字符不相同，分两种情况，去掉其中一段字符串的尾端字符后再进行比较
	else  {
		//先去掉第一条字符串的尾端字符进行计算
		store = text1[i];
		text1[i] = 0;
		length1 = LCS(text1, text2);
		//再去掉第二条字符串的尾端字符进行计算
		text1[i] = store;
		text2[j] = 0;
		length2 = LCS(text1, text2);
		maxlength = max(length1, length2);
	}
	return maxlength;
}
//end 

int main() {
	char text1[100];
	char text2[100];
	scanf("%s", text1);
	scanf("%s", text2);
	
	printf("%d", LCS(text1, text2));
}
