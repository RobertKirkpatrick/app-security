#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "dictionary.h"
#include <stdbool.h>
#include <string.h>
#define LENGTH 45  //from dictionary.h
#define HASH_SIZE 2000  //from dictionary.h
#define MAX_MISSPELLED 1000  //from dictionary.h

////// From dictionary.h
// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)


typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* hashtable[HASH_SIZE]; //fromdictionary.c
typedef node* hashmap_t;
// Hash table is an array of linked lists.


int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[]);
bool check_word(const char* word, hashmap_t hashtable[]);
bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[]);
int hash_function(const char* word);
////// from dictionary.h



int hash_function(const char* word)
{
    int sum = 0;
    int word_length = strlen(word);

    for (int i = 0; i < word_length; i++)
    {
        sum += word[i];
    }

    int bucket = sum % HASH_SIZE;
    return bucket;
}

/*
 * Run istructions: ./spell_check a_tale_of_two_cities.txt wordlist.txt
 *
 * Your program should contain at least three functions, a function to load the list of words into the hash map (called load_dictionary), a function to check if a word is correctly spelled (called check_word), and a function called check_words to tie them all together. The parameter to check_words will be a file pointer containing lines of words separated by spaces, punctuation, etc. The function prototypes are as follows1:
 * 	int check_words(FILE* fp, hashmap_t hashtable[], char* misspelled[]);
 *	 bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[]);
 * 	bool check_word(const char* word, hashmap_t hashtable[]);
*/

//function to check if a word is correctly spelled
/*fuction check_word(string word, hashmap hashtable[])
{
    Set int bucket to the output of hash_function(word).
    Set hashmap_t cursor equal to hashmap[bucket].
    While cursor is not NULL:
        If word equals cursor->word:
            return True.
        Set curosr to cursor->next.
    Set int bucket to the output of hash_function(word).
    Set hashmap_t cursor equal to hashmap[bucket].
    While cursor is  not NULL:
        If lower_case(word) equals curosr->word:
            return True.
        Set curosr to cursor->next.
    return False.
}*/

//function to load the list of words into the hash map
bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
    /**
     * Loads dictionary into memory.  Returns true if successful else false.
     */
    /**
     * Inputs:
     *  dictionary_file:    Path to the words file.
     *  hashtable:          The hash table to be populated.
     *
     * Returns:
     *  bool:       Whether or not the hashmap successfully populated.
     *
     * Modifies:
     *  hashtable: This hashmap should be filled with words from the file provided.
     **/
    int bucket;
    //Initialize all values in hash table to NULL.
    for (int i=0; i < HASH_SIZE;i++){
         hashtable[i] = NULL;

    }
    //Open dict_file from path stored in dictionary.
    FILE* fp = fopen(dictionary_file, "r");
    char word[255]; //maydelete
    if (fp == NULL){
        printf("No file found");
        exit(0);
    }
    //If dict_file is NULL:
        //return false.

    //While word in dict_file is not EOF (end of file):
    fgets(word, 255, (FILE*) fp);{
        printf("%s\n", word);
        hashmap_t new_node;
        new_node -> next = NULL;
        new_node -> word = word;
        bucket = hash_function(word);
        if (hashtable[bucket] == NULL)
        {
            hashtable[bucket]=new_node;
        }else{
            new_node->next = NULL;
            new_node ->word = word;
    }
    /*
    while(!feof(fp)){
        int line = 0;
        str word = fscanf(fp, "%[^\n]");
        printf("scanned line is %s \n", word)
        hashmap_t new_node;
        new_node -> next = NULL;
        new_node -> word = word;
        bucket = hash_function(word);
        if (hashtable[bucket] == NULL)
        {
            hashtable[bucket]=new_node;
        }else{
            new_node->next = NULL;
            new_node ->word = word;

        }

    }*/
    fclose(fp);
        //Set hashmap_t new_node to a new node.
        //Set new_node->next to NULL.
        //Set new_node->word equal to word.
        //Set int bucket to hash_function(word).
        //if hashtable[bucket] is NULL:
            //Set hashtable[bucket] to new_node.
        //else:
            //Set new_node->next to hashtable[bucket].
            //Set hashtable[bucket] to new_node.
    //Close dict_file.
}

/*
function check_words(file fp, hashmap hashtable[], string misspelled[])
{
    Set int num_misspelled to 0.
    While line in fp is not EOF (end of file):
        Read the line.
        Split the line on spaces.
        For each word in line:
            Remove punctuation from beginning and end of word.
            If not check_word(word):
                Append word to misspelled.
                Increment num_misspelled.
    Return num_misspelled.
}
*/

int main() {
    std::cout << "Hello, World!" << std::endl;
    //int num_misspelled = check_words(text_file, hashtable, misspelled);
    bool success = load_dictionary("wordlist.txt", hashtable);
    printf(%B, success);

    return 0;
}