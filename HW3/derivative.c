#include<stdio.h>
#include<math.h>
#include<string.h>
#define e 2.718
#define pi 3.14159
double special_derivative(double c,char choice[4],double x_value);
double derivative(double c,double x,double p);
double ln(double c,double x);
double exponantial(double c,char choice[4],double x);

int main(){
	
	int i,num,k,x,n,selection,status;
	char choice[4], standard;
	double c,p,last_value,last_value_ptr;
	double sum=0.0;
	
	printf("Number of the elements to calculate derivative : "); 
	scanf("%d",&num);  /* get the num of elements */
	double arr[num];
	printf("\n\nFirstly, enter a value for x ==>  "); 
	scanf("%d",&x);
	printf("\nEnter 1 for Special functions\n");
	printf("if it's not enter 2\n\n");
	
	for(i=0, n=1; i<num ;i++, n++){

		printf("\nEnter %d.element:\n",n);
		printf("enter 1 or 2:  ");
		scanf("%d",&selection);
		printf("\n");
		
		if(selection==2){
			printf("Enter as in the example: 2x3 or 4x0 or 1x0.5 etc.\n");
			scanf("%lf %s %lf",&c,choice,&p);
			last_value=derivative(c,x,p);
		}
		else{
			printf("Enter as in the example: 23ex, 1lnx, 3sinx, 2ax or 5-cosx for inverse etc.\n");
			scanf("%lf %s %c",&c,choice,&standard);
			last_value=special_derivative(c,choice,x);
		}	
		
		arr[i]=last_value;	

		sum+=arr[i];	

				
	}
	printf("Result is: %.4lf\n",sum);
	      
	return 0;
}

double derivative(double c,double x,double p){
	double result;
	if(p==0.5)
		result=c*p*sqrt(x);	
	else	
		result=c*p*pow(x,p-1);
		
	return result;

}

double special_derivative(double c,char choice[4],double x_value){

	double result,angel,rad,inverse;

	if(strcmp(choice,"log")==0){
		result=exponantial(c,choice,x_value);

	}	
	else if(strcmp(choice,"ln")==0){
		result=ln(c,x_value);

	}	
	else if(strcmp(choice,"e")==0 || strcmp(choice,"a")==0 ){
		result=exponantial(c,choice,x_value);

	}	
	else if(strcmp(choice,"sin")==0){
		printf("Enter an angel value:  ");
		scanf("%lf",&angel);
		rad=(pi * angel)/180.0;
		result=cos(rad);
	}
	else if(strcmp(choice,"cos")==0){
		printf("Enter an angel value:  ");
		scanf("%lf",&angel);
		rad=(pi * angel)/180.0;
		result=(-1)*sin(rad);
	}
	else if(strcmp(choice,"tan")==0){
		printf("Enter an angel value:  ");
		scanf("%lf",&angel);
		rad=(pi * angel)/180.0;
		result=pow(1/cos(rad),2);
	}
	else if(strcmp(choice,"-sin")==0){
		printf("inverse! Enter an value (-1,1):  ");
		scanf("%lf",&inverse);
		result=c/sqrt(1-(inverse*inverse));
	}
	else if(strcmp(choice,"-cos")==0){
		printf("inverse! Enter an value (-1,1):  ");
		scanf("%lf",&inverse);
		result=c*(-1)*(1/sqrt(1-(inverse*inverse)));
	}
	else if(strcmp(choice,"-tan")==0){
		printf("inverse! Enter an value in R:  ");
		scanf("%lf",&inverse);
		result=c*(1/sqrt(1+(inverse*inverse)));
	}
	return result;
}
double ln(double c,double x){

	return c*(1/x);

}
double exponantial(double c,char choice[4],double x){

	double result;
	int a;
	
	if(strcmp(choice,"e")==0)
		result=c*pow(e,x);
	else if(strcmp(choice,"a")==0){
		printf("Enter the base value:");
		scanf("%d",&a);
		result=c*log(a)*pow(a,x);
	}	
	else if(strcmp(choice,"log")==0){
		printf("Enter the base value:");
		scanf("%d",&a);
		result=c/(x*log(a));
	}	
	return result;	
}





