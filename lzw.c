#include<stdio.h>
#include<stdlib.h>
#include"lzw.h"
#include"algorithms.h"
#include"input_output.h"

//This function returns a node pointer by creating a node according to the given parameters
trie_node * get_node(char c, int d){


    trie_node * node ;
    node = (trie_node *)(malloc(sizeof(trie_node)));
    for(int i = 0; i <= 12; i++){

        node->child[i] = NULL;

    }

    node->data = c;
    node->index = d;
    return node;

}

//initializes the dictionary containing single characters
void init_encoding_dictionary(encoding_dictionary * t){

    trie_node * new_node;
    new_node = (trie_node *)(malloc(sizeof(trie_node)));

    //11 the child is space
    trie_node* tmp_node;
    tmp_node = get_node( '\0' + 32 ,11);
    new_node->child[11] = tmp_node;

    //12 the child is '-'
    tmp_node = get_node( '\0' + 45 ,12);
    new_node->child[12] = tmp_node;

    //10 th child is '\n'
    tmp_node = get_node('\0'+ 10,10);
    new_node->child[10] = tmp_node;
    for(int i = 0; i <= 9 ; i++){

        trie_node* tmp_node;
        tmp_node = get_node( '0' + i ,i);
        new_node->child[i] = tmp_node;

    }
    //put the index of root as -1.
    new_node->index = -1;
    *t = new_node;
    return ;

}

/*
This function inserts the pattern
also updates the dictionary_size after inserting the pattern
*/
void insert_pattern(encoding_dictionary *t, char * s){

        trie_node * node = *t;
        int i = 0;
        int flg = 0;
        int ret = 0;
        while(1){

            if(s[i] == '\0' || flg == 1)
            {
                break ;
            }
            char c = s[i];
            int pos ;
            if( c == '-')pos = 12;
            else if( c == ' ' )pos = 11;
            else if (c == '\n')pos = 10;
            else pos =  c - '0';
            if( node->child[pos] == NULL ){

                flg = 1;
                dictionary_size++;
                trie_node *tmp_node  = get_node(s[i] , dictionary_size );
                node->child[pos] = tmp_node;


            }
            else {



                node = node->child[pos];
                ret = node->index;
                i++;

            }


        }

}

/*
This function searches a pattern in the dictionary
returns -1, if the pattern is not present
returns the code for pattern if present
*/

int search_pattern(encoding_dictionary t, char *p)
{
    int i = 0;
    trie_node * node = t;
    int flg = 0;
    int ret = 0;
    while(p[i]!='\0')
    {
        char c = p[i];
        int pos ;
        if( c == '-')pos = 12;
        else if( c == ' ' )pos = 11;
        else if (c == '\n')pos = 10;
        else pos = c-'0';


        if(node->child[pos] != NULL )
        {
            node = node->child[pos];
            ret = node->index;

        }
        else
        {
            flg = 1;
            break;
        }
        i++;

    }

    if(flg)return -1;
    return ret;

}

void get_output(int code, char *t, FILE * op, dict_element* decoding_dictionary)
{


    char output[65000];
    int i = 0;
    while(1)
    {
        if(code == -1)break;

        output[i] = decoding_dictionary[code].curr_char;

        i++;
        code = decoding_dictionary[code].prefix_code;





    }

    i--;
    *t = output[i];
    for(int j = i; j>=0; j--)
    {
        char c = output[j];
        fputc(c,op);
    }



}
void add_element_to_dictionary(int p, char c, dict_element * decoding_dictionary)
{
    dictionary_size++;
    dict_element tmp ;
    tmp.curr_char = c;
    tmp.prefix_code = p;
    decoding_dictionary[dictionary_size] = tmp;

    return;

}





void init_decoding_dictionary()
{
    for(int i=0;i<=9;i++)
    {
        dict_element dt;
        dt.prefix_code = -1;
        dt.curr_char = '0'+i;
        decoding_dictionary[i] = dt;
    }

    dict_element dt;
    dt.prefix_code = -1;
    dt.curr_char = ' ';
    decoding_dictionary[11] = dt;

    dt.prefix_code = -1;
    dt.curr_char = '\n';
    decoding_dictionary[10] = dt;

    dt.prefix_code = -1;
    dt.curr_char = '-';
    decoding_dictionary[12] = dt;

}



void delete_file(char * filename)
{
    if(remove(filename) == 0)
    {
        return ;
    }
    else
    {
            fprintf(stderr,"Unable to delete the file\n");
    }
}

