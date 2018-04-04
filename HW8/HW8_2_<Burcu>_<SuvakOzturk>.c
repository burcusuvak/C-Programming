/*  Burcu SUVAK OZTURK                                        */
/*  141044079                                                 */
/*  I show solution path with 1's and each other element 0.   */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define row 10
#define col 10
#define N 10

int is_valid(int** str,int i,int j);
int solve_maze(int** str,int i,int j,int solve[N][N]);
void print(int key[N][N]);
int maze(int** str);

int main(){

    int i,j;
    int **arr;
    
    FILE *p;
    p=fopen("maze.txt","r");
    if(p=='\0')
        printf("Cannot open the file");
        
    /* Dynamic Memory Allocation */    
    arr=malloc(row * sizeof(int*));
    for(i=0; i<row; ++i)
        arr[i]=malloc(col * sizeof(int));
    
    for(i=0;i<N;++i){ 
		for(j=0;j<N;++j){
    		fscanf(p,"%d",&arr[i][j]);
    		printf("%d ",arr[i][j]);
    	}	
   	    printf("\n");        
    }    	        
          
	maze(arr);
    
    for(i=0; i<col; ++i) 
        free(arr[i]);
        
    free(arr);                
    
    fclose(p);

    return 0;
}
int is_valid(int** str,int i,int j){

	if(i>=0 && j>=0 && i<N && j<N && str[i][j]==1)
		return 1;
	else
		return 0;			
}
int solve_maze(int** str,int i,int j,int solve[N][N]){
	if(i==N-1 && j==N-1){
		solve[i][j]=1;
		return 1;
	}	
	if(is_valid(str,i,j)==1){
    	solve[i][j]=1;

		if(solve_maze(str,i+1,j,solve)==1)
			return 1;
        if(solve_maze(str,i,j+1,solve)==1)
			return 1;	
	    if(solve_maze(str,i-1,j,solve)==1)
			return 1;
		if(solve_maze(str,i,j-1,solve)==1)
			return 1;

		solve[i][j]=0;
		return 0;
	}
	return 0;	
}
void print(int key[N][N]){

    int i,j;
    printf("\n\n** SOLVING MAZE **\n\n");
    for(i=0;i<N;++i){
        for(j=0;j<N;++j){     
            printf("%d ",key[i][j]);
            if(j%10==9)
                printf("\n");
        }        
    } 

}
int maze(int** str){
    int key[N][N]={0};
	
    if(!solve_maze(str,0,0,key)){
        printf("maze: %d\n",solve_maze(str,0,0,key));
        return 0;
    }    
    print(key);   
    return 1;
}






