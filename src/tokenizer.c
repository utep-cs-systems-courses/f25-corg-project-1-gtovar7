#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {
  return (c == ' ' || c == '\t') && c != '\0';
}

int non_space_char(char c) {
  return (c != ' ' && c != '\t' && c != '\0');
}

char *token_start(char *str){
  while(*str && space_char(*str)) str++;
  return *str ? str : NULL;
}

char *token_terminator(char *token){
  while (*token && non_space_char(*token)) token++;
  return token;
}

int count_tokens(char *str){
  int count = 0;
  char *p = str;
  while((p = token_start(p))){
    count++;
    p = token_terminator(p);
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *newStr = (char *)malloc(len + 1);
  for(int i = 0; i < len; i++){
    newStr[i] = inStr[i];
  }
  newStr[len] = '\0';
  return newStr;  
}

char **tokenize(char *str){
  int tokens = count_tokens(str);
  char **arr = (char **)malloc((tokens + 1) * sizeof(char *));
  int i = 0;
  char *p = str;

  while((p = token_start(p))){
    char *end = token_terminator(p);
    arr[i++] = copy_str(p, end - p);
    p = end;
  }
  arr[i] = NULL;
  return arr;
}

void print_tokens(char **tokens){
  for(int i = 0; tokens[i]; i++){
    printf("Token %d: %s\n", i + 1, tokens[i]);
  }
}

void free_tokens(char **tokens){
  for(int i = 0; tokens[i]; i++){
    free(tokens[i]);
  }
  free(tokens);
}
