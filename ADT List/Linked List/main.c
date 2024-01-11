#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//STRUCTURE DEFINITIONS
typedef struct {
    char fName[10];
    char lName[20];
    char mInitial;
    int age;
}person;

typedef struct node {
    person P;
    struct node *next;
}*node;

typedef struct {
    node head;
    int count;
}list;

//FUNCTION HEADERS
node insert(person P);


void main() {

}

//FUNCTION DEFINITIONS