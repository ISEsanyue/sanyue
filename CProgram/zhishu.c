#include <stdio.h>
#include <stdlib.h>

int main() {
	int num[10000];
	for (int k = 0; k < 10000; k++) {
		num[k] = 0;
	}
	num[1] = 1;
	int keep;
	int bei;
	int loc;
	int zhi[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	for (int i = 0; i < 25; i++) {
		keep = zhi[i];
		bei = 10000 / zhi[i];
		for (int j = zhi[i]; j <= bei; j++) {
			loc = keep * j;
			if (loc < 10000 && num[loc] != 1) {
				num[loc] = 1;
			}
		}
	}
	int ans = 0;
	for (int k = 2; k < 10000; k++) {
		if (num[k] == 0) {
			printf("%d ", k);
			ans = ans + k;
		}
	}
	printf("\n");
	printf("%d\n", ans);
}