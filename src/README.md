Project 1: Tokenizer
====================
I have written functions that are used to handle input strings from the user and tokenize every space-separated word. Words are separated into tokens by either ' ' or '\t' (tab). Any other character that the user might input is considered a valid character and is part of a word. Every line that the user inputs into the program that is not a command is recorded into a linked list called 'history'.


## Useful Commands

**> make** to compile the tokenizer program.

**> ./lab1** to run the newly created executable after compiling.

**> make clean** to clean temporary files from the project's directory. 


## Using the Tokenizer

0. Notes
   - Output from the program will be prefixed by a ">".
   - When you're being prompted for input, the program will leave a blank space for you, prefixed by a "<".

1. You will be prompted to input a string. Input anything using your keyboard.
2. After you input something, you can check the history of your inputs using the following command:
   - **!N** where 'N' indicates the id number of an item in your history. 
   - **!1** will print the very first input you gave the program. **!2** will print the second input you gave the program.
   - **!0** will print your entire input history.
3. To exit the program, input:
   - **0** or nothing at all.
