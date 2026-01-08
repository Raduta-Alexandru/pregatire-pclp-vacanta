#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int *vect = malloc(n * sizeof(int));
	if (vect == NULL) {
		printf("Nu a functionat\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		vect[i] = i;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", vect[i]);
	}
	printf("\n");
	int m, o;
	scanf("%d%d", &m, &o);
	int **mat = malloc(m * sizeof(int *));
	if (mat == NULL) {
		printf("Nu a functionat\n");
		return 0;
	}
	for (int i = 0; i < m; i++) {
		mat[i] = malloc(o * sizeof(int));
		if (mat[i] == NULL) {
			printf("Nu a functionat\n");
			for (int j = 0; j < i; j++) {
				free(mat[j]);
			}
			free(mat);
			return 0;
		}
	}
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < o; j++) {
			mat[i][j] = c++;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < o; j++) {
			printf("%2d ", mat[i][j]);
		}
		printf("\n");
	}
	// lucru cu matricea
	free(vect);
	vect = NULL;
	for (int i = 0; i < m; i++) {
		free(mat[i]);
	}
	free(mat);
	mat = NULL;
	vect = calloc(n, sizeof(int));
	if (vect == NULL) {
		printf("Nu a functionat\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", vect[i]);
	}
	printf("\n");
	scanf("%d", &n);
	int *tmp = realloc(vect, n);
	if (tmp == NULL) {
		free(vect);
		printf("Nu a functionat\n");
		return 0;
	}
	vect = tmp;
	for (int i = 0; i < n; i++) {
		vect[i] = i;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", vect[i]);
	}
	printf("\n");
	free(vect);
	return 0;
}