#ifndef _TOKENIZER_
#define _TOKENIZER_

/* Returns the numerical value of a string. For example, if a str is "23", the method returns an integer value of 23. */
int str_to_int(char *str);

/* Returns the length of the next whitespace separated word given a string. */
short word_length(char *str);

/* Retuns the length of an entire string, including any whitespace and non-whitespace. */
short str_length(char *str);

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c);

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c);

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str); 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word);

/* Counts the number of words in the string argument. */
int count_words(char *str);

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);
// allocate space = size of word + 1 char for zero-terminator


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
