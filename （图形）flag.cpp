/*Draw the following mxn character American flag.
m and n are read from the standard input.
m is odd and n is even.
	EXAMPLE INPUT 1 
		13 40
	EXAMPLE OUTPUT 1 
		* * * * * * * * * * ====================
 		* * * * * * * * * *                    
		* * * * * * * * * * ====================
		 * * * * * * * * * *                    
		* * * * * * * * * * ====================
		 * * * * * * * * * *                    
		========================================
		                                        
		========================================
                                        
		========================================
                                        
		========================================

	EXAMPLE INPUT 2 
		15 30	
	EXAMPLE OUTPUT 2 
		* * * * * * * *===============
		 * * * * * * *                
		* * * * * * * *===============
		 * * * * * * *                
		* * * * * * * *===============
		 * * * * * * *                
		* * * * * * * *===============
                              
		==============================
                              
		==============================
                              
		==============================
                              
		==============================
		*/

/*��2017/10/19��������д�����ˣ������������Ϊһ��Сbug����(�ħ���)*/
#include <stdio.h>
void rowodd(int x){
	//�ϰ벿�������е����,xΪ���������xΪż��
	if(x % 4 ==0){
		for(int i = 0; i < x / 4; ++i) printf("* ");
		for(int j = 0; j < x / 2; ++j) printf("=");
	}
	else{
		for(int i = 0; i < (x - 2) / 4; ++i) printf("* ");
		printf("*");
		for(int j = 0; j < (x / 2); ++j) printf("=");
	}
	printf("\n");
}

void roweven(int x){
	//�ϰ벿��ż���е����,xΪ���������xΪż��
	if(x % 4 ==0){
		for(int i = 0; i < x / 4; ++i) printf(" *");
		for(int j = 0; j < x / 2; ++j) printf(" ");
	}
	else{
		for(int i = 0; i < (x - 2) / 4; ++i) printf(" *");
		printf(" ");
		for(int j = 0; j < (x / 2); ++j) printf(" ");
	}
	printf("\n");
}

void rowdown(int x,int r){
	//�°벿�ֵ����,xΪ������xΪż��,rΪ��������
	if (r % 2 != 0){
		for(int i = 0; i < x; ++i) printf("=");
	}
	else{
	for(int j = 0; j < x; ++j) printf(" ");
	}
	
	printf("\n");
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i = 1; i < m + 1; i++){
		if (i < (m + 1) / 2){
			if (i % 2 != 0) rowodd(n);
			else roweven(n);
		}
		else rowdown(n,i);
	}
}
	
