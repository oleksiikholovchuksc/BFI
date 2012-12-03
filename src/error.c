#include <stdio.h>
#include <stdlib.h>

#include "error.h"

/* throwing an error to stdout */
void error( const char* msg ) {
	printf("Error: %s.\n", msg);	/* I prefer fprintf instead of printf */
	exit(EXIT_FAILURE);
}