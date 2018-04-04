#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define line_len 80

void file_read(FILE *ptr);
void print_token_file(FILE *ptr);

int main(){
	
	FILE *p;
	
	p=fopen("token.txt","r");  
	if(p=='\0')
		printf("Cannot open the file!");
	file_read(p);
	fclose(p);
	
	p=fopen("token.txt","r");  
	if(p=='\0')
		printf("Cannot open the file!");
	
	print_token_file(p);
	fclose(p);			  	

    return 0;
}

void file_read(FILE *ptr){

	int valid=0;
	int ret=1;
	int i=0,k=1;
	char line[1000];
	int nerd;
	printf("\n\n");						

	for(i=0; ret != EOF ; ++i){		
		ret=fscanf(ptr,"%c",&line[i]);
		nerd=ftell(ptr);	
		if(line[i]=='\n')
			++k;
			
		if(line[i]=='='){
			valid=1;

			nerd+=1;
			fseek(ptr,nerd,SEEK_SET);
			ret=fscanf(ptr,"%c",&line[i]);	
			if(isdigit(line[i])==0)	 
   				printf("Error at line number %d\n",k);	
		 
			nerd-=2;
			fseek(ptr,nerd,SEEK_SET);	
			fscanf(ptr,"%c",&line[i]);
		}	
			
		if(isdigit(line[i])){
			nerd-=3;	
			fseek(ptr,nerd,SEEK_SET);
			ret=fscanf(ptr,"%c",&line[i]);
						
			if(line[i]!='=')
   			    printf("Error at line number %d\n",k);

			nerd+=3;
			fseek(ptr,nerd,SEEK_SET);		   						
		}				
	}
}

void print_token_file(FILE *ptr){
    char *ret;
	char line[line_len];
	int size,i,k,s,c,different_size;
	printf("\n\n");
				
	for(i=0; i<80; ++i)
		printf("_");
		
	printf("\n");
	printf("|");
	printf("  #  ");
	printf("|");
	printf("                   token                   ");		
	printf("|");
	printf("           Frequency        ");	
	printf("|");
	printf("\n");
	k=0;		
	for(i=0; i<80; ++i)
		printf("_");
	printf("\n");
	for(ret=fgets(line,line_len,ptr);
		ret!=0;
		ret=fgets(line,line_len,ptr)){

		if(line[strlen(line)-1]=='\n'){
			line[strlen(line)-1]='\0';
			++k;
			size=strlen(line);
		}
		for(i=0;i<size;++i){				
			if(line[i]=='='){											
				if(isdigit(line[i+2])){					
					printf("|");
					printf("%5d",k);
					printf("|");
					for(s=0, c=1;line[s]!='=';++s,++c)
						printf("%c",line[s]);
						different_size=44-c;    /* 44 weight of tokens line in table */
					for(s=0; s<different_size;++s)
						printf(" ");						
					printf("|");
					printf("%28c",line[i+2]);
					printf("|");
					printf("\n");
					
				}				
			}
		}				
	}
	for(i=0; i<80; ++i)
		printf("_");
	printf("\n\n");						
	
}

