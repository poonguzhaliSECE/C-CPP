#include<stdio.h>
int main(void){
	int number,flag=0;
	printf("Enetr a number to check if it is prime or not");
	scanf("%d",&number);
	//check if number is prime or not
	for (int i=2;i<number;i++){
		if(number%i==0){
			flag=1;
			
		}
		
	}
	if(flag==1){
	printf("number is not prime");	
	}
	
	return 0;
}
