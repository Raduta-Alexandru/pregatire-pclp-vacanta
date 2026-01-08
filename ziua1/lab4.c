#include <stdio.h>

void increment(int *n) {
	(*n)++;
}

void read_vect(int *v, int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", v + i);
	}
}

void write_vect(int *v, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(v + i));
	}
	printf("\n");
}

int main() {
	int n = 10;
	printf("%d\n", n);
	int *p = &n;
	// tip_variabila *nume_variabila = adresa;
	// * - dereferentiere
	*p = 3;
	// & - referentiere
	printf("%d\n", n);
	printf("%p\n", p);
	p++;
	printf("%p\n", p);
	p++;
	printf("%p\n", p);
	printf("-----\n");
	char c = 3;
	char *p2 = &c;
	printf("%p\n", p2);
	p2++;
	printf("%p\n", p2);
	p2++;
	printf("%p\n", p2);
	printf("-----\n");
	n = 10;
	printf("%d\n", n);
	increment(&n);
	printf("%d\n", n);
	printf("-----\n");
	int v[10];
	// [][][][][][][][][][]
	// v[0] <-> *v <=> v <-> &v[0]
	// v[1] <-> *(v + 1)
	read_vect(v, 10);
	write_vect(&v[0], 10);
	return 0;
}
