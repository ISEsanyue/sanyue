#include <stdio.h>
#include <stdlib.h>

int shi1[30][3];
int shi2[30][3];
int len1 = 0;
int len2 = 0;
int result[1000][3];

typedef struct node {
	int coef;
	int exp;
	struct node *next;
}NODE;

void sort1(char s[]) {
	int part = -1;
	int i = 0;
	int fu = 0;
	while (s[i] != '\0') {
		if (s[i] == '-') {
			fu = 1;
			i++;
		} else if (s[i] == '+') {
			fu = 0;
			i++;
		}
		int j = 0;
		int count = 0;
		char ch[2];
		int flag1 = 0, flag2 = 0, flag3 = 0;
		while (s[i] != '\0' && s[i] != '+' && s[i] != '-') {
			if (s[i] >= '0' && s[i] <= '9') {
				if (s[i + 1] == 'x') {
					flag1 = 1;
					ch[0] = s[i];
				} else {
					flag2 = 1;
					ch[1] = s[i];
				}
				count++;
			} else if (s[i] == 'x') {
				flag3 = 1;
			}
			i++;
		}
		part++;
		switch(count) {
			case 0: {
				shi1[part][0] = 1;
				shi1[part][1] = 1;
				break;
			}
			case 1:{
				if (flag3 == 0) {
					shi1[part][0] = fu == 1 ? -(ch[1] - '0') : ch[1] - '0';
					shi1[part][1] = 0;
				} else {
					shi1[part][0] = flag1 == 1 ? ch[0] - '0' : 1;
					if (fu == 1) {
						shi1[part][0] = -shi1[part][0];
					}
					shi1[part][1] = flag2 == 1 ? ch[1] - '0' : 1;
				}
				break;
			}
			case 2:{
				shi1[part][0] = fu == 1 ? -(ch[0] - '0') : ch[0] - '0';
				shi1[part][1] = ch[1] - '0';
				break;
			}
			default:
				printf("有内鬼，快跑啊！");
		}
	}
	len1 = part;
	/*for (int i = 0; i < part; i++) {
		printf("%d, %d\n",shi1[i][0],shi1[i][1]);
	}*/
	for (int i = 0; i < part + 1; i++) {
		int loc = i;
		int max = shi1[i][1];
		for (int j = i + 1; j < part + 1; j++) {
			if (shi1[j][1] > max) {
				loc = j;
				max = shi1[j][1];
			}
		}
		if (loc != i) {
			int temp0 = shi1[i][0];
			int temp1 = shi1[i][1];
			shi1[i][0] = shi1[loc][0];
			shi1[i][1] = shi1[loc][1];
			shi1[loc][0] = temp0;
			shi1[loc][1] = temp1;
		}

	}
	
}

void sort2(char s[]) {
	int part = -1;
	int i = 0;
	int fu = 0;
	while (s[i] != '\0') {
		if (s[i] == '-') {
			fu = 1;
			i++;
		} else if (s[i] == '+') {
			fu = 0;
			i++;
		}
		int j = 0;
		int count = 0;
		char ch[2];
		int flag1 = 0, flag2 = 0, flag3 = 0;
		while (s[i] != '\0' && s[i] != '+' && s[i] != '-') {
			if (s[i] >= '0' && s[i] <= '9') {
				if (s[i + 1] == 'x') {
					flag1 = 1;
					ch[0] = s[i];
				} else {
					flag2 = 1;
					ch[1] = s[i];
				}
				count++;
			} else if (s[i] == 'x') {
				flag3 = 1;
			}
			i++;
		}
		part++;
		switch(count) {
			case 0: {
				shi2[part][0] = 1;
				shi2[part][1] = 1;
				break;
			}
			case 1:{
				if (flag3 == 0) {
					shi2[part][0] = fu == 1 ? -(ch[1] - '0') : ch[1] - '0';
					shi2[part][1] = 0;
				} else {
					shi2[part][0] = flag1 == 1 ? ch[0] - '0' : 1;
					if (fu == 1) {
						shi2[part][0] = -shi2[part][0];
					}
					shi2[part][1] = flag2 == 1 ? ch[1] - '0' : 1;
				}
				break;
			}
			case 2:{
				shi2[part][0] = fu == 1 ? -(ch[0] - '0') : ch[0] - '0';
				shi2[part][1] = ch[1] - '0';
				break;
			}
			default:
				printf("有内鬼，快跑啊！");
		}
	}
	len2 = part;
	/*for (int i = 0; i < part; i++) {
		printf("%d, %d\n",shi1[i][0],shi1[i][1]);
	}*/
	for (int i = 0; i < part + 1; i++) {
		int loc = i;
		int max = shi2[i][1];
		for (int j = i + 1; j < part + 1; j++) {
			if (shi2[j][1] > max) {
				loc = j;
				max = shi2[j][1];
			}
		}
		if (loc != i) {
			int temp0 = shi2[i][0];
			int temp1 = shi2[i][1];
			shi2[i][0] = shi2[loc][0];
			shi2[i][1] = shi2[loc][1];
			shi2[loc][0] = temp0;
			shi2[loc][1] = temp1;
		}

	}
	
}

