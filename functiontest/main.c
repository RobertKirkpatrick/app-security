#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[])
{
    //Set int num_misspelled to 0.
    int num_misspelled = 0;
    while(num_misspelled <MAX_MISSPELLED) {
        char* word = calloc(LENGTH+ 1,sizeof(char));

        //While line in fp is not EOF (end of file):

        if (fp == NULL) {
            printf("No file found");
            exit(0);
        }

        //while(fgets(line,LENGTH, fp) != NULL){
        //if(fp)
        //{
            while(!feof(fp))
            {
                char* word_c = calloc(LENGTH+ 1,sizeof(char));

                //Read the line.

                //Split the line on spaces.
                fscanf(fp,"%s",word);
                //printf("%s\n", word);

                ////codeblock for cleaning up the word////
                //For each word in line:
                //Remove punctuation from beginning and end of word.
                int i=0;
                int j=0;
                //cleanup line read, make all characters 0 at the newline

                for(i; i<LENGTH+1; i++){
                    if (isupper(word[i])) {
                        word_c[j] = tolower(word[i]);
                        word[i]=0;
                        j++;
                    }
                    else if (isalpha(word[i])){
                        word_c[j] = word[i];
                        word[i]=0;
                        j++;
                    }
                    else if (ispunct(word[i]) ){ //skip character
                        word[i]=0;
                    }
                    else{
                        word[i]=0;
                    }

                }
                //printf("%s\n", word_c);

                //If not check_word(word):
                //append word to misspelled.
                //Increment num_misspelled.
                if(!check_word(word_c, hashtable)){
                    printf("%s\n", word_c);
                    misspelled[num_misspelled] = word_c;
                    num_misspelled++;

                }


                free(word_c);
            }
            //fclose(fpr);
            return num_misspelled;
        }

    //}

    return num_misspelled;
}

//function to check if a word is correctly spelled
bool check_word(const char* word, hashmap_t hashtable[])
{
    //Set int bucket to the output of hash_function(word).
    int bucket = hash_function(word);
    //Set hashmap_t cursor equal to hashmap[bucket].
    hashmap_t cursor = (node*) malloc(sizeof(node));

    cursor = hashtable[bucket];

    //While cursor is not NULL:
    if (cursor == NULL){
        return false;

    }else{
        while(cursor != NULL ){

            //If word equals cursor->word:

             if( strcmp( cursor ->word, word)==0) {//this is failing when it should be true
                return true;
            }

            //Set cursor to cursor->next.*/
            cursor = cursor -> next;

        }
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
    //initial character for line read
    //char *line = (char*) malloc(sizeof(char) * LENGTH);
    char* line = calloc(LENGTH+ 1,sizeof(char));



    //hashmap_t curr = (node*) malloc(sizeof(node));

    while(fgets(line,LENGTH, fp) != NULL){
    // For each line, get the word
        //initialize char for cleaned up word
        //char *word_c = (char*) malloc(sizeof(char) * LENGTH);
        char* word_c = calloc(LENGTH+ 1,sizeof(char));
        //printf("%s\n", line);

        //malloc new node
        hashmap_t new_node = (node*) malloc(sizeof(node));

        ////codeblock for cleaning up the word////

        int i=0;
        int j=0;
        //cleanup line read, make all characters 0 at the newline

        for(i; i<LENGTH+1; i++){
            if (isupper(line[i])) {
                word_c[j] = tolower(line[i]);
                line[i]=0;
                j++;
            }
            else if (isalpha(line[i])){
                word_c[j] = line[i];
                line[i]=0;
                j++;
            }
            else if (ispunct(line[i]) ){ //skip character
                line[i]=0;
            }
            else{
                line[i]=0;
            }

        }

        //printf("%s", &word_c);

        new_node -> next = NULL;
        strncpy(new_node -> word, word_c, LENGTH);
        //printf("%s \n", new_node -> word );
        bucket = hash_function(word_c);
        //curr = hashtable[bucket];

        if (hashtable[bucket] == NULL) //if there isn't a word, then add it and point to null
        {
            //new_node is assigned the word, and pointer next

            hashtable[bucket]= new_node;
            //hashtable[bucket] = new_node;
            //printf("%i\n", bucket);
            //printf("%s\n", (hashtable[bucket]->word));

        }else
            {
            /*code for adding to end of list

            while(curr-> next != NULL){
                curr = curr->next;
            }curr ->next = new_node;*/
            //Add node to front of list, and
            new_node->next = hashtable[bucket];
            hashtable[bucket] = new_node;

            //hashtable[bucket]=curr;
            //printf("%s\n", hashtable[bucket]->word);
        }
        free(word_c);
    }


    fclose(fp);

    return true;
}


int main() {

    //int num_misspelled = check_words(text_file, hashtable, misspelled);
    bool success = load_dictionary("/home/rob/appsecurity/app-security/wordlist.txt", hashtable);
    printf("%d\n", success);
    char *word2 = "semicolons";
    //bool test = check_word(word2, hashtable);
    //printf("%d\n", test);
    char *misspelled[MAX_MISSPELLED];
    FILE* fp = fopen("/home/rob/appsecurity/app-security/test1.txt", "r");
    int miss = check_words(fp, hashtable, &misspelled);
    printf("%d\n", miss);
    //check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[])


    return 0;
}