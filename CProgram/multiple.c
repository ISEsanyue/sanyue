#include<stdio.h>
#include<stdlib.h>
struct node;
typedef struct node *ptrtonode;
typedef ptrtonode polynomial;
typedef ptrtonode position;
struct node {
	int coef;
	int expo;
	ptrtonode next;
};
polynomial InitList(void);
void CreatList(polynomial L);
void ShowList(polynomial L);
polynomial MultPolys(polynomial L1, polynomial L2);
void DeleteList(polynomial L);
int main(void) {
	polynomial L1, L2, multpoly;
	L1 = InitList();
	CreatList(L1);
	puts("\nPolynomial1:");
	ShowList(L1);
	L2 = InitList();
	CreatList(L2);
	puts("\nPolynomial2:");
	ShowList(L2);
	puts("\nMultiple two polynomials:");
	multpoly = MultPolys(L1, L2);
	ShowList(multpoly);
	DeleteList(L1);
	DeleteList(L2);
	DeleteList(multpoly);
	return 0;
}
polynomial InitList(void)
{
	polynomial L = (polynomial)malloc(sizeof(struct node));
	if (L == NULL) {
		fprintf(stderr,"Out of space\n");
		exit(EXIT_FAILURE);
	}
	L->next = NULL;
	return L;
}
void InsertTail(int co, int ex, position r)
{
	polynomial tem = (polynomial)malloc(sizeof(struct node));
	tem->coef = co;
	tem->expo = ex;
	tem->next = r->next;
	r->next = tem;
}
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
void CreatList(polynomial L)
{
	printf("\nPlease enter coefficients and exponents"
	 "(nonumeric values to stop):\n");
	int co, ex;
	position r = L;
	while (scanf("%d %d",&co, &ex) == 2) {
		InsertTail(co, ex, r);
		r = r->next;
	}
	eatline();
}
void ShowList(polynomial L)
{
	position p = L->next;
	while (p) {
		if (p->coef)
			printf("%dX^%d",p->coef,p->expo);
		p = p->next;
		if (p && p->coef > 0)
			putchar('+');
	}
	putchar('\n');
}
/*用插入排序，排序时将同系数项合并
将序列分成已排序和未排序两部分
*/
void MergeNode(position p, position q)
{
	p->coef = p->coef + q->coef;
}
void InsertAfter(position p, position ptemp, position pbtemp)
{
	pbtemp->next = ptemp->next;
	ptemp->next = p->next;
	p->next = ptemp;
}
void SortList(polynomial L)
{
	position p, pbefore, ptemp, pbtemp, tem;
	ptemp = L->next->next;
	pbtemp = L->next;
	while (ptemp) {
		p = L->next;
		pbefore = L;
		while (p != ptemp && ptemp->expo < p->expo) {
				pbefore = p;
				p = p->next;
		}
		if (p == ptemp) {
			pbtemp = ptemp;
			ptemp = ptemp->next;
		}
		else {
	 		if (ptemp->expo == p->expo) {
				MergeNode(p, ptemp);
				tem = ptemp;
				pbtemp->next = ptemp->next;
				ptemp = ptemp->next;
				free(tem);
			}
			else if (ptemp->expo > p->expo) {
				InsertAfter(pbefore, ptemp, pbtemp);
				ptemp = pbtemp->next;
			}
		}
	}
}
int IsEmpty(polynomial L)
{
	return L->next == NULL;
}
polynomial MultPolys(polynomial L1, polynomial L2)
{
	polynomial multpoly = InitList();
	position p1, p2, p = multpoly;
	int co, ex;
	if (IsEmpty(L1) || IsEmpty(L2)) {
		fprintf(stderr,"Empty linked list\n");
		exit(EXIT_FAILURE);
	}
	for (p1 = L1->next; p1 != NULL; p1 = p1->next) 
		for (p2 = L2->next; p2 != NULL; p2 = p2->next) {
			co = p1->coef * p2->coef;
			ex = p1->expo + p2->expo;
			InsertTail(co, ex, p);
			p = p->next;
		}
	SortList(multpoly);
	return multpoly;
}
void DeleteList(polynomial L)
{
	position p, tem;
	p = L->next;
	L->next = NULL;
	while (p) {
		tem = p->next;
		free(p);
		p = tem;
	}
}
