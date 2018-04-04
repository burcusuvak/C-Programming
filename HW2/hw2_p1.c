#include<stdio.h>

void Draw_Rectangle(int str_p, int length, int width, int lyr);				/* function prototypes */
void Draw_Triangle(int sp,int length,int lyr);
void Draw_Circle(int center,int radious,int lyr);

int main(){
	
	int st_point,length,width,lyr,cent,rad;
	int shape_no;
	
	printf("please enter any shape to draw\n");								/* information for user */
	printf("rectangle :1\ntriangle :2\ncircle:3\n");	
	scanf("%d",&shape_no);													  /* get the shape	   */
		
	switch(shape_no){
	
		case 1: printf("enter for rectangle a starting point, length, width and \nlayer(1 or 2) sequentially\n");
				scanf("%d %d %d %d",&st_point,&length,&width,&lyr);/* get the values for rectangle  */
				Draw_Rectangle(st_point,length,width,lyr);      /* call the Draw_Rectangle function */
				break;
		
		case 2: printf("enter for triangle a starting point, length and \nlayer(1 or 2) sequentially\n");
				scanf("%d %d %d",&st_point,&length,&lyr);			/* get the values for triangle  */
				Draw_Triangle(st_point,length,lyr);		         /* call the Draw_Triangle function */
				break;
			
		case 3:
				scanf("%d %d %d",&cent,&rad,&lyr);			/* get the values for circle  */
				Draw_Circle(cent,rad,lyr);		
		
		
			break;	
	}

	return 0;

}
void Draw_Rectangle(int str_p, int length, int width, int lyr)
{
	int ih;
	int i,k;
	
	for(ih=1; ih<=length*lyr; ih++)
	{	for(i=1; i<=str_p; i++)
		{
			printf(" ");
		}
		if(ih>lyr && ih<=((length*lyr)-lyr))
		{	for(k=1; k<=lyr; k++)
			{
				printf("*");
			}
			for(k=1; k<=(lyr*width-2*lyr); k++)
			{
				printf(" ");
			}		
			for(k=1; k<=lyr; k++)
			{
				printf("*");	
			}
		}	
		else
		{	for(i=1; i<=width*lyr; i++)
			{	
				printf("*");
			}		
		}
		printf("\n");
	}
}

void Draw_Triangle(int sp,int length,int lyr){
	
	int ih;                                                     	    /* ih is number of line. */
	int k, m, mid_point, last_line, l, n, p;
	mid_point=(length*lyr-1);
	last_line=(length*lyr*2)-1;
	m=0, n=0, l=0, p=0;                             					  /* variables for loops  */

	for(ih=1; ih<=length*lyr; ih++, m++, n++)
	{	for(k=1; k<=(sp+mid_point)-m; k++)
		{
			printf(" ");
		}
		if(ih<=lyr)
		{	for(k=1; k<=2*n+1; k++)
			{
				printf("*");
			}		
		}
		else if(ih>length*lyr-lyr)
		{	for(k=1; k<= (last_line - (2*(lyr-1)) + (2*l) ); k++)
			{
				printf("*");
			}
			l++;
			
		}
		else
		{	for(k=1; k<=lyr; k++)
			{
				printf("*");
			}
			for(k=1; k<=2*p+1; k++)
			{
				printf(" ");
			}
			for(k=1; k<=lyr; k++)
			{
				printf("*");			
			}
			p++;
		}
		printf("\n");			
	}
}

void Draw_Circle(int center,int radious,int lyr)
{
	int ih,k;
	
	
	for(ih=1; ih<=(radious*2+1); ih++){
		if(ih==1 || ih==radious*2+1){
			for(k=1;k<=center;k++){
				printf(" ");
			}
			for(k=1;k<=lyr;k++){
			printf("*");
			}		
			printf("\n");		
		}
			       
		if(ih==2||ih==radious*2){
			for(k=1;k<=center-3;k++){
				printf(" ");
			}
			for(k=1;k<=lyr;k++){
			printf("*");
			}	
			for(k=1;k<=radious+1;k++){
				printf(" ");
			}
			for(k=1;k<=lyr;k++){
			printf("*");
			}
			printf("\n");
		}	
		printf("\n");
		
		if(ih==3||ih==radious*2-1){
		
			for(k=1;k<=center-5;k++){
					printf(" ");
				}
			for(k=1;k<=lyr;k++){
				printf("*");
			}
			for(k=1;k<=radious+3;k++){
				printf(" ");
			}
			for(k=1;k<=lyr;k++){
				printf("*");
			}
			printf("\n");		
		
		}
		
		if(ih==radious+1){
			for(k=1;k<=center-radious;k++){
				printf(" ");
			}
			for(k=1;k<=lyr;k++){
				printf("*");
			}	
			for(k=1;k<=radious*2-1;k++){
				printf(" ");
			}
			for(k=1;k<=lyr;k++){
				printf("*");
			}
			printf("\n");	
		
		}

		printf("\n");	
				
	}
}

