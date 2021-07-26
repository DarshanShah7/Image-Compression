#ifndef LZW_H_INCLUDED
#define LZW_H_INCLUDED



typedef struct trie_node{

    char data;
    int index;
    struct trie_node *child[13];


}trie_node;






typedef trie_node * encoding_dictionary;


void init_encoding_dictionary(encoding_dictionary *);


/*This function will return index if we find the pattern
else will return -1
*/
int search_pattern(encoding_dictionary t, char * p);

void insert_pattern(encoding_dictionary *t, char * s);

trie_node * get_node(char c, int d);


typedef struct dictElement{

    int prefix_code;
    char curr_char;

}dict_element;

dict_element decoding_dictionary[65000];


void init_decoding_dictionary();

void get_output(int code, char *t, FILE * op, dict_element* decoding_dictionary);
void add_element_to_dictionary(int p, char c, dict_element * decoding_dictionary);

//this will delete the file with the given name
void delete_file(char * filename);

#endif // LZW_H_INCLUDED
