#include <stdio.h>
void gcd(int x,int y){
	for(;x != y;){
		if(x > y) x -= y;
		else y -= x;
	}
	//�˴����ø��������
	printf("%d\n",x);
}

int main(){
	for(int i = 0; i < 5; ++i){
		int x,y;
		scanf("%d %d",&x,&y);
		gcd(x,y);
	}
}
