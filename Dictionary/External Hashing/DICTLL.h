#ifndef DICTLL_H
#define DICTLL_H
#define MAX 10

typedef struct node {
    int elem;
    struct node *next;
}*SET;

typedef SET Dict[MAX];

typedef enum { TRUE, FALSE }Bool;

void initDict(Dict A);
void displayDict(Dict A);
int hash(int val);
Bool isMember(Dict A, int val);
void insert (Dict A, int val);
void deleteElem(Dict A, int val);

void initDict(Dict A) {
	int i;
	for (i = 0; i < MAX; i++) { A[i] = NULL; }
}

void displayDict(Dict A) {
	int i; SET trav;
	printf("Dictionary\n\n");
	for (i = 0; i < MAX; i++) {
		printf("[%d]", i);
		for (trav = A[i]; trav != NULL; trav = trav->next) { printf("%4d", trav->elem); }
		printf("\n");
	}
	printf("\n\n");
}

int hash(int val) { return val % 10; }

Bool isMember(Dict A, int val) {
	SET trav; Bool mem = FALSE;
	for (trav = A[hash(val)]; trav != NULL && mem == FALSE; trav = trav->next) { 
	mem = trav->elem == val ? TRUE : FALSE;
	}
	return mem;
}

void insert(Dict A, int val) {
	SET *trav;
	if (isMember(A, val) == FALSE) {
		for (trav = &(A[hash(val)]); (*trav) != NULL && val < (*trav)->elem; trav = &((*trav)->next) ) {}
		SET newNode = (SET)malloc(sizeof(struct node));
		if (newNode != NULL) {
			newNode->elem = val;
			newNode->next = *trav;
			*trav = newNode;
		} 
	}
}

void deleteElem(Dict A, int val) {
	if (isMember(A, val) == TRUE) {
		SET *trav;
		for (trav = &(A[hash(val)]); (*trav)->elem != val; trav = &((*trav)->next)) {}
		SET temp = (*trav);
		(*trav) = (*trav)->next;
		free(temp);
	}
}


#endif
