#include<stdio.h>
 #include<string.h>
 void main()
 {
 	int len,i,count=0;
 	char a[10];
 	printf("Enter the Name : ");
 	scanf("%s",a);
 	len=strlen(a);
 	for(i=0;i<len;++i){
 	if(a[i]==a[len-i-1])
 	count++;
 }
 if(len==count)
 printf( "Palindrome");
 else
 printf("not a palindrome");
}