void createL1(NODE *L) {
	int i = 0;
	NODE *p = L;
	while (i <= len1) {
		NODE *new_x = (NODE*)malloc(sizeof(struct node));
		new_x->coef = shi1[i][0];
		new_x->exp = shi1[i][1];
		p->next = new_x;
		new_x->next = NULL;
		p = p->next;
		i++;
	}
}

void createL2(NODE *L) {
	int i = 0;
	NODE *p = L;
	while (i <= len2) {
		NODE *new_x = (NODE*)malloc(sizeof(struct node));
		new_x->coef = shi2[i][0];
		new_x->exp = shi2[i][1];
		p->next = new_x;
		new_x->next = NULL;
		p = p->next;
		i++;
	}
}

void multiplication(NODE *head1, NODE *head2, NODE *head3) {
	NODE *p1 = head3;
	NODE *h1 = head1->next, *h2 = head2->next;
	while (h1) {
		while (h2) {
			int coef = h1->coef * h2->coef;
			int exp = h1->exp + h2->exp;
			NODE *new_x = (NODE*)malloc(sizeof(struct node));
			new_x->coef = coef;
			new_x->exp = exp;
			p1->next = new_x;
			new_x->next = NULL;
			p1 = p1->next;
			h2 = h2->next;
		}
		h1 = h1->next;
		h2 = head2->next;
	}
	return;
}

void print(NODE *L) {
	NODE *p = L->next;
	while (p != NULL) {
		printf("(%dx^%d)", p->coef, p->exp);
		p = p->next;
		if (p != NULL) {
			printf(" + ");
		}
	}
	printf("\n");
}

int main() {
	char s1[100];
	char s2[100];
	printf("第1个多项式：\n");
	printf(" 排序前多项式：");
	scanf("%s", s1);
	sort1(s1);
	printf(" 排序后多项式:");
	for (int i = 0; i <= len1; i++) {
		printf("(%dx^%d)", shi1[i][0], shi1[i][1]);
		if (i != len1) {
			printf(" + ");
		}
	}
	printf("\n");
	NODE *L1 = (NODE*)malloc(sizeof(struct node));
	L1->next = NULL;
	createL1(L1);
	printf("第2个多项式：\n");
	printf(" 排序前多项式：");
	scanf("%s", s2);
	sort2(s2);
	printf(" 排序后多项式:");
	for (int i = 0; i <= len2; i++) {
		printf("(%dx^%d)", shi2[i][0], shi2[i][1]);
		if (i != len2) {
			printf(" + ");
		}
	}
	printf("\n");
	NODE *L2 = (NODE*)malloc(sizeof(struct node));
	L2->next = NULL;
	createL2(L2);
	NODE *L3 = (NODE*)malloc(sizeof(struct node));
	L3->next = NULL;
	multiplication(L1, L2, L3);
	//printf("相乘结果：");
	//print(L3);
	printf("按指数排序后：");
	int len3 = len1 * len2;
	NODE *p = L3;
	while (p->next != NULL) {
		int max = p->next->exp;
		NODE *q = p->next;
		NODE *keep = p;
		while (q->next != NULL) {
			int x = q->next->exp;
			if (x > max) {
				max = x;
				keep = q;
			}
			q = q->next;
		}
		if (keep != p) {
			NODE *k1 = keep->next;
			NODE *k2 = p->next;
			NODE *k3 = k1->next;
			NODE *k4 = k2->next;
			p->next = k1;
			k1->next = k4;
			keep->next = k2;
			k2->next = k3;
		}
		p = p->next;
	} 
	print(L3);
}