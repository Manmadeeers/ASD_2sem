#include <iostream>
#include <stack>
#include <string>
#define WRONG "Breckets are in the wrong order"
#define RIGHT "Brackets are in correct order"
using namespace std;

void main()
{
	string str_to_check;
	cout << "Enter the symbol string: ";
	cin.ignore(cin.rdbuf()->in_avail());//clear buffer
	getline(cin,str_to_check);
	stack<char>symbol_stack;
	int str_length = str_to_check.length();
	for (int i = 0; i < str_length; i++) {
		if (str_to_check[i] == '[' || str_to_check[i] == '(' || str_to_check[i] == '{') {
			symbol_stack.push(str_to_check[i]);
		}
		if (str_to_check[i] == ']') {
			if (symbol_stack.top() != '[') {
				cout << WRONG<< endl;
				return;
			}
			symbol_stack.pop();
		}
		else if (str_to_check[i] == ')') {
			if (symbol_stack.top() != '(') {
				cout << WRONG << endl;
				return;
			}
			symbol_stack.pop();
		}
		else if (str_to_check[i] == '}') {
			if (symbol_stack.top() != '{') {
				cout << WRONG << endl;
				return;
			}
			symbol_stack.pop();
		}
	}
	if (!symbol_stack.empty()) {
		cout << WRONG << endl;
		return;
	}
	cout << RIGHT << endl;

	
}