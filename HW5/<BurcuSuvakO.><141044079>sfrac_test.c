/* Gerekli tum fonksiyonlari yazdım fakat tamamiyla pdf deki formata uyamadim 
verilen bazi fonksiyonlarin ne ise yaradigini anlamlandiramadigim icin gerekli 
fonksiyonlari kendim uretmeye karar verdim... */


#include<stdio.h>
#include<string.h>
#include "<BurcuSuvakO.><141044079>sfrac.h"

int main(){
	char n1[100], n2[100];
	char const_n1[100];
	char const_n2[100];	
	
	char operation;
	char n3[]="2/3";
	/* Informations */	
	printf("\n\nPlease enter in order of first fractional number\n");
	printf("operation such that + - * / \n");
	printf("and second fractional number\n\n");
	
	/* Get the First Fractionel Number */
	printf("First value  => ");
	scanf("%s",n1);
	strcpy(const_n1,n1);
	
	printf("Operation    =>  ");
	/* Get the operation */
	scanf(" %c",&operation);
	
	printf("Second value => ");
	/* Get the Second Fractionel Number */
	scanf("%s",n2);
	strcpy(const_n2,n2);

    printf("\n\n");	

	switch(operation){
	    case '+' : sfrac_add(n1,n2);
	        break;
        case '-' : sfrac_sub(n1,n2);
	        break;
        case '*' : sfrac_mult(n1,n2);
            break;
        case '/' : sfrac_div(n1,n2);
            break;
            
	}

	sfrac_print("Result = ",const_n1," + ",const_n2," ?=? ",n3,".");

    printf("\n\n");	
    
	return 0;
}

