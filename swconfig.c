#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int i, menuOption, textSize, mainLoop = TRUE;
char string[100];

int validateInput(){
    for (i = 0; i < textSize; i++){
        if (string[i]<65 || string[i]>90){
            printf("The text format is invalid.\nExample: HELLOWORLD\n");
            return FALSE;
        }   
    }
    return TRUE;
}

void execute(){
    printf("Enter the text to be encrypted(Max of 100 chars): ");
    scanf("%s", string);
    textSize = strlen(string);
    if (validateInput()){
        char format[textSize+13];
        sprintf(format, "chaocipher %d %s", textSize, string);
        printf("the command: %s\n", format);
        system("pause");
        system(format);
    } else {
        execute();
    }
    
    
    
}

void compile(){
    system("gcc chaocipher.c");
    system("gcc -o chaocipher chaocipher.c");
    printf("Compilation complete\n");
    system("pause");
}

void showMenu(){
    printf("\nProgram Menu\n"
        "1 - compile code\n2 - run code\n3 - exit\n"
        "Choose a option: ");
    scanf("%d", &menuOption);
}

int main(int argc, char const *argv[]){

    do{

        showMenu();
        switch (menuOption){
        case 1:
            compile();
            break;
        case 2:
            execute();
            break;
        case 3:
            mainLoop = FALSE;
            break;
        default:
            printf("This option is invalid");
            break;
        }
    } while (mainLoop);
    
    return 0;
}
