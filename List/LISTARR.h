#ifndef LISTARR.h
#define LISTARR.h
#define SIZE 10
typedef struct {
    char *elem;
    int count;
}List, *ListPTR;

typedef enum {TRUE, FALSE}Bool;

void initList(ListPTR *A);
void expandList(ListPTR *A);
void insertPos(ListPTR *A, char elem, int pos);
void deleteElem(ListPTR *A, char elem);
Bool findElem(ListPTR A, char elem);
void displayList(ListPTR A);

void initList(ListPTR *A) {
    *A = (ListPTR)malloc(sizeof(List));
    *A->elem = (char*)malloc(SIZE * sizeof(char));
    *A->count = 0;
}

void insertPos(ListPTR *A, char elem, int pos) {
    *A->count % SIZE == 0 && *A->count > 0  ? realloc(&(*A), (*A->count + SIZE));

}

#endif

