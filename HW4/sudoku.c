#include<stdio.h>

/* Function prototypes */
void init(int S[][9]);
int is_legal(int S[][9],int r,int c,int x);
void place(int S[][9],int r,int c,int x,int *count);
void read_from_file(FILE *file_pointer,int S[][9]);
void write_to_file(FILE *file_pointer,int S[][9]);

int main(){
	FILE *fptr, *wptr;
	int i,j;
	/* Array declaration */
	int s_D[9][9];
	
	/* Call the functions */
	init(s_D);
	read_from_file(fptr,s_D);
	write_to_file(wptr,s_D);
	
	return 0;      
}
/* Function init to initialize the array */
void init(int S[][9]){

	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			S[i][j]=0;
		}
	}
}
/* specification that right location or not*/
int is_legal(int S[][9],int r,int c,int x){
	int i,j,row,col;
	row=r/3;
	col=c/3;
	/* invalid values */
	if(r<0 || r>8 || c<0 || c>8) return 0;
	
	if(x<0 || x>9) return 0;
	if(x==0) return 1;
	
	/* controlling rows */	
	for(i=0;i<9;i++){
		if(S[r][c]!=0 || S[r][i]==x)	
			return 0;		
	}
	
	/* controlling columns */
	for(i=0;i<9;i++){
		if(S[r][c]!=0 || S[i][c]==x)
			return 0;		
	}	
	
	/* controlling 3*3 blogs */
	for(i=3*row; i<3*row+3; i++){
		for(j=3*col; j<3*col+3; j++){
			if(S[r][c]!=0 || S[r][c]==x)
				return 0;
		}
	}
		
	return 1;
}
void place(int S[][9],int r,int c,int x,int *count){
	int legal;
	int i,j;

	legal=is_legal(S,r,c,x);
	
	if(legal==1){
		S[r][c]=x;
		(*count)++;
	}	
						
}
/* get values from the file and check wrong or correct  */
void read_from_file(FILE *file_pointer,int S[][9]){
	int x,i,j;
	int ptr=0;
	
	file_pointer=fopen("sudoku.txt","r");
	
	/* When cannot open file */
	if(file_pointer==NULL)
		printf("Cannot open the file!\n");
		
	x=0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			fscanf(file_pointer,"%d",&x);
			place(S,i,j,x,&ptr);
		}
	}
	printf("\n\n");
	if(ptr==81){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				printf("%d ",S[i][j]);
			}
			printf("\n");
		}		
	}

	else
		printf("\nThis sudoku is wrong !\n\n");

	printf("\n");		
	fclose(file_pointer);	
}
/* Howsoever write sudoku table values to file */
void write_to_file(FILE *file_pointer,int S[][9]){
	
	int i,j;
	
	/* Open the file to write */
	file_pointer=fopen("write_su.txt","w+");
	
	if(file_pointer==NULL)
		printf("Cannot open the file!\n");
		
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			fprintf(file_pointer,"%d ",S[i][j]);
		}
	}
	/* Closing the fie */
	fclose(file_pointer);	

}


