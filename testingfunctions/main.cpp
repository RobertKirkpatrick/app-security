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

/**
 * Array misspelled is populated with words that are misspelled. Returns the length of misspelled.
 */
/**
 * Inputs:
 *  fp:         A file pointer to the document to check for spelling errors.
 *  hashtable:  The hash table used to determine spelling
 *  misspelled: An empty char* array to be populated with misspelled words.
 *              This array will never be greater than 1000 words long.
 *
 * Returns:
 *  int:        The number of words in the misspelled arary.
 *
 * Modifies:
 *  misspelled: This array will be filled with misspelled words.
 *
 * Example:
 *  int num_misspelled = check_words(text_file, hashtable, misspelled);
 **/
/*
int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[])
{
    //Set int num_misspelled to 0.
    int num_misspelled = 0;
    //While line in fp is not EOF (end of file):
    while(fgets(line, LENGTH, fp) != NULL) {
        //malloc new node
        hashmap_t new_node = (node *) malloc(sizeof(node));
        //Read the line.

        //Split the line on spaces.
        //For each word in line:
        //Remove punctuation from beginning and end of word.
        //If not check_word(word):
        //append word to misspelled.
        //Increment num_misspelled.
        //Return num_misspelled.
        free(new_node);
        return num_misspelled;
    }
}*/

//function to check if a word is correctly spelled
bool check_word(const char* word, hashmap_t hashtable[])
{
    //Set int bucket to the output of hash_function(word).
    int bucket = hash_function(word);
    //Set hashmap_t cursor equal to hashmap[bucket].
    node *curr = hashtable[bucket];
    //printf("%s\n", curr->word);
    printf("%s\n", word);
    //While cursor is not NULL:

    while(curr != NULL){
        //If word equals cursor->word:
        if( strcmp( word, curr ->word)==0) {
            return true;
        }
        else{
            //Set cursor to cursor->next.
            curr = curr ->next;
            if( strcmp( word, curr ->word)==0){
                return true;
            }

        }curr = NULL;
    }return false;

}

bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[]) {
    int bucket = 0;
    //Initialize all values in hash table to NULL.
    for (int i=0; i < HASH_SIZE;i++){
        hashtable[i] = NULL;

    }

    FILE* fp = fopen(dictionary_file, "r");

    if (fp == NULL) {
        printf("No file found");
        exit(0);
    }
    //Start reading in lines
    char *line = (char*) malloc(sizeof(char) * LENGTH);
    hashmap_t new_node = (node*) malloc(sizeof(node));
    hashmap_t curr= (node*) malloc(sizeof(node));

    while(fgets(line,LENGTH, fp) != NULL){
        //malloc new node

        new_node -> next = NULL;
        strcpy(new_node -> word, line);
        bucket = hash_function(line);
        curr = hashtable[bucket];

        if (curr == NULL) //if there isn't a word, then add it and point to null
        {
            //new_node is assigned the word, and pointer next

            hashtable[bucket]= new_node;
            //hashtable[bucket] = new_node;
            //printf("%i\n", bucket);
            printf("%s\n", &(hashtable[bucket]->word));

        }else
            { //should add another conditional to check for more than one node at the collisiion
            while(curr-> next != NULL){
                curr = curr->next;
            }
            curr ->next = new_node;
            //new_node->next = hashtable[bucket];
            //hashtable[bucket] = new_node; //this doesn't seem right but is in the pseudcode
            //new_node ->next = NULL;

            //hashtable[bucket]=curr;
            printf("%s\n", curr->word);
        }


    }
    free(line);

    fclose(fp);

    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    //int num_misspelled = check_words(text_file, hashtable, misspelled);
    bool success = load_dictionary("/home/rob/appsecurity/app-security/testingfunctions/wordlist.txt", hashtable);
    printf("%d\n", success);

    //bool test = check_word(word2, hashtable);
    //printf("%d\n", test);
    return 0;
}