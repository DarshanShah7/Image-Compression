#ifndef IMAGE_COMPRESSION_H_INCLUDED
#define IMAGE_COMPRESSION_H_INCLUDED

#define DCT_SIZE 8

#define pi 3.142857

extern long int input_file_size;
extern long int output_file_size;


//This is the main function
void image_compression(char * input_filename, char * output_file_name);

void read_BMP(char *filename, int ** MATRIX);

void print_compression();


void write_the_matrix_into_file(int **MATRIX, int matrix_height ,int matrix_width);

void get_image_name(char *final_name , char *initial_name);

long int get_file_size(char * file_name);


void print_decompression();


void get_number(int number , int * size, int arr[]);

//This gives the matrix pointer after dynamic allocation
int** get_matrix_int(int height  , int widht );

float ** get_matrix_float(int height, int width);




//applies DCT and quantization on the matrix
void forward_DCT(int  **MATRIX, int x_limit, int y_limit,int flg);

void apply_DCT( int Matrix[][8], float final_matrix[][8] );

void extract_matrix(int temporary_matrix[][DCT_SIZE], int ** MATRIX, int row, int col);

void copy_matrix( int quantized_MATRIX[8][8] , int ** , int , int);



int ** get_reverse_dct(int ** MATRIX, int height, int width ,int flg);

void image_decompression(char * input_filename, char *output_filename);

void inverse_DCT(int temporary_matrix[][8], int ans[][8]);

int check_if_valid(char * filename);

#endif // IMAGE_COMPRESSION_H_INCLUDED
