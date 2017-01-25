/**
 *    Author: Emanuel Gitterle
 *    Date: Monday the  23. Jan 2017
 *
 *    This is a satsolver i programm in my freetime. I started programming this at the Date above and i guess it will never get finished perfektly ;).
 *
 */ 


#include <stdio.h>
#include <stdlib.h>

#include "dpll.h"
#include "interface.h"
#include "dlist.h"

int main(int argc, char** argv){
    
    /**
     *    Inform user about the program if no argument is given
     */
    if(argc < 2)
	print_instruction();
   
   /**
    *    Open DIMACS file
    */ 
   FILE *file = fopen(argv[1], "r");

   if(file == NULL){
       printf("Error: File not found\n");
       printf("Exiting now...\n");
       exit(EXIT_FAILURE);
   }

/*	for debugging,    visualises the input file
   char c;
   if(file){
       while((c = getc(file)) != EOF)
	   putchar(c);
   }
*/


/*
 * START dlist TEST
 */
dlist* list = create_dlist();

int a[] = {1,  2, 3};
int b[] = {-2, 3, 0};
int c[] = {-1, -3, 0};
prepend(list, a);
prepend(list, b);
prepend(list, c);

print_dlist(list); 

/*
 * END dlist TEST
 */ 

    fclose(file);
    exit(EXIT_SUCCESS);
}
