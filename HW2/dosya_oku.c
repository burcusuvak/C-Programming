/* Read the values from the file and find the min.polynom and max. polynom */

#include<stdio.h>
#include<math.h>
int main(){

	FILE *inp;
	int a,b,i,temp,x,nerd,f=0;
	int ret;
	int fmin=pow(10,9),fmax=0;

	inp=fopen("polynomial.txt","r");
	nerd=ftell(inp);
	ret=fscanf(inp,"%d",&a);
    
    while(ret!=EOF){    
		temp=a;

		for(i=0; i<temp+2; i++){
			ret=fscanf(inp,"%d",&b);
		}
		x=b;
		fseek(inp,nerd,SEEK_SET);	

		ret=fscanf(inp,"%d",&a);
		temp=a;
		for(i=0; i<temp+2; i++,a--){
			ret=fscanf(inp,"%d",&b);
			f+=(b*pow(x,a));
		}
		f=f-1;
		
		if(fmin>f) fmin=f;
		
		nerd=ftell(inp);	
		ret=fscanf(inp,"%d",&a);

		if(f>fmax) fmax=f;

		f=0;
		
	}
	printf("fmin: %d\nfmax :%d\n",fmin,fmax);
	
	return 0;

}


