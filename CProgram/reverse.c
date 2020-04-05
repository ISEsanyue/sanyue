#include <stdio.h>
#include <stdlib.h>

char res[1000];
int topr = -1;

void reverse(char s[], int top) {
	if (top < 0) {
		return;
	} else {
		topr++;
		res[topr] = s[top];
		top--;
		reverse(s, top);
	}
}

int main() {
	char s[1000];
	scanf("%s", s);
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	reverse(s, i - 1);
	printf("%s", res);
	return 0;
}