#include<stdio.h>

/* Function prototype */
void found_letgrd(int num);

int main(){
	/* variables */
	int total,number,counter,average;
	
	/* initializies */
	total=0;
	number=0;
	counter=0;
	average=0;
	
	/* loop; get grade and display letter grade */
	do{
		scanf("%d",&number);		/* get the grade */		
		found_letgrd(number);		/* letter grade conversion */

		if(number>=0 && number<=100){
			total += number;
			counter++;
		}
		
	}while(number!=(-1));
	
	/* if first value is -1 to control */
	if(total==(-1))
		printf("0 F\n");
		
	else{		
		/* average grade to calculate */	
		average=total/counter;
	
		printf("%d ",average);
	
		/* call the function to convert */		
		found_letgrd(average);	
	}
	
	return 0;
}

/* convert the grade to the letter grade */
void found_letgrd(int num){
	
	if (num>=90) printf("A\n");
	else if (num>=80) printf("B\n");
	else if (num>=70) printf("C\n");
	else if (num>=60) printf("D\n");	
	else if (num<60 && num>=0) printf("F\n");	
}
