#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main(){
    char wordsIn[50], histItem[50];
    List* history = init_history();
    char ** tok;
    printf("Enter the phrase you want to tokenize after the '>' (enter 'E' to exit, 'H' to view history, or '!' if you want to tokenize a history item ) \n");
    printf("> ");
    fgets(wordsIn, sizeof(wordsIn),stdin);
    printf("You entered: %s", wordsIn);
    
    while(*wordsIn != 'E'){
    
        if (*wordsIn == 'H'){
            printf("Here is your history: \n");
            print_history(history);
        }
        else{
            if(*wordsIn == '!'){
                printf("What item in history do you want to tokenize?\n Enter a number for that item \n");
                //not working
                fgets(histItem,sizeof(histItem),stdin);
                //error have to manualy copy contents
                printf("You entered: %d", *histItem);
                char *wn2 = get_history(history ,*histItem);
                //test
                int i =0;
                while(wn2[i] !='\0'){
                    wordsIn[i] = wn2[i];
                    i++;
                }
                wordsIn[i] = '\0';
            }
            
            tok = tokenize(wordsIn);
            print_tokens(tok);
            add_history(history, wordsIn);
        }
        printf("Enter the phrase you want to tokenize after the '>' (enter 'E' to exit, 'H' to view history, or '!' if you want to tokenize a history item ) \n");
        printf("> ");
        fgets(wordsIn, sizeof(wordsIn),stdin);
        printf("You entered: %s", wordsIn);
        
    }
    
    //prints exit message
    if (*wordsIn == 'E'){
        printf("BYE!");
    }
    free_tokens(tok);
    free_history(history);
    return 0;
}
