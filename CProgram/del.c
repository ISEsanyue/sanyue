#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode *next;
} LinkNode;

void del(LinkNode *&L, int x) {
	if (L == NULL) {
		return;
	}
	if (L->data == x) {
		L = L->next;
		return;
	}  else if (L->next == NULL) {
		return;
	} else if (L->next->data == x) {
		LinkNode *p = L->next;
		L->next = p->next;
		return;
	} else {
		L = L->next;
		del(L, x);
	}
}

void delall(LinkNode *&L, int x) {
	if (L == NULL) {
		return;
	}
	if (L->data == x) {
		L = L->next;
	} else if (L->next == NULL) {
		return;
	} else if (L->next->data == x) {
		LinkNode *p = L->next;
		L->next = p->next;
	} else {
		L = L->next;
		delall(L, x);
	}
}

void maxnode(LinkNode *L) {
	if (L == NULL) {
		return;
	}
	if (L->data > max) {
		max = L->data;
	}
	L = L->next;
	maxnode(L);
}

void minnode(LinkNode *L) {
	if (L == NULL) {
		return;
	}
	if (L->data < min) {
		min = L->data;
	}
	L = L->next;
	minnode(L);
}

void show(LinkNode *L) {
	if (L == NULL) {
		return;
	} else {
		printf("%d -> ", L->data);
		show(L->next);
	}
}

int main() {
	//create一个linklist的函数我懒得写了，直接建了一个小链表
	LinkNode *L1 = (LinkNode *)malloc(sizeof(LinkNode));
	L1->data = 1;
	LinkNode *L2 = (LinkNode *)malloc(sizeof(LinkNode));
	L1->next = L2;
	L2->data = 3;
	LinkNode *L3 = (LinkNode *)malloc(sizeof(LinkNode));
	L2->next = L3;
	L3->data = 3;
	LinkNode *L4 = (LinkNode *)malloc(sizeof(LinkNode));
	L3->next = L4;
	L4->data = 5;
	L4->next = NULL;
	show(L1);
	del(L1, 3);
	show(L1);
	//delall(L1,3);
	//show(L1);
}