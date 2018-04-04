#include<stdio.h>

/* define consist max column */
#define Max_N 6		
													
/*Functions prototypes */
int find(char Puzzle[][Max_N],int row,int column,char orientation,char *word);
int find_size(char word[7]);

int main(){
	int r,c;
	char direction,choice;
	
	/* String decleration that word */
	char wrd[7];         
	    
	/* array decleration for puzzle table */                                       
    char word[][Max_N]={{'A','B','R','A','I','N'}, 
                        {'O','D','A','R','H','L'},
                        {'W','E','Y','K','S','J'},
                        {'A','Y','S','E','Y','C'},
                        {'X','E','U','Y','O','F'},
                        {'Q','P','B','I','S','R'}}; 
    /* Do-while loop */      
    do{    
		printf("Enter your guess?\n");   
		/* get a guess */             
		scanf("%s",wrd);
		
		printf("'r' or 'R' for right-to-left\n"); 
		printf("'l' or 'L' for left-to-right\n"); 
		printf("'t' or 'T' for top-to-bottom\n");
		printf("'b' or 'B' for bottom-to-top\n"); 
		printf("Direction => ");   
		/* get the orientation */            
		scanf(" %c",&direction);
		printf("Enter a location => ");
		/* get the location */            						     
		scanf("%d %d",&r,&c);
		
		/* Information about found or not */
		if(1==find(word,r,c,direction,wrd))
	    	printf("\nIt's founded...\n\n");
	    else
	        printf("\nIt's not found...\n\n");
	        	
		printf("Enter Y to continue or N to quit =>\n");
		scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');

	return 0;

}

int find_size(char word[7]){
	int i=0;
	while(word[i]!='\0'){
		i++;
	}
	return i;	
}

    /* The function find definition */
int find(char Puzzle[][Max_N],int row,int column,char orientation,char *word){
	/* Control flag */
	int i,j,size,found=1;
	
	/* calculate the size */
	size=find_size(word);
    /* to choose the direction */
	switch(orientation){
	    /* It controls just on row */
		case'r':	
		case'R':for(i=column, j=0; i<column+size, j<size; i++, j++){
					if(Puzzle[row][i]!=word[j])
						found=0;	
				}
				break;
		/*control the row from  left to right */
		case'l':	
		case'L':for(i=column, j=0; i>column-size, j<size; i--, j++){

					if(Puzzle[row][i]!=word[j])
						found=0;	
				}
				break;	
		/* It controls just on columns; from top to down */	
		case't':
		case'T':for(i=row, j=0; i<row+size, j<size; i++, j++){	
					if(Puzzle[i][column]!=word[j])
						found=0;	
				}
				break;		
			
		case'b':	
		case'B':for(i=row, j=0; i>row-size, j<size; i--, j++){	
					if(Puzzle[i][column]!=word[j])
						found=0;	
				}
				break;	
		/* when entered except that R,L,T,B a character */
		default:printf("INCORRECT ENTRY!\n");
		        break;					
	}
	return found;
}


