#ifndef INPUT_OUTPUT_H_INCLUDED
#define INPUT_OUTPUT_H_INCLUDED

extern int leftOver;
extern int leftValue;
extern int dictionary_size;



int read_binary(FILE *ip, int size);

void write_binary(FILE *op, int code, int size);



#endif // INPUT_OUTPUT_H_INCLUDED
