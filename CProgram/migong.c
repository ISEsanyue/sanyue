#include <stdio.h>
#include <stdlib.h>

int minlen = 100;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int path[10][50];
int len[10] = {100,100,100,100,100,100,100,100,100,100};

int map[6][6] = {
	{-1,-1,-1,-1,-1,-1},
	{-1, 0, 0, 0,-1,-1},
	{-1, 0,-1, 0, 0,-1},
	{-1, 0, 0, 0,-1,-1},
	{-1,-1, 0, 0, 0,-1},
	{-1,-1,-1,-1,-1,-1}
};

typedef struct stack{
	int i;
	int j;
	int di;
	int father;
}stack;

void findpath(stack s[100], int top, int count) {
	top = s[top].father;
	int keep[50];
	int z = -1;
	while (s[top].father != -1) {
		z++;
		keep[z] = s[top].di;
		top = s[top].father;
	}
	len[count] = z;
	for (int j = z; j >= 0; j--) {
		path[count][z - j] = keep[j];
	}
}

void dfs(int i, int j, int x, int y) {
	stack s[100];
	int top = -1;
	top++;
	s[top].i = i; s[top].j = j; s[top].di = -1; s[top].father = -1;
	int count = 0;
	while (top >= 0) {
		int flag = 0;
		if (s[top].i == x && s[top].j == y) {
			count++;
			findpath(s, top, count);
			map[x][y] = 0;
			s[top].father = -1;
			top--;
		}
		int xi = s[top].i; int yi = s[top].j; 
		int di = s[top].di;
		for (int i = di + 1; i < 4; i++) {
			int xt = xi + dx[i];
			int yt = yi + dy[i];
			if (map[xt][yt] == 0) {
				map[xt][yt] = 1;
				flag = 1;
				s[top].di = di;
				top++;
				s[top].i = xt; s[top].j = yt; s[top].di = -1; s[top].father = top - 1;
				break;
			}
		}
		if (flag == 0) {
			map[s[top].i][s[top].j] = 0;
			top--;
		}
	}
}

void printpath(int i, int x, int y) {
	int pa[50][2];
	int k = -1;
	for (int j = len[i]; j >= 0; j--) {
		k++;
		pa[k][0] = x - dx[path[i][j]];
		pa[k][1] = y - dy[path[i][j]];
		x = pa[k][0];
		y = pa[k][1];
	}
	printf("(1, 1) ");
	for (int z = k; z >= 0; z--) {
		printf("(%d, %d) ", pa[z][0], pa[z][1]);
	}
	printf("(4, 4)\n");
}

int main() {
	dfs(1, 1, 4, 4);
	for (int i = 0; i < 10; i++) {
		if (len[i] <= minlen) {
			minlen = len[i];
		}
	}
	printf("最短路径为：\n");
	for (int i = 0; i < 10; i++) {
		if (len[i] == minlen) {
			printpath(i, 4, 4);
		}
	}
	printf("最短路径长度:%d\n", minlen + 1);
}