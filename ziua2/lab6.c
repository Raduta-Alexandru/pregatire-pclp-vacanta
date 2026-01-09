#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_string(const void *a, const void *b) {
	char **str1 = (char**)a;
	char **str2 = (char**)b;
	return strcmp(*str1, *str2);
}

char *my_strdup(char *og_string) {
	int len = strlen(og_string);
	char *new_string = malloc(len + 1);
	strcpy(new_string, og_string);
	return new_string;
}

int main() {
	char buffer[100];
	buffer[0] = 72;
	buffer[1] = 0x65;
	buffer[2] = 'l';
	buffer[3] = 'l';
	buffer[4] = 'o';
	buffer[5] = ' ';
	buffer[6] = '\0';
	char world[] = "World!";
	printf("%s%s\n", buffer, world);
	printf("%ld\n", strlen(buffer));
	if (strcmp(buffer, world) == 0) {
		printf("Sunt egale\n");
	} else {
		printf("Nu sunt egale\n");
	}
	char **mat = malloc(5 * sizeof(char*));
	mat[0] = strdup("AE");
	mat[1] = strdup("BB");
	mat[2] = strdup("AD");
	mat[3] = strdup("AA");
	mat[4] = strdup("AF");
	qsort(mat, 5, sizeof(char *), compare_string);
	for (int i = 0; i < 5; i++) {
		printf("%s\n", mat[i]);
		free(mat[i]);
	}
	free(mat);

	char *string = malloc(100);
	string[0] = 0; // sa gaseasca strcat un \0
	strcat(string, buffer);
	printf("%s\n", string);
	strcat(string, world);
	printf("%s\n", string);
	strcat(string, " from Alex");
	printf("%s\n", string);

	char *o = strchr(string, 'o');
	printf("%s\n", o);

	char *ll = strstr(string, "ll");
	printf("%s\n", ll);

	char *first = strtok(string, " ");
	while(first != NULL) {
		printf("%s\n", first);
		first = strtok(NULL, " ");
	}
	free(string);
	int size = 100;
	int pos = 0;
	char *new_string = malloc(size * sizeof(char));
	char c;
	scanf("%c", &c);
	while(c != '\n') {
		if (size == pos) {
			size *= 2;
			char *tmp = realloc(new_string, size);
			if (tmp == NULL) {
				exit(1);
			}
			new_string = tmp;
		}
		new_string[pos++] = c;
		scanf("%c", &c);
	}
	if (size == pos) {
		size += 1;
		char *tmp = realloc(new_string, size);
			if (tmp == NULL) {
				exit(1);
			}
		new_string = tmp;
	}
	new_string[pos] = '\0';
	printf("%s\n%d\n", new_string, size);
	free(new_string);
	return 0;
}
