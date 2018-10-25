#include <stdio.h>
void judge(double x){
	scanf("%lf",&x);
	int min = 0, max = 10, i = 0;
	while(i < 10 && (!(x > min) || !(x <= max))){
	//×¢ÒâÅÐ¶ÏÌõ¼þ 
		min = min + 10;
		max = max + 10;
		i = i + 1;
	}	
	printf("(%d,%d]\n",min,max);
}

int main(){
	double x;
	for(int i = 0;i < 5;++i) judge(x);
}
