#include <stdio.h>

int main(){
  char interface[150];
  int i;
  
  printf(">");
  if(fgets(interface, sizeof(interface), stdin) == NULL){
    return 1;
  }

  for(i = 0; interface[i] != '\0'; i++){
    if(interface[i] == '\n'){
      interface[i] = '\0';
      break;
    }
  }
 
  printf("%s\n", interface);
  return 0;
}
  
