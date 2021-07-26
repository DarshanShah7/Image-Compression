#include<stdio.h>
#include"quantization.h"
#include"image_compression.h"
#include<math.h>

//taken from  https://web.stanford.edu/class/ee398a/handouts/lectures/08-JPEG.pdf
int Q_Y[DCT_SIZE][DCT_SIZE] = {
    {16, 11, 10, 16, 24, 40, 51, 61},
    {12, 12, 14, 19, 26, 58, 60, 55},
    {14, 13, 16, 24, 40, 57, 69, 56},
    {14, 17, 22, 29, 51, 87, 80, 82},
    {18, 22, 37, 56, 68, 109, 103, 77},
    {24, 35, 55, 64, 81, 104, 113, 92},
    {49, 64, 78, 87, 103, 121, 120, 101},
    {72, 92, 95, 98, 112, 100, 103, 99}
};

int Q_C[DCT_SIZE][DCT_SIZE] = {
        {17, 18, 24, 47, 99, 99, 99, 99},
        {18, 21, 26, 66, 99, 99, 99, 99},
        {24, 26, 56, 99, 99, 99, 99, 99},
        {47, 66, 99, 99, 99, 99, 99, 99},
        {99, 99, 99, 99, 99, 99, 99, 99},
        {99, 99, 99, 99, 99, 99, 99, 99},
        {99, 99, 99, 99, 99, 99, 99, 99},
        {99, 99, 99, 99, 99, 99, 99, 99}
};


void quantize_matrix(int matrix[][8],float MATRIX[][DCT_SIZE], int flg)
{
    int i ;
    int j ;
    for(i = 0; i < DCT_SIZE; i++)
    {

        for(j = 0; j < DCT_SIZE; j++)
        {
            if(flg)
                matrix[i][j] = (int)(round(MATRIX[i][j]/Q_Y[i][j]));
            else
                matrix[i][j] = (int)(round(MATRIX[i][j]/Q_C[i][j]));

        }
    }



}

void dequantize_matrix(int ans[8][8],int MATRIX[][8] , int flag)
{

    int i ;
    int j ;
    for(i = 0; i < DCT_SIZE; i++)
    {

        for(j = 0; j < DCT_SIZE; j++)
        {
            if(flag)
                ans[i][j] = MATRIX[i][j]*Q_Y[i][j];
            else
               ans[i][j] = MATRIX[i][j]*Q_C[i][j];

        }
    }


}



