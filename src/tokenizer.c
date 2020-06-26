#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main() {
  char str[200];
  printf("> Enter a word.\n");
  printf("< ");
  fgets(str, sizeof(str), stdin);
  printf("\n> You entered: %s\n", str);

  char *s = "name";
  printf("%x\n", &s[0]);
  char *copy = copy_str(s, 4);
  printf("%c%c%c%c\n", copy[0], copy[1], copy[2], copy[3]);
  printf("%x\n", &s[0]);
  printf("%x\n", &copy[0]);
  return 0;
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
    if (non_space_char(str[i])) { // found first non space char
      return str + i; // move pointer to current char and return
    }
    i++; // next char in str
  }
  
  // reached end of string
  printf("...\n");
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
  int count = 0; // keep count of number of words
  str = word_start(str); // start counting from beginning of 1st word
  
  while (*str != '\0') { // iterate to end of str
    str = word_terminator(str); // go to end of current word
    str = word_start(str); // go to beginning of next word
    
    count++; // count another word
  }

  return count;
}


/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  char *copy = (char*) malloc(len+1);
  int i;
  for (i = 0; i < len; i++) {
    copy[i] = inStr[i];
  }
  copy[i] = '\0';
  
  return copy;
}
// allocate space = size of word + 1 char for zero-terminator


/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {

}


/* Prints all tokens. */
void print_tokens(char **tokens) {

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {
  
}
