/*Description

Input a string(end of '\n') of character(a-z, A-Z and '*') 

(such as "aBc*Def", "*AbC", "ABc*", "ABc*Acb*AAa*BbB*C", "***", "**", ......)

(You can use getchar method to get  each character and operate it.).

First,  convert the character you get to uppercase. When meet the first '*', convert the character you get to lowercase. And when meet the second '*', convert  the character you get to uppercase.when meet the third '*' ........

For example, "aBc*Def*Aaa*bBB"-->"ABC*def*AAA*bbb"

 
output format: no  '\n'

Sample Input 1
    aBc*Def*Aaa*bBB
    
Sample Output 1
    ABC*def*AAA*bbb


Sample Input 2
    Aaa*BbB**CCC*
    
Sample Output 2
    AAA*bbb**ccc*
    
    
Sample Input 3
    *
    
Sample Output 3
	*
*/

#include <stdio.h>
#include <string.h>

int main() {
	char arr[100]; 
	scanf("%s", &arr);
	int len = strlen(arr), countTimes = 0, i, j;	
	for (i = 0; i < len; ++i) 
		if (arr[i] <= 'z' && arr[i] >= 'a') arr[i] -= 'a' - 'A'; //��ʹ������ĸ��д 
	for (i = 0; i < len; ++ i) {
		if (arr[i] == '*') {
			countTimes ++;  //���� 
			if (countTimes % 2 != 0) { //��������������* ������ߵĴ�дȫ��ת��Сд 
				for (j = i + 1; j < len; ++ j) 
					if (arr[j] <= 'Z' && arr[j] >= 'A') arr[j] += 'a' - 'A'; 
			}
			else if (countTimes % 2 == 0) { //������ż������* ������ߵ�Сдȫ��ת�ɴ�д
				for (j = i + 1; j < len; ++ j) 
					if (arr[j] <= 'z' && arr[j] >= 'a') arr[j] -= 'a' - 'A'; 
			}
		}
	}	
	printf("%s",arr);
}
