#include <stdio.h>
#include <stdlib.h>

#include "evaluator.h"
#include "error.h"

/* Read the file and pass it to the brainfuck_eval() function */
void interpret( const char* filename ) {
	FILE* file = fopen(filename, "r");
	if(!file) error("file opening error");

	/* start size of code is 2. array will be realloc'ed later */
	char* code = (char*) malloc( 2 * sizeof(char) );
	
	/* Strange fix required in order to run most brainfuck programs... */
	/* I don't know (how and why) but it works */
	int pointer = 0;
	code[ pointer++ ] = ' ';	/* it's so strange */

	/* Place each character from the file into the array */
	char c;
	while ((c = fgetc(file)) != EOF) {
		code = (char*) realloc(code, (pointer + 1)*sizeof(char));
		code[ pointer++ ] = c;
	}

	/* adding \0 to the end of string */
	code = (char*) realloc(code, (++pointer)*sizeof(char));
	code[ pointer - 1 ] = '\0';

	/* close the file and run the code */
	fclose(file);

	/* evaluating the code */
	brainfuck_eval(code);
	free(code);
}

int main(int argc, char** argv) {
	if(argc != 2) error("incorrect number of parameters");
	
	interpret(argv[1]);

	return EXIT_SUCCESS;
}