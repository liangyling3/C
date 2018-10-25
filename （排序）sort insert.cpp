#include <stdio.h> 

void readData(int array[]) { 
    int i; 
    for (i = 0; i < 10; ++ i) { 
        scanf("%d", &array[i]); 
    } 
} 
 
void print(int array[]) { 
    int i; 
    for (i = 0; i < 10; ++ i) { 
        printf("%d ", array[i]); 
    } 
    putchar('\n');
} 
 
void insertionSort (int data[], int times) {
	int i, j, store;
	if (times == 0) return;
	insertionSort (data, times - 1);
	for (i = times - 1; i >= 0; -- i) {
		if (data[times - 1] < data[i]) {
			store = data[times - 1];
			for (j = i + 1; j < times; ++ j)
				data[j] = data[j - 1];
			data[i] = store;
			print(data);
			}
		}
} 

int main() { 
    int data[10]; 
    readData(data); 
    insertionSort(data, 10); 
} 
