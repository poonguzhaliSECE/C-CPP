#include <stdio.h>
  enum door_status{
  	LOCKED,
  	UNLOCKED,
  	OPEN
  };
 typedef int a;
 int main(void){
 	a num=5;
 	enum door_status d;
 	scanf("%d",&d);
 	switch(d){
 		case LOCKED:
 			printf("Door is locked");
 			break;
 		case UNLOCKED:
		 printf("Door is UNLOCKED");
		 break;	
		 case OPEN:
		 	printf("Door is opened");
		 	break;
	 }
 }
