#include<stdio.h>
#include<string.h>
#include "<BurcuSuvakO.><141044079>sfrac.h"
/*******   Function Definitions   ********/
int num_size(int x){
	int i;
	if(x<0)
		x*=(-1);
		
	for(i=1;x>9;++i)
		x/=10;
	return i;
}

void seperate_num(int num,int n[],int size){

	int i,digit=0,k;
	k=size;

	for(i=0; num>0; ++i,size--){
		digit=num%10;
		n[size-1]=digit;
		num/=10;
	}
}	
void convert_toint(char *x,int *num1,int *num2){	
	int i,find=0;
	
	if(x[0]==0){
	    *num1=0;
	    *num2=0;
	}

	for(i=0;x[i]!='\0';++i){
		if(x[i]=='/')
			find=1;
	}
	if(find==1){
		*num1=atoi(strtok(x,"/"));
		*num2=atoi(strtok(NULL,"/"));
	}
	else{
		*num1=atoi(strtok(x,"\0"));
		*num2=1;	
	}

}
char *convert_tochar(char *x,int *num1,int *num2){
	
	int numer_int[100]={0},numer_int2[100];
	int size,size2,sum=0,i,k=0,p=0,l;
		
	/*num1*/
	if( (*num1)>0 ){
		size=num_size(*num1);
		seperate_num(*num1,numer_int,size);
		for(i=0;i<size;++i){
			x[i]=numer_int[i]+'0';
		}
	
		x[i]='/';/*****/
		
		/*num2*/
		size2=num_size(*num2);
		sum=size+size2+1;
		seperate_num(*num2,numer_int2,size2);
		for(k=i+1; k<sum; ++k,++p){
			x[k]=numer_int2[p] +'0';
		}
		x[sum]='\0';
	}
	else{
		(*num1)=(*num1)*(-1);
		size=num_size(*num1);
		seperate_num(*num1,numer_int,size);

		x[0]='-';
		for(i=1,l=0 ;i<=size;++i,++l){
			x[i]=numer_int[l]+'0';
		}
	
		x[i]='/';/**/
		/*num2*/
		size2=num_size(*num2);
		sum=size+size2+1;
		seperate_num(*num2,numer_int2,size2);
		
		for(k=i+1; k<=sum; ++k,++p){
			x[k]=numer_int2[p] +'0';
		}
		x[sum+1]='\0';	
	}
	return x;	

}
void gcd(int *n1,int *n2){
	int i,min,gcd=1;
	if( (*n1)<0 ){
		(*n1)=(*n1)*(-1);	
		if((*n1)<(*n2))
			min=*n1;
		else
			min=*n2;	
		for(i=2; i<=min; ++i){
			if((*n1)%i==0 && (*n2)%i==0)
				gcd=i;			
		}
		*n1/=gcd;
		*n2/=gcd;
		(*n1)=(*n1)*(-1);
	}
	else{
		if((*n1)<(*n2))
			min=*n1;
		else
			min=*n2;	
		for(i=2; i<=min; ++i){
			if((*n1)%i==0 && (*n2)%i==0)
				gcd=i;			
		}
		*n1/=gcd;
		*n2/=gcd;	
	}				
}
char *sfrac_simplify(char * n){

	/* numerator and denominator */
	int numer,denom;   
	
	convert_toint(n,&numer,&denom);
	
	/* for divide by zero as number/0 */	
	if(denom==0 && numer!=0){
		printf("Undefined!\n\n");
	}	
	/* for multiply by zero */
	else if(numer==0 || denom==0){
		n[0]='0';
		n[1]='\0';
		printf("Result is %s\n\n",n);
	}	
	else{
		gcd(&numer,&denom);	
		printf("Result is %s\n\n",convert_tochar(n,&numer,&denom));
	}	
	return n;
}

char * sfrac_add(char * n1, char * n2){
	/*numerator and denominator of num1 and num2*/
	int numer1,denom1,numer2,denom2;
	int cm_numer,cm_denom;
	char fractional[100];
	
	convert_toint(n1,&numer1,&denom1);
	convert_toint(n2,&numer2,&denom2);
	
	if(denom1!=denom2){
		cm_numer=numer1*denom2+numer2*denom1;
		cm_denom=denom1*denom2;
	}
	else{
		cm_numer=numer1+numer2;
		cm_denom=denom1;
	}
	convert_tochar(fractional,&cm_numer,&cm_denom);	
	sfrac_simplify(fractional);
}
char * sfrac_sub(char * n1, char * n2){
	int numer1,denom1,numer2,denom2;
	int cm_numer,cm_denom;
	char fractional[100];
	convert_toint(n1,&numer1,&denom1);
	convert_toint(n2,&numer2,&denom2);
	if(denom1!=denom2){
		cm_numer=numer1*denom2-numer2*denom1;
		cm_denom=denom1*denom2;
	}
	else{
		cm_numer=numer1-numer2;
		cm_denom=denom1;
	}
	convert_tochar(fractional,&cm_numer,&cm_denom);	
	sfrac_simplify(fractional);
}

