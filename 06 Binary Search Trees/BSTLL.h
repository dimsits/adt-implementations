#ifndef BSTLL_H
#define BSTLL_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}*bst;

int mem(bst b, int data) {
   	int boolean = 0; bst trav;
   	while (trav != NULL && boolean != 1) {
   		if (trav->data == data) {
   			boolean = 1;
		   } else if (data < trav->data) {
		   	trav = trav->left;
		   } else {
		   	trav = trav->right;
		   }
		}
	return boolean;
}

void insert(bst *b, int data) {
    if (mem((*b), data) != 0) {
    	if ((*b) == NULL) {
    		(*b) = (bst*)malloc(sizeof(struct node));
    		(*b)->data = data;
    		(*b)->left = NULL;
    		(*b)->right = NULL;
		} else if (data < (*b)->data) {
			insert(&((*b)->left), data);
		} else {
			insert(&((*b)->right), data);
		}
	}
}

void del(bst *root, int data) {
	
}

void display(bst b) {
    //PRE-ORDER TRAVERSAL
	if (b != NULL) {
		printf("%d ", b->data);
    	display(b->left);
    	display(b->right);
	}
}

#endif 
