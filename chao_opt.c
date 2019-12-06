#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
const char *DECRYPTED_TEXT = "ROBSON";
const char *ENCRYPTED_TEXT = "GMUMVY";

const int TEXT_SIZE = 6;
 
const char *l_alphabet = "HXUCZVAMDSLKPEFJRIGTWOBNYQ";
const char *r_alphabet = "PTLNBQDEOYSFAVZKGJRIHWXUMC";

char left[27], right[27], lTemp[27], rTemp[27], store;
int i, j, indexFound;

clock_t startTime, endTime;

void setupKeys(){
    strcpy(left, l_alphabet);
    strcpy(right, r_alphabet);
    indexFound = 0;
}

void shuffleKeys(){
    for (j = indexFound; j < 26; ++j) lTemp[j - indexFound] = left[j];
    for (j = 0; j < indexFound; ++j) lTemp[26 - indexFound + j] = left[j];
    store = lTemp[1];
    for (j = 2; j < 14; ++j) lTemp[j - 1] = lTemp[j];
    lTemp[13] = store;
    strcpy(left, lTemp);

    for (j = indexFound; j < 26; ++j) rTemp[j - indexFound] = right[j];
    for (j = 0; j < indexFound; ++j) rTemp[26 - indexFound + j] = right[j];
    store = rTemp[0];
    for (j = 1; j < 26; ++j) rTemp[j - 1] = rTemp[j];
    rTemp[25] = store;
    store = rTemp[2];
    for (j = 3; j < 14; ++j) rTemp[j - 1] = rTemp[j];
    rTemp[13] = store;
    strcpy(right, rTemp);
}

void shuffleKeysOptimized(){
    for (j = indexFound; j < 26; ++j){
        lTemp[j - indexFound] = left[j];
        rTemp[j - indexFound] = right[j];
    } 
    for (j = 0; j < indexFound; ++j){
         lTemp[26 - indexFound + j] = left[j];
         rTemp[26 - indexFound + j] = right[j];
    }
    store = lTemp[1];
    for (j = 2; j < 14; ++j) lTemp[j - 1] = lTemp[j];
    lTemp[13] = store;
    strcpy(left, lTemp);

    store = rTemp[0];
    for (j = 1; j < 26; ++j) rTemp[j - 1] = rTemp[j];
    rTemp[25] = store;
    store = rTemp[2];
    for (j = 3; j < 14; ++j) rTemp[j - 1] = rTemp[j];
    rTemp[13] = store;
    strcpy(right, rTemp);
}

void encryptOptimized(){

    setupKeys();

    startTime = clock();

    for (int i = 0; i < TEXT_SIZE; i++){
        for (int j = 0; j < 27; j++){
            if (right[j] == DECRYPTED_TEXT[i]){
                indexFound = j;
                break;
            }
        }
        
        printf("%c", left[indexFound]);

        shuffleKeysOptimized();
    }

    endTime = clock();
    double resultTime = (double) (endTime-startTime)/CLOCKS_PER_SEC;
    printf("\nTime execution on OPTIMIZED encryption: %le\n", resultTime);
    
}

void encrypt(){

    setupKeys();

    startTime = clock();

    for (int i = 0; i < TEXT_SIZE; i++){
        for (int j = 0; j < 27; j++){
            if (right[j] == DECRYPTED_TEXT[i]){
                indexFound = j;
                break;
            }
        }
        
        printf("%c", left[indexFound]);

        shuffleKeys();
    }

    endTime = clock();
    double resultTime = (double) (endTime-startTime)/CLOCKS_PER_SEC;
    printf("\nTime execution on REGULAR encryption: %le\n", resultTime);
    
}

void decrypt(){

    setupKeys();

    for (int i = 0; i < TEXT_SIZE; i++){
        for (int j = 0; j < 27; j++){
            if (left[j] == ENCRYPTED_TEXT[i]){
                indexFound = j;
                break;
            }
        }
        printf("%c", right[indexFound]);

        shuffleKeys();
    }
    printf("\n");

}



 
int main() {

    encrypt();
    encrypt();
    encryptOptimized();
    // printf("Decrypted text: ");
    // decrypt();
    return 0;
}