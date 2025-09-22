#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c != '\0') && (c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (c != '\0') && (c != ' ' || c != '\t');
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  if(str == NULL) return NULL;

  while(*str != '\0' && space_char(*str)){
    str++;
  }

  if(*str == '\0'){
    return NULL;
  }

  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  if(token == NULL) return NULL;

  while (*token != '\0' && !space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  char *tok = token_start(str);

  while(tok != NULL){
    count++;
    char *end = token_terminator(tok);
    tok = token_start(end);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  if(inStr == NULL || len <= 0){
    return NULL;
  }

  char *newStr = (char *)malloc(len + 1);
  if(newStr == NULL) return NULL;

  for(short i = 0; i < len; i++){
    newStr[i] = inStr[i];
  }

  newStr[len] = '\0';
  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
