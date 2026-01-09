#include <stdlib.h>
#include <stdio.h>

int* my_int_calloc(int n) {
	int *vect = calloc(n, sizeof(int));
	return vect;
}

int* my_int_realloc(int *v, int new_size, int old_size) {
	int *new_vect = malloc(new_size * sizeof(int));
	int pos = 0;
	while(pos < new_size && pos < old_size) {
		new_vect[pos] = v[pos];
		pos++;
	}
	free(v);
	return new_vect;
}

void read_vect(int *v, int n) {
	for(int i = 0; i < n; i++) {
		v[i] = i;
	}
}

void write_vect(int *v, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void free_mat(int **v, int n) {
	for (int i = 0; i < n; i++) {
		free(v[i]);
	}
	free(v);
}

int main() {
	int n;
	scanf("%d", &n);
	int *v = my_int_calloc(n);
	write_vect(v, n);
	read_vect(v, n);
	write_vect(v, n);
	free(v);
	int **mat = malloc(10 * sizeof(int*));
	for(int i = 0; i < 10; i++) {
		mat[i] = malloc(10 * sizeof(int));
	}
	free_mat(mat, 10);
	return 0;
}
