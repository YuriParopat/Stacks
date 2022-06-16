#include <stdio.h>
#include <stdlib.h>

#pragma once

using namespace std;

class Util {
public:
	Util() {}
	int ScanNum(char ch) {
		int value;
		value = ch;
		return int(value - '0');
	}

	int IsOperator(char ch) {
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			return 1;
		return -1;
	}
	int IsDigit(char ch) {
		if (ch >= '0' && ch <= '9')
			return 1;
		return -1;
	}


	float Operation(int a, int b, char op) {
		float result = 0;
		switch (op)
		{
		case '+':
			return b + a;
			break;
		case '-':
			return b - a;
			break;
		case '*':
			return b * a;
			break;
		case '/':
			if (a== 0) {
				printf("\nERRO: Divisão por zero não permitida.");
				return _I32_MIN;
				break;
			}
			result = b /(float)a;
			return result;
			break;
		default:
			return _I32_MIN;
			break;
		}

	}

};

