#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "converter.h"

int main(int argc, char **argv){
    
    int i; /*loop */
    int j;
    int belen;
	int validNum;
	/*check argument 1*/
	
	int re1, re2;

    /*check argument 2*/

	int ra21, ra22, ra23;

	
	/*SM, E, 1*/
	int argument2;

	char number[17]={0};
	

	int length;
	length=argc;
	if (length>11 || length<4){
	
		return EXIT_FAILURE;
	}


    else{
    
    re1 =strcmp(argv[1], "BE");
    re2 =strcmp(argv[1], "LE");
    
    
    /*BE*/
    if(re1==0){
        ra21=strcmp(argv[2], "1");
        ra22=strcmp(argv[2], "SM");
        ra23=strcmp(argv[2], "E");
        
        if(ra21==0 || ra22==0 || ra23==0){
        
        	 if(ra21==0){
            	argument2=1;
            }
            else if(ra22==0){
            	argument2=2;
            }
            else {
            	argument2=3;
            }

        for(i=3;i<argc;i++){
      
        	   if(strlen(argv[i])>2){
        	   	return EXIT_FAILURE;
        	   }
       

              if(strlen(argv[i]) == 1) {
            		char buff[3] = {0};
            		strcat(buff, "0");
            		strcat(buff, argv[i]);
            		strcat(number, buff);
            	} 
            	else {
            		strcat(number, argv[i]);
            	}
        }

     belen = strlen(number);

        for (j=belen; j<16;j++){
        	strcat(number, "0");
             }
           
         
          validNum = is_valid(number);
          
         if(validNum==1){
            
            return EXIT_FAILURE;
         }
         else{
         hex_convert (number, argument2);
             return EXIT_SUCCESS;
           }
         

        }
        else{
        	
        	 return EXIT_FAILURE;
        }

        }

    













    /*LE*/
    else if(re2==0)
    {  

        ra21=strcmp(argv[2], "1");
        ra22=strcmp(argv[2], "SM");
        ra23=strcmp(argv[2], "E");
        
        if(ra21==0 || ra22==0 || ra23==0){

            if(ra21==0){
            	argument2=1;
            }
            else if(ra22==0){
            	argument2=2;
            }
            else {
            	argument2=3;
            }


        	/*go to converter for loop to loop through*/
        
        	for(i=argc-1;i>2;i--){
               
            	if(strlen(argv[i]) == 1) {
            		char buff[3] = {0};
            		strcat(buff, "0");
            		strcat(buff, argv[i]);
            		strcat(number, buff);
            	} else {
            		strcat(number, argv[i]);
            	}
        	}
        	
        	validNum = is_valid(number);
          
         if(validNum==1){
            
            return EXIT_FAILURE;
         }
         else{
         hex_convert (number, argument2);
             return EXIT_SUCCESS;
           }

        }
        else {
        	return EXIT_FAILURE;
             }
        	
    }
    else {
    	    return EXIT_FAILURE;
            
    }


	}
	if(validNum==1){
    return EXIT_FAILURE;

	}

       
	return EXIT_SUCCESS;
}