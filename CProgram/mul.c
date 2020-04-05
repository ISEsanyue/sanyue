#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
	int xi;
	int zhi;
	struct Lnode *next;
}LinkNode;


void sort(char s1[], char s2[], LinkNode *node) {
	int part = 0;
	int i = 0;
	int op = 0;
	int fu = 0;
	LinkNode *L = node;
	while (s1[i]!='\0') {
		if (s1[i] == '-') {
			fu = 1;
		}
		int flag1 = 0;
		int flag2 = 0;
		if (s1[i] >= '0' && s1[i] <= '9') {
			int x = s1[i] - '0';
			i++;
			while (s1[i] != '\0' && s1[i] != '+' && s1[i] != '-') {
				if (s1[i] == 'x') {
					flag1 = 1;
					L->xi = fu == 1 ? -x : x;
					fu = 0;
				}
				if (s1[i] >= '0' && s1[i] <= '9') {
					flag2 = 1;
					L->zhi = s1[i] - '0';
				}
				i++;
			}
			if (s1[i] == '\0' && s1[i] == '+' && s1[i] == '-') {
				i--;
			}
			if (flag1 == 0) {
				L->xi = fu == 1 ? -x : x;
				fu = 0;
				L->zhi = 0;
			} else if (flag2 == 0) {
				L->zhi = 1;
			}
			LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
			p = NULL;
			p->next = NULL;
			L->next = p;
			L = L->next;
		}
		i++;
	}
	LinkNode *q = node;
	while(q != NULL) {
		printf("%d, %d\n", q->xi, q->zhi);
		q = q->next;
	}
}

int main() {
	LinkNode *L1;
	L1 = (LinkNode *)malloc(sizeof(LinkNode));
	L1 = NULL;
	LinkNode *L2;
	L2 = (LinkNode *)malloc(sizeof(LinkNode));
	L2 = NULL;
	LinkNode *L3;
	L3 = (LinkNode *)malloc(sizeof(LinkNode));
	L3 = NULL;
	char shi1[100];
	char sort1[100];
	char shi2[100];
	char sort2[100];
	printf("第1个多项式：\n");
	printf(" 排序前多项式：");
	scanf("%s", shi1);
	sort(shi1,sort1, L1);
	//printf(" 排序后多项式:%s\n",sort1);
	printf("第2个多项式：\n");
	printf(" 排序前多项式：");
	scanf("%s", shi2);
	sort(shi2,sort2, L2);
	//printf(" 排序后多项式:%s\n",sort1);

}