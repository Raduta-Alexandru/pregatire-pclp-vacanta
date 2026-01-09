#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bugetare {
	Buget,
	Taxa,
	Special = 101
}TBuget;

union value {
	long intreg;
	double real;
};

union uniune {
	int n;
	short s;
	char c;
};

struct struct1 {
	char c; // 1
	long l; // 8
	int d; // 4
	char u; // 1
	short s; // 2
}; // 24

struct struct2 {
	long l; // 8
	int d; // 4
	char c; // 1
	char u; // 1
	short s; // 2
}; // 16

typedef struct student {
	char *nume; // 8
	char grupa[6]; // 6
	float medie; // 4
	int an; // 4
	TBuget bugetare;
}TStudent; // 24

TStudent *init_student(char *nume, char *grupa, float medie, int an, TBuget bugetare) {
	TStudent *this = malloc(sizeof(TStudent));
	if (this == NULL) {
		return NULL;
	}
	this->nume = strdup(nume);
	if (this->nume == NULL) {
		free(this);
		return NULL;
	}
	strncpy(this->grupa, grupa, 5);
	this->grupa[5] = 0; // strncpy nu adauga \0
	this->medie = medie;
	this->an = an;
	this->bugetare = bugetare;
	return this;
}

void print_student(TStudent *this) {
	if (this == NULL) {
		return;
	}
	printf("%s %s %.1f %d ", this->nume, this->grupa, this->medie, this->an);
	if (this->bugetare == Buget) {
		printf("si este la buget\n");
	} else {
		printf("si este la taxa\n");
	}
}

void copy_student(TStudent *dest, TStudent *src) {
	if (dest == NULL) {
		return;
	}
	if (src == NULL) {
		return;
	}
	free(dest->nume);
	dest->nume = strdup(src->nume);
	strcpy(dest->grupa, src->grupa);
	dest->medie = src->medie;
	dest->an = src->an;
	dest->bugetare = src->bugetare;
}

void free_student_with_null(TStudent **this) {
	free((*this)->nume);
	free(*this);
	*this = NULL;
}

void free_student(TStudent *this) {
	free(this->nume);
	free(this);
}

int main() {
	struct student student1;
	student1.nume = strdup("Alex");
	strcpy(student1.grupa, "324CB");
	student1.medie = 5;
	student1.an = 2;
	printf("%s %s %.1f %d\n", student1.nume, student1.grupa, student1.medie, student1.an);
	printf("%ld\n", sizeof(struct student));
	printf("%ld\n", sizeof(struct struct1));
	printf("%ld\n", sizeof(struct struct2));
	free(student1.nume);
	student1.nume = malloc(100);
	strcpy(student1.nume, "Alexandru");
	printf("%s %s %.1f %d\n", student1.nume, student1.grupa, student1.medie, student1.an);
	TStudent student2;
	student2.nume = strdup("Daniel");
	strcpy(student2.grupa, "324CB");
	student2.medie = 10;
	student2.an = 2;
	printf("%s %s %.1f %d\n", student2.nume, student2.grupa, student2.medie, student2.an);
	TStudent *stud3 = malloc(sizeof(TStudent));
	stud3->nume = strdup("Maria");
	strcpy(stud3->grupa, "315CB");
	stud3->medie = 9;
	stud3->an = 1;
	printf("%s %s %.1f %d\n", stud3->nume, stud3->grupa, stud3->medie, stud3->an);
	TStudent *stud4 = init_student("Teo", "313CC", 9.5, 1, Taxa);
	if (stud4 == NULL) {
		exit(1);
	}
	print_student(stud4);
	print_student(NULL);
	TStudent *stud5 = malloc(sizeof(TStudent));
	copy_student(stud5, stud4);
	print_student(stud5);
	TStudent *stud6 = stud4;
	print_student(stud6);
	stud4->medie = 8.5;
	print_student(stud6);
	print_student(stud5);
	free_student(stud3);
	stud3 = NULL;
	free_student(stud4);
	stud4 = NULL;
	stud6 = NULL;
	free_student_with_null(&stud5);
	free(student1.nume);
	free(student2.nume);
	TStudent *stud7 = init_student("Mario", "343C3", 10, 4, Buget);
	print_student(stud7);
	free_student(stud7);
	printf("%d\n", Buget);
	printf("%d\n", Taxa);
	printf("%d\n", Special);
	union uniune u1;
	u1.n = 0x12345678;
	printf("%d\n", u1.s);
	return 0;
}
