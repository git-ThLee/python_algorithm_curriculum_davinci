#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main() {
	while (1) {
		char str[103] = { 0 }; 
		fgets(str, 103, stdin);
		if (!strcmp(str, ".\n")) 
			break;
		stack<char> stk;
		int len = strlen(str);
		bool check = true;
		for (int i = 0; i < len; i++) {
			if (str[i] == '(') 
				stk.push('(');
			else if (str[i] == '[') 
				stk.push('[');
			else if (str[i] == ')') {
				if (stk.empty()) {
					check = false;
					break;
				}
				else if (stk.top() != '(') {
					check = false;
					break;
				}
				else 
					stk.pop();
			}
			else if (str[i] == ']' ){
				if (stk.empty()) {
					check = false;
					break;
				}
				else if (stk.top() != '[') {
					check = false;
					break;
				}
				else 
					stk.pop();
			}
		}
		if (!stk.empty()) 
			check = false;
		if (check) 
			printf("yes\n");
		else 
			printf("no\n");
	}
}