#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main() {
  /*
  char str[200];
  printf("> Enter a word.\n");
  printf("< ");
  fgets(str, sizeof(str), stdin);
  printf("\n> You entered: %s\n", str);
  */
  char s[3];
  s[0] = ' ';
  s[1] = ' ';
  s[2] = '\0';
  //char s[] = {' ', ' ', '\0'};
  //char *s = "  ";
  printf("output:%c", *word_start(s));
  printf("\n");
  
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
  return (c != '\t' && c != ' ');
}


/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str) {
  int before_space = 1; // determine where currently am in str
  int i = 0; // count through str

  
  // iterate to the next non space character or end of string
  while(/*str[i] != '\0'*/1==1) {
    if (non_space_char(str[i])) { // found first non space char
      printf("found non space char:\n");
      return str + i; // return pointer to char
    }

    if (str[i] == '\0') {
      return str + i;
    }
    i++; // next char in str
  }
  
  // reached end of string
  printf("reached end of string:\n");
  return str + i;
}


/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
  return word;
}


/* Counts the number of words in the string argument. */
int count_words(char *str) {
  
  return 0;
  /*
  int p1 = 0; // positions of chars in str
  int p2 = 0;
  int num = 1; // count number of words

  // while current char is not a space char
  while (non_space_char(str[p2]) == 1) {
    p1 += 1;
    p2 += 2;
  }
  while (str[p2] != 
  */
}


