#include "converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
char* ptr=NULL;
int k=0;
 uint64_t hex;
 uint64_t final;
 
uint64_t fvalue;

/*
*Converts a hex sting to a number
*
*/

 int hex_convert (const char* value, int a ){
    

 	hex=  (uint64_t )strtoull(value, &ptr, 16);
 	
     
    if(hex==0){

    	
       return EXIT_FAILURE;
   
    }
    /*LE*/
    
         if(a==1 && hex<0){

           
       final= hex-1;
       printf("%016"PRIu64"\n", final);
        
    }
    /* SM */
    else if(a==2 && hex<0){
    	 
    	final=hex-1;
    	
    	final=~final;
    	
    	final=0x8000|final;
    	
    	printf("%016"PRIx64"\n", final);
       
    }
    /*  E  */
    else if (a==3){
         final=hex-1023;
  
         printf("%016"PRIx64"\n", final);
         
    }

   


 	else {
 		
 		
 		printf("%016"PRIx64"\n", hex);
 	   
 	}

    




    
    
  
 	
return 0;
     


 }


/*
*Checks a string of hex num for invalid char
*
*/
int is_valid (const char* value){
  

	
	int numlen=strlen(value);
	
     while(k<numlen){
     	char num = value[k];
     	if(num=='1'||num=='2'||num=='3'||num=='4'||num=='5'||num=='6'||num=='7'||num=='8'||num=='9'||num=='0'||num=='a'||num=='A'||num=='b'||num=='B'||num=='c'||num=='C'||num=='d'||num=='D'||num=='e'||num=='E'||num=='f'||num=='F')
     {
     	     	k++;
     }
     else{

     return EXIT_FAILURE;}
     }
      return 0;
       /*if(b!=0){
       	return 1;
       }
       
       	return 0;
       */

       
   }