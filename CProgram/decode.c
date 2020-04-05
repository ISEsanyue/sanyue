#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[50];
	char out[50];
	scanf("%s", s);
	char tablet[28];
	for (int j = 0; j < 26; j++) {
		tablet[j] = j + 'a';
	}
	tablet[26] = '_';
	int i = 0;
	while (s[i] != '\0') {
		int shift;
		if (s[i] == '_') {
			shift = 26;
		} else {
			shift = s[i] - 'a';
		}
		int num = shift * 4 + 15;
		num = num % 27;
		if (num == 26) {
			out[i] = '_';
		} else {
			num = num + 'a';
			out[i] = num;
		}
		i++;
	}
	out[i] = '\0';
	printf("%s", out);
}