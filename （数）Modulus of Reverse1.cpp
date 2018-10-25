/*Description

+7 dalao would like to reverse a number, and +C dalao would like to see the remainder (modulus) after division of the reversed number by a second number. So please tell +7 the reversed number and +C the remainder.

Details

In the first line of the input is a number n (1 <= n <= 10) representing the number of the test cases.

Each of the following n lines consists of two integers a and b (1 <= a, b <= 10000000), where a is the one to be reversed, and b is the divisor to be used to get the remainder.

    5
    12345 10
    2345 32
    43245 98
    83929 231
    1 2
    

In this input:

- There are five test cases.
- In the first test case, output the reversed number of 12345, namely 54321, and then output the remainder of 54321 / 10, namely 1.
- In the second test case, output the reversed number of 2345, namely 5432, and then output the remainder of 5432 / 32, namely 24
- ...

And the corresponding output would be:

    54321 1
    5432 24
    54234 40
    92938 76
    1 1
    

Note: the reversed number of 500 would be 005. Numbers beginning with 0 such as 005 will not be given in the input for simplicity.
*/

/*��2018/1/7��ģ���� +7��+C���е�����ʲô�ˡ��� ��֪��Ϊʲô����˼˵��Ϊ�˼򻯣�����ʱ����0�������������������� qswl*/
#include <stdio.h>
#include <string.h>

struct ARR{//ʹ���Է���һ������ 
	char array[20];
};

struct ARR reverse1(long int num) {
	struct ARR arr;
	for (int i = 0; i < 20; ++ i) arr.array[i] = 0;//һ��Ҫ��ʼ������Ȼÿ�η��صĶ��ǳ���Ϊ5���ַ������� 
	for (int i = 0; num > 0; ++ i) {
		arr.array[i] = num % 10 + '0';//һ��ע����ֵת��Ϊ�ַ�ʱ���ϡ�0����ascii�룡���� 
		//�˴�ֱ�ӵ��򴢴棬���صļ�Ϊ�����Ұ����ַ�0 
		num /= 10;
	}
	return arr;
}

long int reverse2(long int num) {//����ֵ���е���ĺ��� 
	long int rem, sum = 0; 
	for(; num > 0; ) {
		rem = num % 10;
		sum = sum*10 + rem;
		num /= 10;
	}
	return sum;
}

long int remainder(long int num1, long int num2) {
	return num1 % num2;
}

void printout(struct ARR arr, long int num) {
	printf("%s ", arr.array);//����ַ��� 
	printf("%ld\n", num);
}

int main() {
	int times;
	scanf("%d",&times);
	for(int i = 0; i < times; ++ i) {
		struct ARR arr;
		long int num1, num2;
		scanf("%d %d", &num1, &num2);
		arr = reverse1(num1);//�ַ������� 
		num1 = reverse2(num1);//��ֵ���� 
		num2 = remainder(num1,num2);
		printout(arr,num2);
	}
}

/*���� ĳ���еĴ�
#include <stdio.h>
#include <string.h>

int main()
{
 int T;
 scanf("%d",&T);
 while(T--)      //ѭ��ִ�д��� 
 {
  int num;   //��ֵ1 
  int mod;   //��ֵ2 
  int rum=0;
  int f=0;
  char pre[20]="";
  scanf("%d%d",&num,&mod);
  while(num>0)  //ִ��ѭ�� 
  {
   if(!(num%10) && !f) strcat(pre,"0");  //strcat��������char�������ӣ��˴������num���к�����Ļ��������pre������ 
   else f++;
   rum=rum*10+num%10;
   num/=10;
  }
  printf("%s%d %d\n",pre,rum,rum%mod);   //�����ǰ����+��������ֵ  
 }
 return 0;
}*/
