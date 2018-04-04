#include<stdio.h>

#define PI 3.141592

int part1(void);
double power(double x, int n);
long factorial(int x);
double sin_tyl(double x, int num_of_terms);

int main(){
		
	part1();	
		
}

int part1(void){
	
	double angle;
	int term;
	
	printf(" Enter an angle to calculate the sinus:\n");
	scanf("%lf",&angle);
	
	printf(" Enter terms value:\nIts max value should be 8 !\n");   /*for finite series*/
	scanf("%d",&term);
	
	
	if(term<0 || term >7 )
		return -1;
	else		
		sin_tyl(angle,term);

}

double power(double x, int n){

	double p=1.0;
	int i;
	
	if(n==0)
		p=1;
	else{	
		for(i=1;i<=n;i++){
			p*=x;	
		}
	}
	return p;
}

long factorial(int x){

	int i=1,result=1;
	
	while(i<=x) result*=i++;
	
	return result;
		
}

double sin_tyl(double x, int num_of_terms){

	double rad=0;
	double sum=0;
	double pow_x,sign;
	int n;
	long fact;
	if(x>360)
		x%=360;
	if(x<0){
		while(x<0){
			x+=360;
		}	
	}
	
	rad=(PI * x)/180.0;
	printf("rad:%lf\n",rad);	 
	for(n=0; n<num_of_terms; n++){
		sign=power(-1,n);
		pow_x=power(rad,(2*n+1));
		fact=factorial(2*n+1);
		sum += sign* (pow_x / fact);

	}
	printf("Sinus : %lf\n",sum);    
	          
	return 0;
	
}



