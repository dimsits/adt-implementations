#ifndef LISTARR_H
#define LISTARR_H
#define SIZE 10

typedef struct LType{
    char *elem;
    int count;
}*List;

typedef enum {
    TRUE, FALSE'
}Bool;

void initList(List *A);
Bool findElem(List A);
void insertSorted(List A, int elem);
void deleteElem(List A, int elem);
void displayList(List A);

void initList(List *A) {
    *A = (List)malloc(sizeof(LType));
    if ((*A) != NULL) {
        (*A)->count = 0;
        (*A)->elem = (char*)malloc(SIZE * sizeof(char));
    }
}

Bool findElem(List A) {
	Bool ret = FALSE;
	int i;
	for (i = 0; i < A->count; i++) {
		
	}
}



#endif

