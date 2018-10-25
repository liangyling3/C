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

/*（2018/1/7）模拟题 +7和+C大佬到底是什么人…… 不知道为什么好意思说“为了简化，倒序时包含0”，明明更复杂了垃圾 qswl*/
#include <stdio.h>
#include <string.h>

struct ARR{//使可以返回一个数组 
	char array[20];
};

struct ARR reverse1(long int num) {
	struct ARR arr;
	for (int i = 0; i < 20; ++ i) arr.array[i] = 0;//一定要初始化！不然每次返回的都是长度为5的字符串（？ 
	for (int i = 0; num > 0; ++ i) {
		arr.array[i] = num % 10 + '0';//一定注意数值转化为字符时加上‘0’的ascii码！！！ 
		//此处直接倒序储存，返回的即为倒序，且包含字符0 
		num /= 10;
	}
	return arr;
}

long int reverse2(long int num) {//对数值进行倒序的函数 
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
	printf("%s ", arr.array);//输出字符串 
	printf("%ld\n", num);
}

int main() {
	int times;
	scanf("%d",&times);
	for(int i = 0; i < times; ++ i) {
		struct ARR arr;
		long int num1, num2;
		scanf("%d %d", &num1, &num2);
		arr = reverse1(num1);//字符串倒序 
		num1 = reverse2(num1);//数值倒序 
		num2 = remainder(num1,num2);
		printout(arr,num2);
	}
}

/*补充 某大佬的答案
#include <stdio.h>
#include <string.h>

int main()
{
 int T;
 scanf("%d",&T);
 while(T--)      //循环执行次数 
 {
  int num;   //数值1 
  int mod;   //数值2 
  int rum=0;
  int f=0;
  char pre[20]="";
  scanf("%d%d",&num,&mod);
  while(num>0)  //执行循环 
  {
   if(!(num%10) && !f) strcat(pre,"0");  //strcat：将两个char类型连接，此处是如果num中有后置零的话，则存入pre数组中 
   else f++;
   rum=rum*10+num%10;
   num/=10;
  }
  printf("%s%d %d\n",pre,rum,rum%mod);   //输出：前置零+倒序后的数值  
 }
 return 0;
}*/
