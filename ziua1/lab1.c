#include <stdio.h>

int main() {
	printf("Hello World!\n");
	char c; // 1 byte
	short s; // 2 bytes
	int i; // 4 bytes
	float f;
	double d;
	long l; // 8 bytes
	unsigned char uc; // 1
	unsigned short us; // 2
	unsigned int ui; // 4
	unsigned long ul; // 8
	c = 3;
	s = 100;
	i = 1000;

	if (i == 1000) {
		printf("Este 1000\n");
	}

	c = 0;
	if (c == 0) {
		printf("0");
	} else if (c == 1) {
		printf("1");
	} else {
		printf(">1");
	}
	printf("\n");

	switch (c) {
		case 0:
		printf("0");
		break;
		case 1:
		printf("1");
		break;
		default:
		printf(">1");
		break;
	}
	printf("\n");
	int n = 10;
	i = 0;

	while(i < n) {
		printf("%d ", i);
		i++;
	}

	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", i);
	}

	printf("\n");
	i = 0;
	do {
		printf("%d ", i);
		i++;
	} while (i < n);

	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			continue;
		}
		if (i == 7) {
			break;
		}
		printf("%d ", i);
	}
	printf("\n");

	while(1) {
		scanf("%d", &i);
		if (i == 0) {
			break;
		}
		printf("%d ", i);
	}
	printf("\n");

	n = 10;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (j % 2 == 1) {
				continue;
			}
			if (j == 6) {
				break;
			}
			printf("%d ", j);
		}
		printf("\n");
	}
	goto label1;
	printf("Test\n");
label1:
	printf("label1\n");
	goto label3;
label2:
	printf("label2\n");
label3:

	printf("%ld\n", sizeof(int));	
	printf("%ld\n", sizeof(i));

	int a = 3;
	int b = 3;
	printf("%d %d\n", a--, --b);
	printf("%d %d\n", a, b);

	return 0;
}
