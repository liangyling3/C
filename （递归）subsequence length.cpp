/*Longest common subsequence problem (������ִ�)
����ַ���һ�������ַ��������ַ����е�˳�����������һ���ַ������У����ַ���һ��֮Ϊ�ַ��������Ӵ���
��ע�⣬����Ҫ���Ӵ����ַ���һ�����ַ����������������ַ������С����дһ�����������������ַ����������ǵ�����������У�����ӡ������������С�
	���磺���������ַ���BDCABA��ABCBDAB���ַ���BCBA��BDAB���������ǵ�����������У���������ǵĳ���4��

��Ȼ�������Ҳ��Ҫ���ҵݹ�ġ������ҵ�����sequence��һ����X������Ϊn����һ����Y������Ϊm�� 
���ڼ�����������point��һ����i��ָ��X�����һ��Ԫ���ϣ���һ����j��ָ��Y�����һ��Ԫ���ϡ����ǵĵݹ�Ӧ���Ƿ���������ġ� 
  �����X[i] == Y[j] ��ôLCS(X[i],Y[j]) = LCS(X[i-1],Y[j-1]) + 1
	��������ԣ���Ϊ������һ�鹫��Ԫ�أ��Ϳ�ʣ�µ��ж��ٹ���Ԫ�ء�
  �����X[i] != Y[j] ��ô LCS(X[i],Y[j]) = max( LCS(X[i-1], Y[j]), LCS(X[i], Y[j-1]) )
	�����ʵҲ��������ͬ������������ֲ�ͬ�ģ���ȥ��X��Y�����һ����Ȼ�����һ�������ıȽϣ�����ȥ��X����Y�����һ�����������ֿ��ܣ����Ծ���Ҫ���м�max��һ����
  ����� i=0 ���� j=0����return 0
	��Ϊ��һ��sequence�Ѿ����ˡ�
EXAMPLE INPUT
	BDCABA
	ABCBDAB
EXAMPLE OUTPUT 
	4*/ 
	
/*��2017/12/19�� ���Լ����ģ�������ô�����װ�(�� ����) */
#include <stdio.h>

//�𰸲��� start 
#include <string.h>
#define max(x, y) (x > y ? x : y)

int LCS(char text1[], char text2[]) {
	int maxlength = 0, length1 = 0, length2 = 0;
	char store;
	int i = strlen(text1) - 1, j = strlen(text2) - 1;
	//�ݹ�ͷ
	if (i == -1 || j == -1)	return 0;
	//β�������ַ���ͬ��������Ӵ�����Ϊȥ��β���ַ������ε�����Ӵ����ȼ���ȥ����1
	else if (text1[i] == text2[j]) {
		text1[i] = text2[j] = 0;
		maxlength = LCS(text1, text2) + 1;
	}
	//β�������ַ�����ͬ�������������ȥ������һ���ַ�����β���ַ����ٽ��бȽ�
	else  {
		//��ȥ����һ���ַ�����β���ַ����м���
		store = text1[i];
		text1[i] = 0;
		length1 = LCS(text1, text2);
		//��ȥ���ڶ����ַ�����β���ַ����м���
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
