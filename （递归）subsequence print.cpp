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
	BDAB*/ 
	
/*（2017/12/21）自己看了很久，最后由俞因找出来的错误TAT */
/* 知识点：static的使用，递归 */
/* 惨痛教训：涉及到递归、循环时，一定要注意变量的改变情况和重新赋值情况！！！ */

#include <stdio.h>
#include <string.h>
#define max(x, y) x > y ? x : y

struct Result//题目给出的部分 
{
	char LCS[100];
};

struct Result LCS1(char text1[], char text2[]) {
	int i = strlen(text1) - 1, j = strlen(text2) - 1;
	/*此处一定要用static！！
	不用static的话，每次递归count和store都会重新被赋值为0，
	导致最后的store中只能存储一个字符*/
	static int count = 0;
	static struct Result store = {0};
	struct Result resultchar = {0}, result1 = {0}, result2 = {0}, zero = {0};
	char storechar;
	if (i == -1 || j == -1)	return zero;
	//尾端字符相同的情况，先存入尾端字符，再去掉尾端字符比较
	else if (text1[i] == text2[j]) {
		//注意存入相同字符的顺序是从后向前的
		store.LCS[count] = text1[i];
		count ++;
		text1[i] = text2[j] = 0;
		resultchar = LCS1(text1, text2);
		return store;
	}
	
	//尾端字符不同的情况
	else {
		//先去掉第一条字符串的尾端字符进行计算
		storechar = text1[i];
		text1[i] = 0;
		result1 = LCS1(text1, text2);
		//再去掉第二条字符串的尾端字符进行计算
		text1[i] = storechar;
		text2[j] = 0;
		result2 = LCS1(text1, text2);
		resultchar = strlen(result1.LCS) > strlen(result2.LCS) ? result1 : result2;
		return resultchar;
	}
}

/*如果在所求函数中倒序，每次递归也会倒序，就很混乱
因此在这里把用到递归的函数定义为另一个函数，在所求的函数中再进行倒序*/
struct Result LCS(char text1[], char text2[]) {
	struct Result result = LCS1(text1, text2), resultchar = {0};
	int length = strlen(result.LCS);
	for (int k = 0; k < length; ++k) resultchar.LCS[k] = result.LCS[length - k - 1];
	return resultchar;
}

int main() {//题目已经给出的主函数 
	char text1[100];
	char text2[100];
	scanf("%s", text1);
	scanf("%s", text2);
	
	struct Result result = LCS(text1, text2);
	printf("%s", result.LCS);
}
