#include<stdio.h>

int main(){
	int sum =0, n=5;

	for(int i= 0; i <= n; ++i){
		sum += i;
	}

	printf("Sum of the series is %d", sum);


	return 0;
}
