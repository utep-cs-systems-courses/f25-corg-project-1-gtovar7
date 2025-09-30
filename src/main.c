#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int str_equal(const char *a, const char *b);
void remove_newline(char *s);

int main() {
  List *list = init_history();
  char input[256];
  
  puts("Started Program");

  while(1){
    printf(">");
    fflush(stdout);

    if((fgets(input, sizeof(input), stdin)) == NULL){
      break;
    }

    remove_newline(input);
    if(str_equal(input, "exit")){
      break;
    }

    if(str_equal(input, "history")){
      print_history(list);
      continue;
    }

    if (input[0] == '!') {
      int id = atoi(&input[1]);
      char *cmd = get_history(list, id);
      if (cmd) {
	printf("Token: %s\n", cmd);
	char **tokens = tokenize(cmd);
	print_tokens(tokens);
	free_tokens(tokens);
      } else {
	printf("No history with id %d\n", id);
      }
      continue;
    }

    add_history(list, input);

    char **tokens = tokenize(input);
    print_tokens(tokens);
    free_tokens(tokens);
  }

  free_history(list);
  return 0;
}

int str_equal(const char *a, const char*b){
  int i = 0;
  while(a[i] && b[i]){
    if(a[i] != b[i]){
      return 0;
    }
    i++;
  }
  return (a[i] == '\0' && b[i] == '\0');
}

void remove_newline(char *s){
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] == '\n'){
      s[i] = '\0';
      break;
    }
  }
}
      
