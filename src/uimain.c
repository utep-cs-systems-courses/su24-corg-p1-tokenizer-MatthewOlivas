#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"



int main(){
  List *list = init_history();
  char c[100];
  char count = 0;
  
  while(1){
    fputs("\n What do you want to tokenize? (h for history or  #num for specific history or q to quit): ", stdout);

    fflush(stdout);
    
    char count_in = count;
    char curr_char = getchar();

    while(curr_char == '\n');
     while(curr_char != '\n'){

       c[count] = curr_char;
       curr_char = getchar();
       count++;

    }

     if (c[count_in] == 'h' && (count-count_in) == 1){
       
       printf("Full History: \n");
       print_history(list);

     }
     
     else if (c[count_in] == '#' && (count-count_in) == 2){
       
       int num = (int)c[count_in+1] -48;
       printf("Getting %d from Hist: \n%d:", num, num);
       char *word = get_history(list, num);
       
       while (*word != 0){
	 
	 putchar(*word);
	 word++;

       }

       putchar('\n');

     }
     
     else if (c[count_in] == 'q' && (count-count_in) == 1){

       break;
       
     }
     
     else{
       
       printf("Tokenized: \n");
       char **tokens = tokenize(&c[count_in]);
       print_tokens(tokens);
       add_history(list, &c[count_in]);
       
     }
     
     count ++;
  }

  printf("You pressed q to quit \n");

}

  
