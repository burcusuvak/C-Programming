/* I did not Table formatting  and commands in terms of */
/* my time is over and it is difficult and time consuming*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define line_len 15
#define max 100

int emails_file_read(FILE *ptr);

int main(){
	
	FILE *p;
		
	p=fopen("emails.txt","r");  
	if(p=='\0')
		printf("Cannot open the file!");
	emails_file_read(p);
	
	fclose(p);
	return 0;
}

int emails_file_read(FILE *ptr){

    char *line[1000];
    int ret=1,tg_1=-1,tg_2=-1,tg_3=-1,tg_4=-1,k;
	int i=0,position, find=0,count;
	
	char tag1[30]="<Subject>";
	char tag2[30]="</Subject>";
	char tag3[30]="<Body>";
	char tag4[30]="</Body>";
	
	printf("\n\n");
	for(i=0;i<1000;++i)
		line[i]=(char*)malloc(15*sizeof(char));
	
    i=0;
	for(ret=fscanf(ptr,"%s",line[i]);
		ret!=EOF;
		ret=fscanf(ptr,"%s",line[i]))	
    {	
    	if(strcmp(line[i],tag1)==0){
            find=1;
            tg_1=i;
        }
        
        if(strcmp(line[i],tag2)==0){
            find=1;
            tg_2=i;
        } 
        
        if(strcmp(line[i],tag3)==0){
            find=1;
            tg_3=i;

        } 
        
        if(strcmp(line[i],tag4)==0){
            find=1;
            tg_4=i;
        } 
     
       	++i;
    }

  	printf("\n\n");
 	printf(" *** Emails.txt TABLE ***\n");
	printf("\n");
 	for(i=0; i<80; ++i)
		printf("_");
		
	printf("\n");
	printf("|");
	printf("  #  ");
	printf("|");
	printf("                   emails                  ");		
	printf("|");
	printf("           Frequency        ");	
	printf("|");
	printf("\n");
	k=0;		
	for(i=0; i<80; ++i)
		printf("_");
		printf("\n");  
	
		printf("|"); 
		printf("%5d",k);
		printf("|");
	if(tg_1!=-1 && tg_2!=-1){
		for(i=tg_1+1; i<=tg_2-1; ++i){
			printf("%s ",line[i]);			
		}
	}	
		printf("                  ");
		printf("|");
	if(tg_3!=-1 && tg_4!=-1){
		for(count=1, i=tg_3+1; i<=tg_4-1, count<5; ++count, ++i){
				printf("%s ",line[i]);			
			}
		
	}
	printf(".......");
	printf("|");
	printf("\n");  
	for(i=0; i<80; ++i)
		printf("_");
	printf("\n\n");  	 
    
}	






