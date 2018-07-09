#include <stdio.h>
#include <stdlib.h>

#define CNT 10000

char arr[125000] = { 0 };
int sto[CNT] = { 0 };

void set_value(int num, int chk)
{
	int mok, rem, temp;

	mok = (int)(num / 8);
	rem = (int)(num % 8);

	if (chk == 1) {
		temp = 0x80 >> rem;
		arr[mok] = arr[mok] | temp;
	}
	else {
		temp = (0x7F >> rem) | (0xFF << (8 - rem));
		arr[mok] = arr[mok] & temp;
	}
}

int get_value(int num)
{
	int mok, rem, temp, im;

	mok = (int)(num / 8);
	rem = (int)(num % 8);

	im = 0x80 >> rem;
	temp = arr[mok] | im;

	if (temp > 0) return 1;

	return 0;
}

int search(int num)
{
	int chk = -1;

	for (int a = 0; a < CNT; a++) {
		if (sto[a] == num) {
			chk = a;
			break;
		}
	}

	return chk;
}

int main(void)
{
	int k = 0, na;

	srand(1);

	while (k < CNT) {
		na = rand() % 1000000;
		if (search(na) == -1) {
			sto[k] = na;
			set_value(na, 1);
			k++;
		}
	}

	return 0;
}