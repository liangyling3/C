/*（2017/9/26） 思考怎么输出换行符想了好久… */
#include <stdio.h>
int main() {
	char x, y;
	scanf("%c %c", &x, &y);
	int ASC1 = (int) x, ASC2 = (int) y; 
	//取得输入字符的ASCII码
	int num = ASC1 + 9;
	for(int i = ASC1; i <= ASC2; ++ i){
		printf("%c", (char) i);
		for(; i == num; num += 10) printf("\n");
		//每隔十个字符输出一个换行符
	}
}
