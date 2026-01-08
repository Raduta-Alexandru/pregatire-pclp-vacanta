#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	int ***mat = malloc(x * sizeof(int **));
	if (mat == NULL) {
		exit(1);
	}
	for (int i = 0; i < x; i++) {
		mat[i] = malloc(y * sizeof(int *));
		if (mat[i] == NULL) {
			for (int j = 0; j < i; j++) {
				free(mat[j]);
			}
			free(mat);
			exit(1);
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			mat[i][j] = malloc(z * sizeof(int));
			if (mat[i][j] == NULL) {
				for (int k = 0; k < j; k++) {
					free(mat[i][k]);
				}
				for (int k = 0; k < i; k++) {
					for (int l = 0; l < y; l++) {
						free(mat[k][l]);
					}
					free(mat[k]);
				}
				free(mat[i]);
				free(mat);
				exit(1);
			}
		}
	}
}
