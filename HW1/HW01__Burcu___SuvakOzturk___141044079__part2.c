/* the program for the four operations until entering "=" */
#include<stdio.h>

int main(){
								/* variables */
	char chr,leave_chr;
	int num,temp,result;

	leave_chr='=';				/* the variable to calculate and assignment */
	result=0;					/* initializies */
	num=0;						/*				*/
	
	scanf("%d",&num);			/* get the integer number */
	result=num;
	do{							/* do-while loop to calculate and get number */
		scanf(" %c",&chr);		/* get the a character for four operations */
		if(chr!=leave_chr)
			scanf("%d",&num);

			
		switch(chr){			/* switch statement -four operations- */
			case '+': result+=num; break;
			case '-': result-=num; break;
			case '*': result*=num; break;
			case '/': result/=num; break;
		}

	}while(chr!=leave_chr);		/* the loop condition to exit  */
	
	printf("%d\n",result);		/* to display the result */
	
	return 0;

}
