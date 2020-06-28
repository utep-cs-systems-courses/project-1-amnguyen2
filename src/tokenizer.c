#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  char str[100]; // input is likely not more than 100 chars
  List *history = init_history(); // initialize history of input
  
  // program will ask for input as long as the first char isn't '0'
  printf("> To end the program, enter 0");
  do {
    printf("\n> Enter input.");
    printf("\n< ");
    fgets(str, sizeof(str), stdin); // get input
    printf("> You entered: %s", str);
    
    if (str[0] == '0') { // user wants to exit program
      printf("\n> EXITING PROGRAM\n");
      return 0; // exit
      
    } else if ((str[0] == '!') && (word_length(str) > 1)) { // user wants to input a command
      int n = str[1] - '0'; // cast command argument into integer
      if (n > 0) { // view a specific history item
	printf("> %s\n", get_history(history, n));
      } else { // view the entire history list
	print_history(history);
      }
      
    } else { // tokenize any other input and add to history
      char **tokens;
      tokens = tokenize(str); // tokenize
      add_history(history, word_start(str)); // add tokenized words to history
    }
   
  } while (str_length(str) > 0);
}


/* Returns the length of the next whitespace separated word given a string. */
short word_length(char *str) {
  str = word_start(str); // go to first word
  int i = 0; // current character in str
  short count = 0; // count number of chars in next word
  
  while(non_space_char(str[i]) && (count_words(str) > 0)) { // iterate to end of next word
    count++; // count +1 character
    i++; // next character
  }
  return count;
}


/* Retuns the length of an entire string, including any whitespace and non-whitespace. */
short str_length(char *str) {
  int i = 0; // current char in str
  short count = 0; // count number of chars in str

  while (str[i] != '\0') {
    i++;
    count++;
  }
  return count-1;
}


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  return (c == '\t' || c == ' ');
}


/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c) {
  return ((c != '\t') && (c != ' '));
}


/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str) {
  int i = 0; // count through str
  
  // iterate to the next non space character or end of string
  while(i < str_length(str)) {
    if (non_space_char(str[i])) { // found first non space char or end of string
      return str + i; // move pointer to current char and return
    }
    i++; // next char in str
  }
  
  // reached end of string
  return str + i;
}


/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
  int i = 0; // iterate through characters in 'word'

  while (word[i] != '\0') { // iterate to end of 'word'
    if (space_char(word[i])) { // found end of a word 
      return word + i; // move pointer to current char and return
    }
    i++; // next character
  }
  return word + i;
}


/* Counts the number of words in the string argument. */
int count_words(char *str) {
  char *temp = str;
  int count = 0; // keep count of number of words
  temp = word_start(temp); // start counting from beginning of 1st word
  
  while (temp[0] != '\0') { // iterate to end of str
    temp = word_terminator(temp); // go to end of current word
    temp = word_start(temp); // go to beginning of next word
    
    count++; // count another word
  }

  return count;
}


/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  char *copy = (char*) malloc(len+1); // allocate memory

  int i; // keep track of where we are in string 'inStr'
  for (i = 0; i < len; i++) {
    copy[i] = inStr[i]; // copy a character into a new string 'copy'
  }
  copy[i] = '\0'; // last char is zero-terminator
  
  return copy;
}


/* Prints all tokens. */
void print_tokens(char **tokens) {
  int t = 0; // current token
  while(tokens[t]) {
    printf("tokens[%d] = %s", t, tokens[t]); // print token position and word
    printf("\n");
    t++; // next token
  }
}


/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {
  int t = 0; // current token
  while (tokens[t]) { // iterate through all tokens
    free(tokens[t]); // "deallocate" current token
    t++; // next token
  }
  free(tokens); // free pointer to pointer
}


/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str) {
  char *temp = str; // temporary pointer in place of str
  int t = 0; // current token (word)
  int num_words = count_words(temp); // number of words in str
  char **tokens = (char**) malloc(sizeof(char*) * (num_words+1)); // allocate memory for tokens

  while (t < num_words) {
    // get next word (token)
    temp = word_start(temp); // go to start of word
    char *curr_word = copy_str(temp, word_length(temp)); // save word 
    temp = word_terminator(temp); // go to end of word

    tokens[t] = curr_word; // add word as token to tokens
    
    t++; // next token
  }
  tokens[t] = '\0';
  return tokens;
}
