#include <stdio.h>
#include <stdlib.h>
#include "DICTLL.h"


void main() {
	Dict D;
	initDict(D);
	insert(D, 0);
	insert(D, 23);
	insert(D, 35);
	displayDict(D);
	deleteElem(D, 23);
	displayDict(D);
	
}
