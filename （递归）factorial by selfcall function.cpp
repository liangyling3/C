#include <iostream>
using namespace std;

int factorial(int n){
	if (n == 1) return 1;
	return n * factorial(n - 1);//通过调用自身实现递归 
}

int main(){
	int num;
	cin >> num;
	cout << factorial(num);
}
