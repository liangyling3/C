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
	BDAB*/ 
	
/*��2017/12/21���Լ����˺ܾã�����������ҳ����Ĵ���TAT */
/* ֪ʶ�㣺static��ʹ�ã��ݹ� */
/* ��ʹ��ѵ���漰���ݹ顢ѭ��ʱ��һ��Ҫע������ĸı���������¸�ֵ��������� */

#include <stdio.h>
#include <string.h>
#define max(x, y) x > y ? x : y

struct Result//��Ŀ�����Ĳ��� 
{
	char LCS[100];
};

struct Result LCS1(char text1[], char text2[]) {
	int i = strlen(text1) - 1, j = strlen(text2) - 1;
	/*�˴�һ��Ҫ��static����
	����static�Ļ���ÿ�εݹ�count��store�������±���ֵΪ0��
	��������store��ֻ�ܴ洢һ���ַ�*/
	static int count = 0;
	static struct Result store = {0};
	struct Result resultchar = {0}, result1 = {0}, result2 = {0}, zero = {0};
	char storechar;
	if (i == -1 || j == -1)	return zero;
	//β���ַ���ͬ��������ȴ���β���ַ�����ȥ��β���ַ��Ƚ�
	else if (text1[i] == text2[j]) {
		//ע�������ͬ�ַ���˳���ǴӺ���ǰ��
		store.LCS[count] = text1[i];
		count ++;
		text1[i] = text2[j] = 0;
		resultchar = LCS1(text1, text2);
		return store;
	}
	
	//β���ַ���ͬ�����
	else {
		//��ȥ����һ���ַ�����β���ַ����м���
		storechar = text1[i];
		text1[i] = 0;
		result1 = LCS1(text1, text2);
		//��ȥ���ڶ����ַ�����β���ַ����м���
		text1[i] = storechar;
		text2[j] = 0;
		result2 = LCS1(text1, text2);
		resultchar = strlen(result1.LCS) > strlen(result2.LCS) ? result1 : result2;
		return resultchar;
	}
}

/*������������е���ÿ�εݹ�Ҳ�ᵹ�򣬾ͺܻ���
�����������õ��ݹ�ĺ�������Ϊ��һ��������������ĺ������ٽ��е���*/
struct Result LCS(char text1[], char text2[]) {
	struct Result result = LCS1(text1, text2), resultchar = {0};
	int length = strlen(result.LCS);
	for (int k = 0; k < length; ++k) resultchar.LCS[k] = result.LCS[length - k - 1];
	return resultchar;
}

int main() {//��Ŀ�Ѿ������������� 
	char text1[100];
	char text2[100];
	scanf("%s", text1);
	scanf("%s", text2);
	
	struct Result result = LCS(text1, text2);
	printf("%s", result.LCS);
}
