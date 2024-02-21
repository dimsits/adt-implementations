#include <stdio.h>
#include "SETSLL.h"

void main() {
    SET A = NULL;
    insertSortedIfUnique(&A, 1);
    insertSortedIfUnique(&A, 2);
    insertSortedIfUnique(&A, 3);
    insertSortedIfUnique(&A, 1);
}