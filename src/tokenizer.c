#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main() {
  char str[100]; // input is likely not more than 100 chars

  // program will ask for input as long as the first char isn't '0'
  printf("To end the program, enter no words");
  do {
    printf("\n> Enter input.");
    printf("\n< ");
    fgets(str, sizeof(str), stdin);
    printf("\n> You entered: %s\n", str);
    
    char **tokens;
    tokens = tokenize(str);
    print_tokens(tokens);
  } while (*str != '0');
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
  while(1==1) {
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
  
  while (*temp != '\0') { // iterate to end of str
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

  while ((t < num_words)) {
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
