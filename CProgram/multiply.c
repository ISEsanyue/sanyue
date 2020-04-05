#include <stdio.h>
#include <stdlib.h>

int shi1[30][3];
int shi2[30][3];
int len1 = 0;
int len2 = 0;
int result[1000][3];

void sort1(char s[]) {
	int part = 0;
	int i = 0;
	int fu = 0;
	while (s[i] != '\0') {
		if (s[i] == '-') {
			fu = 1;
		}
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;
		if (s[i] >= '0' && s[i] <= '9') {
			int x = s[i] - '0';
			i++;
			while (s[i] != '\0' && s[i] != '+' && s[i] != '-') {
				flag = 1;
				if (s[i] == 'x') {
					flag1 = 1;
					shi1[part][0] = fu == 1 ? -x : x;
					fu = 0;
				}
				if (s[i] >= '0' && s[i] <= '9') {
					flag2 = 1;
					shi1[part][1] = s[i] - '0';
				}
				i++;
			}
			if (flag == 1 && s[i] == '\0' && s[i] == '+' && s[i] == '-') {
				i--;
			}
			if (flag1 == 0) {
				shi1[part][0] = fu == 1 ? -x : x;
				fu = 0;
				shi1[part][1] = 0;
			} else if (flag2 == 0) {
				shi1[part][1] = 1;
			}
			part++;
		}
		i++;
	}
	len1 = part - 1;
	/*for (int i = 0; i < part; i++) {
		printf("%d, %d\n",shi1[i][0],shi1[i][1]);
	}*/
	for (int i = 0; i < part; i++) {
		int loc = i;
		int max = shi1[i][1];
		for (int j = i + 1; j < part; j++) {
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
	int part = 0;
	int i = 0;
	int fu = 0;
	while (s[i] != '\0') {
		if (s[i] == '-') {
			fu = 1;
		}
		int flag1 = 0;
		int flag2 = 0;
		if (s[i] >= '0' && s[i] <= '9') {
			int x = s[i] - '0';
			i++;
			while (s[i] != '\0' && s[i] != '+' && s[i] != '-') {
				if (s[i] == 'x') {
					flag1 = 1;
					shi2[part][0] = fu == 1 ? -x : x;
					fu = 0;
				} else if (s[i] >= '0' && s[i] <= '9') {
					flag2 = 1;
					shi2[part][1] = s[i] - '0';
				}
				i++;
			}
			if (s[i] == '\0' || s[i] == '+' || s[i] == '-') {
				i--;
			}
			if (flag1 == 0) {
				shi2[part][0] = fu == 1 ? -x : x;
				fu = 0;
				shi2[part][1] = 0;
			} else if (flag2 == 0) {
				shi2[part][1] = 1;
			}
			part++;
		}
		i++;
	}
	len2 = part - 1;
	/*for (int i = 0; i < part; i++) {
		printf("%d, %d\n",shi1[i][0],shi1[i][1]);
	}*/
	for (int i = 0; i < part; i++) {
		int loc = i;
		int max = shi2[i][1];
		for (int j = i + 1; j < part; j++) {
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
}