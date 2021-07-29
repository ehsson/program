#include <iostream>
#include <cctype>
#include "ListBaseStack.h"
using namespace std;

int evalRPNExp(char exp[])
{
	Stack stack;
	int explen = strlen(exp);
	char tok, op1, op2;

	stackInit(&stack);

	for (int i = 0; i < explen; i++) {
		tok = exp[i];

		if (isdigit(tok))
			SPush(&stack, tok - '0');
		else {
			op2 = SPop(&stack);
			op1 = SPop(&stack);

			switch (tok) {
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			default:
				break;
			}
		}
	}

	return SPop(&stack);
}
