#icnlude <iostream>
using namespace std;

void selfcall(int times){
	-- times;
	cout << times << endl;
	if (times > 0){
		selfcall(times);//���������� 
		//ÿ�ε��þ������ڴ�ռ䣨ÿ���ڴ�ռ以��Ӱ�죩
		//�ͷ��ڴ�ռ�˳��3 ��2 ��1 ��main 
	}
	cout << times << endl;//���������3 ��2 ��1 
}

int main(){
	selfcall(3);
}
