#icnlude <iostream>
using namespace std;

void selfcall(int times){
	-- times;
	cout << times << endl;
	if (times > 0){
		selfcall(times);//先运行三次 
		//每次调用均申请内存空间（每次内存空间互不影响）
		//释放内存空间顺序：3 →2 →1 →main 
	}
	cout << times << endl;//此行输出从3 →2 →1 
}

int main(){
	selfcall(3);
}
