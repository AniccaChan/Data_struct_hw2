#include <iostream>
#include <sstream>
#include <stack>
using namespace std;
int main() {
	string str;
	stack<char> test;
	char temp;
	getline(cin, str);
	stringstream ss(str);
	while (ss) {
		ss >> temp;
		test.push(temp);
	}
	while (! test.empty()) {
		test.pop();
	}
}