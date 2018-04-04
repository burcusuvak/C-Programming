/*  Burcu SUVAK OZTURK                                        */
/*  141044079                                                 */

#include<stdio.h>
/* Function prototype */
int F(int x,int y);

int main(){
    int x,y;
    printf("Please enter two values that is greater than zero for F function\n>>");
    scanf("%d\n%d",&x,&y);
	printf("\nResult is %d.\n",F(x,y));
	
    return 0;
}
/* Function declaration */
int F(int x,int y){
    
    int ans;
    /* Base case */
    if( x<=0 || y<=0 )
        ans=0;
    else 
    	ans=F(x-1,y)+ F(x,y-1)+ x + y;
	return ans;
	
}
