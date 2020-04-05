#include<stdio.h>
#include<string.h>
int main() {
	char s[100];
	scanf("%s", s);
	int i = 0;
	while(s[i] != '\0') {
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			int j = (s[i] - 'A' > 26 ? s[i] - 'a' : s[i] - 'A') + 13;
			j = j % 26;
			s[i] = j + (s[i] - 'A' > 26 ? 'a' : 'A');
		}
		i++;
	}
	printf("%s\n", s);
	return 0;
}

