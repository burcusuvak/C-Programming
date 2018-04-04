/* It is difficult that working original files because it is very big.					*/
/* Thus, I send my files that I am working and I didn't delete my debugs line in terms  */
/* of it's more clear in this way...         											*/
/* My program is working even it is not perfect											*/
/* I send two programs that the old  one check errors but the new one don't.			*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int emails_file_read(FILE *ptr_e, FILE *ptr_t);

int main(){
	
	FILE *email_ptr, *token_ptr;
		
	email_ptr=fopen("email.txt","r");  
	if(email_ptr=='\0')
		printf("Cannot open the file!");
	token_ptr=fopen("token.txt","r");  
	if(token_ptr=='\0')
		printf("Cannot open the file!");	
	emails_file_read(email_ptr,token_ptr);
	
	fclose(email_ptr);
	fclose(token_ptr);
	return 0;
}
int emails_file_read(FILE *ptr_e, FILE *ptr_t){

    char *line[1000];
    char *line_token[50];
    int arr[50];
    int f[50]={0};
    
    int ret=1,tg_1=-1,tg_2=-1,tg_3=-1,tg_4=-1,tg_5=-1, tg_6=-1;
	int i, find=0,email=0,component_email=0,count=0,count2=0;
	int subject=0, component_subject=0, body=0, component_body=0;
	int count_line=0;
	
	int k,s,t,j,m,x,h, differ, dif, c=0, found=0;
	
	char tag5[30]="<email>";
	char tag6[30]="</email>";
	char tag1[30]="<subject>";
	char tag2[30]="</subject>";
	char tag3[30]="<body>";
	char tag4[30]="</body>";
	
	printf("\n\n");
	for(i=0;i<1000;++i)
		line[i]=(char*)malloc(30*sizeof(char));
	
	for(i=0;i<50;++i)
		line_token[i]=(char*)malloc(30*sizeof(char));
	/**/	
	i=0;
	t=0;
	arr[0]=-2;
	k=1;
	for(ret=fscanf(ptr_t,"%s",line_token[i]);
		ret!=EOF;
		ret=fscanf(ptr_t,"%s",line_token[i]))	
    {	
    	if(strcmp(line_token[i],"=")==0){
    		arr[k]=i;
			printf("arr%d: %d \n",k,arr[k]);
    		++t;
   			++k;
   		}	
    	++i; 
	}	
	/**/	
	i=0;
    ret=1;
	for(ret=fscanf(ptr_e,"%s",line[i]);
		ret!=EOF;
		ret=fscanf(ptr_e,"%s",line[i]))	
    {  	
    	
		if(strcmp(line[i],tag5)==0){
			++email;
			tg_5=i;
        }
        if(strcmp(line[i],tag6)==0){
			++component_email;
            tg_6=i;
        } 
        if(strcmp(line[i],tag1)==0){
        	++subject;
			tg_1=i;
        }           
        if(strcmp(line[i],tag2)==0){
        	++component_subject;
            tg_2=i;
        }             
        if(strcmp(line[i],tag3)==0){
           	++body;
            tg_3=i;
        } 
        if(strcmp(line[i],tag4)==0){
        	++component_body;
            tg_4=i;
        }
		for(h=1; h<10; ++h){
		   	if((component_email==h && email==h)&&(component_body==h && body==h)&&
		   	(component_subject==h && subject==h)){
		   		found=0;
				/* x is count of '='*/
				for(x=1, k=0; x<=t; ++x, ++k){
					/* to calculate weight of word between every equal character  */
					dif=0;
			   		differ=0;

					differ=arr[k+1]-arr[k]-2;  
		
					for(j=arr[k]+2; j<arr[k+1]; ++j){
						for(s=tg_5+1; s<tg_6-1; ++s){
							if(strcmp(line[s],line_token[j])==0){
								for(c=s; c<s+differ; ++c){
									if(strcmp(line[c],line_token[j])==0){
										++dif;	
									}											
								}																							
							}
							if(differ==dif)
								f[x]=1;
						}
						printf("line:%s   linetok:%s \n",line[s],line_token[j]);		
					}	
					if(dif>differ){
						dif/=differ;
						f[x]=dif;
					}					
					if(differ!=dif)
						f[x]=0;				
					/* convert from pointer to int */
					printf("count:%d  arr: %d\n",f[x],(int)line_token[arr[x]+1][0] - 48);
					if( f[x] >= (int)line_token[arr[x]+1][0] - 48 ){
						printf("there is...\n\n");
						++found;										 						}			
				}
				printf("found:%d  x:%d\n",found,t);
				if(found==t)	
					printf("\nThe %d. email is a spam!\n\n",h);
				else
					printf("\nThe %d. email is not a spam!\n\n",h);
      	
	    	}
		}		
      	++i;
	}


   	return 0;	
}   	
