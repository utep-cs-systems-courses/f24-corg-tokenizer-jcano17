#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
if(c == '\t' | c==' '){
  return 1;
 }
 return 0 ;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c!= '\t' && c!=' '){
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next
   space-separated token in zero-terminated str.  Return a zero pointer if
   str does not contain any tokens. */
char *token_start(char *str){
  while(*str && space_char(*str) ){
    str++;
  }
  if (*str == '\0'){
    return NULL;
  }
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
    int count = 0;
    str = token_start(str);
    while(*str != '\0'){
        if(non_space_char(*str) && (space_char(*(str-1)) || *(str-1) =='\0')){
            count++;
        }
        str++;
    }
    return count;
}

/* Returns a fresly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    char *cpyStr = (char *)malloc((len+1)* sizeof(char));
    for (int i= 0; i < len; i++){
     cpyStr[i] = inStr[i];
    }
    cpyStr[len]='\0';
    return cpyStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str){
    int count = count_tokens(str);
    char **tokens =(char**) malloc((count+1)*sizeof(char*));
    int cnt = count_tokens(str);
    for (int i= 0; i < cnt; i++){
     char *b = token_start(str);
     str= token_terminator(b);
     int len = str- b;
     tokens[i]=copy_str(b,len);
    }
    
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    while (*tokens != NULL) {
        printf("token: %s\n", *tokens);
        tokens++;
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    char **vector = tokens;
    if (tokens == NULL) {
        return ;
    }
    while(*tokens != NULL){
        free(*tokens);
        tokens++;
    }
    free(vector);
}

