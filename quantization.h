#ifndef QUANTIZATION_H_INCLUDED
#define QUANTIZATION_H_INCLUDED
#include"image_compression.h"

void quantize_matrix(int mat[8][8],float  Matrix[][DCT_SIZE] ,int flg);

void dequantize_matrix(int mat[8][8] ,int ma[8][8], int flag);

#endif // QUANTIZATION_H_INCLUDED
