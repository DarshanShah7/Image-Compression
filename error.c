#ifndef ERROR_C_INCLUDED
#define ERROR_C_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include"error.h"

void error_handler(int error_type)
{
        if( error_type == 0)
        {
            printf("Invalid command found\n");
            printf("Try --help for more information");
            exit(1);

        }
        else if( error_type == 1)
        {
            printf("This file type is not compatible\n");
            printf("Try --help for more information");
            exit(1);
        }
        else if( error_type == 2)
        {
            printf("Error while opening the file\n");
            printf("Try --help for more information");
            exit(1);
        }
}

#endif // ERROR_C_INCLUDED
