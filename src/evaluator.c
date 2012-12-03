/* This is the brainfuck 'backend'. It does all the interpretation :) */
#include <stdio.h>
#include <string.h>

#include "evaluator.h"

#define MAX_CELLS 65536
void brainfuck_eval( const char* code ) {
	int tape[ MAX_CELLS ];

	int pointer = 0;		/* position in [tape] array */
	int char_pointer = 0;	/* position in [code] array */
	int length = strlen( code );

	/* Loop through all character in the character array */
	while ( char_pointer++ < length ) {
		int loop;

		switch ( code[char_pointer] ) {
		case '>':
			pointer++;
			break;

		case '<':
			pointer--;
			break;

		case '+':
			tape[pointer]++;
			break;

		case '-':
			tape[pointer]--;
			break;

		case '.':
			putchar( tape[pointer] );
			break;

		case ',':
			tape[pointer] = (int) getchar();
			break;

		case '[':
			if( !tape[pointer] ) {
				loop = 1;
				while( loop ) {
					char c = code[ ++char_pointer ];
					if (c == '[') loop++;
					else if (c == ']') loop--;
				}
			}
			break;

		case ']':
			loop = 1;
			while( loop ) {
				char c = code[ --char_pointer ];
				if (c == '[') loop--;
				else if (c == ']') loop++;
			}
			char_pointer--;
			break;
		}
	}
}