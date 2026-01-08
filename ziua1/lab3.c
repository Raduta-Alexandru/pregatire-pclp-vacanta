#include <stdio.h>
#include <stdlib.h>

int compar_int(const void* a, const void* b) {
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	return num1 - num2;
}

int binary_search(int v[], int n, int k) {
	int l = 0;
	int r = n - 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if (v[mid] == k) {
			return mid;
		} else if (v[mid] > k) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return -1;
}

void read_array(int v[], int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
}

int main() {
	int v[10];
	// v[0] -> v[99]
	// tip nume[lungime]
	read_array(v, 10);
	qsort(v, 10, sizeof(int), compar_int);
	for (int i = 0; i < 10; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
	printf("%d\n", binary_search(v, 10, 3));

	// tip nume[lungime1][lungime2]

	int n, m;
	scanf("%d%d", &n, &m);
	int mat[n][m];
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = c++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
