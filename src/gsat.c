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

    /*
     *    Create doubly linked list to store tupl from file
     */ 
    dlist *list = create_dlist();

    /*
     *    Read file
     */ 
    char c:
    char *tupl;
    while((c=getc(file) != EOF){
        //code
    }

    fclose(file);
    exit(EXIT_SUCCESS);
}
