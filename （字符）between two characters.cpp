/*��2017/9/26�� ˼����ô������з����˺þá� */
#include <stdio.h>
int main() {
	char x, y;
	scanf("%c %c", &x, &y);
	int ASC1 = (int) x, ASC2 = (int) y; 
	//ȡ�������ַ���ASCII��
	int num = ASC1 + 9;
	for(int i = ASC1; i <= ASC2; ++ i){
		printf("%c", (char) i);
		for(; i == num; num += 10) printf("\n");
		//ÿ��ʮ���ַ����һ�����з�
	}
}
