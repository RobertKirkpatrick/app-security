#include <check.h>
#include "dictionary.h"
#include <stdlib.h>

#define DICTIONARY "wordlist.txt"
#define TESTDICT "test_worlist.txt"

int main() {
    hashmap_t hashtable[HASH_SIZE];
    //int num_misspelled = check_words(text_file, hashtable, misspelled);
    bool success = load_dictionary("/home/rob/appsecurity/app-security/wordlist.txt", hashtable);
    printf("%d\n", success);
    //char *word2 = "semicolons";
    //bool test = check_word(word2, hashtable);
    //printf("%d\n", test);
    char *misspelled[MAX_MISSPELLED];
    FILE* fp = fopen("/home/rob/appsecurity/app-security/test1.txt", "r");
    int miss = check_words(fp, hashtable, &misspelled);
    printf("%d\n", miss);
    //check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[])


    return 0;
}