#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// r (<) w(>) a(>>)
// t (text) b (binar)
// + (optional, both operations)

int main() {
	FILE *intxt = fopen("fisiere/filein.txt", "rt");
	if (intxt == NULL) {
		exit(1);
	}
	fseek(intxt, 0, SEEK_END);
	printf("%ld\n", ftell(intxt));
	fseek(intxt, 0, SEEK_SET);
	fpos_t *ptr = malloc(sizeof(fpos_t));
	char c;
	fgetpos(intxt, ptr);
	fscanf(intxt, "%c", &c);
	printf("%c\n", c);
	fsetpos(intxt, ptr);
	FILE *outtxt = fopen("fisiere/fileout.txt", "at");
	if (outtxt == NULL) {
		fclose(intxt);
		exit(1);
	}
	char buffer[100];
	while (fgets(buffer, 99, intxt)) {
		fprintf(outtxt, "%s", buffer);
	}
	/*
	fprintf(); - scrie intr-un fisier text
	fscanf(); - citeste dintr-un fisier text
	fwrite(); - scrie intr-un fisier binar
	fread(); - citeste dintr-un fisier binar
	*/
	fclose(intxt);
	fclose(outtxt);
	FILE *inbin = fopen("fisiere/filein.bin", "rb");
	if (inbin == NULL) {
		exit(1);
	}
	FILE *outbin = fopen("fisiere/fileout.bin", "wb");
	if (outbin == NULL) {
		fclose(inbin);
		exit(1);
	}
	int vect[10];
	fread(vect, sizeof(int), 2, inbin);
	printf("%x %x\n", vect[0], vect[1]);
	for (int i = 2; i < 10; i++) {
		vect[i] = i;
	}
	fwrite(vect, sizeof(int), 10, outbin);
	fclose(inbin);
	fclose(outbin);
	// stdin - 0
	// stdout - 1
	// stderr - 2
	int n;
	fscanf(stdin, "%d", &n); // scanf("%d", &n);
	fprintf(stdout, "%d\n", n); // printf("%d\n", n);
	fprintf(stderr, "%d\n", n);
	fprintf(stdout, "Hello");
	// compileaza si fara fflush(stdout);
	fflush(stdout);
	while(1) {
		;
	}
	return 0;
}
