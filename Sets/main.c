#include <stdio.h>
#include "SETSLL.h"

void main() {
    SET A = NULL;
    insertSortedIfUnique(&A, 1);
    insertSortedIfUnique(&A, 2);
    insertSortedIfUnique(&A, 3);
    SET B = NULL;
    insertSortedIfUnique(&A, 2);
    insertSortedIfUnique(&A, 4);
    insertSortedIfUnique(&A, 5);

    SET Intersection = Intersection(A, B);
}