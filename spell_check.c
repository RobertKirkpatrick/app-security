#Your program should contain at least three functions, a function to load the list of words into the
#
#hash map (called load_dictionary), a function to check if a word is correctly spelled (called
#check_word), and a function called check_words to tie them all together. The parameter to
#check_words will be a file pointer containing lines of words separated by spaces, punctuation,
#etc. The function prototypes are as follows1
:
int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[]);
bool load_dictionary(const char* dictionary_file, hashmap_t



hashtable[]);


bool check_word(const char* word, hashmap_t hashtable[]);


