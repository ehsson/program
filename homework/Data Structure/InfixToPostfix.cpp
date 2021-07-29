#include <iostream>
#include <cstring>
#include <cctype>
#include "ListBaseStack.h"
using namespace std;

int getOpPrec(char op)
{
	switch (op) {
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
		return 1;
	default:
		break;
	}

	return -1;
}

int whoPrecOp(char op1, char op2)
{
	int op1Prec = getOpPrec(op1);
	int op2Prec = getOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void convToRPNExp(char exp[])
{
	Stack stack;
	int explen = strlen(exp);
	char* convExp = new char[explen + 1];

	int idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * explen + 1);
	stackInit(&stack);

	for (int i = 0; i < explen; i++) {
		tok = exp[i];
		if (isdigit(tok))
			convExp[idx++] = tok;
		else {
			switch (tok) {
			case '(':
				SPush(&stack, tok);
				break;
			case ')':
				while (true) {
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (!SIsEmpty(&stack) && whoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;
			default:
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy_s(exp, explen + 1, convExp);

	delete convExp;
}
