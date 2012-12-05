#include <stdio.h>
#include <stdlib.h>

#include "error.h"

/* throwing an error to stdout */
void error( const char* msg ) {
	printf("Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}