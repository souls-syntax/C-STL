//! XOR Implementation for linkedList -- Ref TSoding

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef struct {
	int value;
	uintptr_t xored;
} Node;

Node *node_create(int value) {
	Node *node = malloc(sizeof(*node));
	memset(node, 0,sizeof(*node));
	node->value = value;
	return node;
}

typedef struct{
	Node *begin;
	Node *end;
} Linked_List;

void ll_append(Linked_List *ll, int value)
{
	if(ll->end == NULL) {
		assert(ll->begin == NULL);
		ll->end = node_create(value);
		ll->begin = ll->end;
	} else {
		Node *node = node_create(value);
		node->xored = (uintptr_t)ll->end;
		ll->end->xored ^= (uintptr_t)node;
		ll->end = node;
	}
}

void *node_next(Node *node, uintptr_t *prev)
{
	Node *next = (Node*)(node->xored^*prev);
	*prev = (uintptr_t)node;
	return next;
}

int main(void) {
	Linked_List xs = {0};
	for (int x = 0; x <=10; ++x) {
		ll_append(&xs, x);	
	}
	uintptr_t prev = 0;
	for (Node *iter= xs.end; iter; iter = node_next(iter, &prev)) {
		printf("%d\n", iter->value);	
	}
	return 0;
}
