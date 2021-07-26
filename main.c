#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>

#include"image_compression.h"

#include"error.h"


void print_help();


int main(int argc, char ** argv)
{

    if(argc == 1)
    {
        error_handler(ERR_INVALID_COMMAND);

    }
    else if(argc == 2)
    {

        if( strcmp(argv[1], "--help") == 0 ){


            print_help();

            return 0;
        }
        else
        {
           error_handler(ERR_INVALID_COMMAND);

        }
    }
    else if(argc == 6)
    {

           char* input_name = NULL;

           char* output_name = NULL;

           int c_flag = 0;

           int d_flag = 0;

           int o_flag = 0;

           int i_flag = 0;

           int opt;
           //':' before c will help to return : for missing argument instead of ?

           while ((opt = getopt(argc, argv, ":cdi:o:")) != -1) {
               switch (opt) {
               case 'c':
                      c_flag = 1;
                      break;

               case 'd':
                        d_flag = 1;
                        break;

                case 'i':
                        input_name = optarg;
                        i_flag = 1;
                        break;

               case 'o' :
                        output_name = optarg;
                        o_flag = 1;
                        break;

               case ':' :
                         error_handler(ERR_INVALID_COMMAND);
                        break;
               default  :
                        error_handler(ERR_INVALID_COMMAND);
                        break;

               }

           }


           //only c or d  flag must be present and o flg  and i flag must be present
           if(((c_flag == 0 && d_flag == 1)|| (d_flag == 0 && c_flag == 1)) && o_flag == 1 && i_flag == 1){
                if(c_flag == 1)
                {

                        image_compression(input_name, output_name);


                }
                else if(d_flag == 1)
                {

                        image_decompression(input_name,output_name);


                }


           }

    }
    else
    {
        error_handler(ERR_INVALID_COMMAND);
    }


    return 0;
}



void print_help(){

    printf("This program compress and decompress grayscale bmp images\n");
    printf("Usage: ./IMAGE_COMPRESSION.exe [-cd][-i][input file name][-o][output file name]\n");
    printf("-c : Compress \n");
    printf("-d : Decompress\n");



}
