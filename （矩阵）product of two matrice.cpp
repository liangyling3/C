/*Description

This C Program computes the product of two matrices. This program accepts the two (3X3) matrices and then find the product of 2 matrices.

Sample Input

    4 5 6
    1 2 3
    3 7 8
    5 6 9
    8 5 3
    2 9 1

Sample Output

    72 103 57 
    27 43 18 
    87 125 56 

Attention

ע���������ĸ�ʽ��

���һ��3��3�еľ���ÿһ����������һ���ո񣨰���ÿ�е����һ������������л���

*/ 

#include <stdio.h> 

int main() {
	int m1[3][3], m2[3][3], m3[3][3] = {0};
	for (int i = 0; i < 3; ++ i) {//�����һ������ 
		for (int j = 0; j < 3; ++ j)
			scanf("%d", &m1[i][j]);
	}
	for (int i = 0; i < 3; ++ i) {//����ڶ������� 
		for (int j = 0; j < 3; ++ j)
			scanf("%d", &m2[i][j]);
	}
	
	for (int i = 0; i < 3; ++ i) {
		for (int j = 0; j < 3; ++ j) 
			m3[i][j] = m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j] + m1[i][2]*m2[2][j];
	}
	
	for (int i = 0; i < 3; ++ i) {
		for (int j = 0; j < 3; ++ j) 
			printf ("%d ", m3[i][j]);
		printf("\n");
	}
} 
