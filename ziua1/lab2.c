#include <stdio.h>

int fibo_recursiv(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fibo_recursiv(n - 1) + fibo_recursiv(n - 2);
}

int fibo_iter(int n) {
	int sum = 1;
	int prec = 0;
	while(n > 1) {
		int tmp = sum;
		sum += prec;
		prec = tmp;
		n--;
	}
	return sum;
}

// tip_return nume_func(tip_param1 param1, tip_param2 param2)

void func(int n) {
	if (n == 11) {
		return;
	}
	n++;
	static int i = 3;
	printf("%d\n", i);
	i++;
	printf("%d\n", n);
}

int main() {
	printf("%d\n", fibo_iter(35));
	printf("%d\n", fibo_recursiv(35));
	int n = 10;
	func(n);
	n++;
	func(n);
	n++;
	func(n);
	printf("%d\n", n);
	return 0;
}