char * sfrac_mult(char * n1, char * n2){
	
	int numer1,denom1,numer2,denom2;
	int cm_numer,cm_denom;
	char fractional[100];
	
	convert_toint(n1,&numer1,&denom1);
	convert_toint(n2,&numer2,&denom2);
	cm_numer=numer1*numer2;
	cm_denom=denom1*denom2;
	convert_tochar(fractional,&cm_numer,&cm_denom);	
	sfrac_simplify(fractional);

}

char * sfrac_div(char * n1, char * n2){

    int numer1,denom1,numer2,denom2;
	int cm_numer,cm_denom;
	char fractional[100];
	
	convert_toint(n1,&numer1,&denom1);
	convert_toint(n2,&numer2,&denom2);  
	
	cm_numer=numer1*denom2;
	cm_denom=numer2*denom1;
	if(cm_denom<0){
	    cm_denom*=(-1);
	    cm_numer*=(-1);	
	}
	
   	convert_tochar(fractional,&cm_numer,&cm_denom);		  
	sfrac_simplify(fractional);
}
void sfrac_print(char *a1,char *n1,char *a2,char *n2,char *a3,char *n3,char *a4){

    int i;
    int numer1,denom1,numer2,denom2,numer3,denom3;
    int size_den1,size_den2,size_den3; 
    int size_numr1,size_numr2,size_numr3;   
    /* variables for print */
    int first,dif1,dif2,dif3;
          
    first=strlen(a1);
    convert_toint(n1,&numer1,&denom1);
   	convert_toint(n2,&numer2,&denom2);  
   	convert_toint(n3,&numer3,&denom3); 
   	
    size_numr1=num_size(numer1);
    size_numr2=num_size(numer2);
    size_numr3=num_size(numer3);
           	
    size_den1=num_size(denom1);
    size_den2=num_size(denom2);
    size_den3=num_size(denom3);
    
    dif1= size_den1 - size_numr1;
    dif2= size_den2 - size_numr2; 
    dif3= size_den3 - size_numr3;
       
   /* if(n2[0]=='0' && a2[0]=='0' && a3[0]=='0' && n3[0]=='0' && a4[0]=='0'){
    
    }
    else	*/   	
   	
    /* Line1... */  
    for(i=0; i<first; ++i)
    	printf(" ");
    	
    for(i=0; i<dif1; ++i)	
    	printf(" ");	     	
    printf("%d",numer1);
    	
    printf("   ");	 
   
    for(i=0; i<dif2; ++i)	    
        printf(" ");
    printf("%d",numer2);
    for(i=0; i<strlen(a3); ++i)
        printf(" ");          
    
    for(i=0; i<dif3; ++i)	    
        printf(" ");
    printf("%d",numer3); 

    printf("\n"); 
    /* Line2... */      
    printf("%s",a1);  
    printf(" ");
    if(dif1>0){
		for(i=0; i<size_den1; ++i)	    
		    printf("-");
    }
    else{
		for(i=0; i<size_numr1; ++i)	    
				printf("-"); 
    }  
      
    printf("%s",a2);

    if(dif2>0){
		for(i=0; i<size_den2; ++i)	    
		    printf("-");
    }
    else{
		for(i=0; i<size_numr2; ++i)	    
				printf("-"); 
    }  
       
    printf("%s",a3);            	 

    if(dif3>0){
		for(i=0; i<size_den3; ++i)	    
		    printf("-");
    }
    else{
		for(i=0; i<size_numr3; ++i)	    
				printf("-"); 
    }   
    printf("%s",a4);
    printf("\n"); 
         
    /* Line3... */  
              
    for(i=0; i<first; ++i)
    	printf(" ");
    if(dif1>0)
    	printf("%d",denom1);
    else{
		for(i=0; i<((-1)*dif1); ++i)	
			printf(" ");	     	
		printf("%d",denom1); 
    }
    	
    for(i=0; i<strlen(a2); ++i)    	
    	printf(" ");
	if(dif2>0)
    	printf("%d",denom2);
    else{
		for(i=0; i<((-1)*dif2); ++i)	
			printf(" ");	     	
		printf("%d",denom2); 
    }
    
	for(i=0; i<strlen(a3); ++i)    	
    	printf(" ");    
    	
	if(dif3>0)
    	printf("%d",denom3);
    else{
		for(i=0; i<((-1)*dif3); ++i)	
			printf(" ");	     	
		printf("%d",denom3); 
    }

    printf("\n\n");      	                                  	  
}












