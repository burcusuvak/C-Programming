/*  Burcu SUVAK OZTURK                                        */
/*  141044079                                                 */

#include<stdio.h>
#include<math.h>

int binary(int n,int i);

int main(){
	int count=0,num;
	printf("Please enter a number\n >>");
	scanf("%d",&num);
	
	printf("\nBinary representation:  %d\n\n",binary(num,count));
	
    return 0;
}

int binary(int n,int i){

    int remainder;
    /* Base case */
    if(n/2==0)
        remainder=1*pow(10,i);
    else
    	remainder= (n%2)*pow(10,i)+ binary(n/2,i+1);

	return remainder;
}
