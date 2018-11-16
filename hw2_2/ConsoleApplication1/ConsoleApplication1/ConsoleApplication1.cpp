#include <iostream>
#include <sstream>
#include <stack>
using namespace std;
template <class T>int to_int(T t) {
	int ret;
	stringstream conv;
	conv << t;
	conv >> ret;
	return ret;
}
int* get_two(stack<int>& stac) {
	int a;
	int b;
	a = stac.top();
	stac.pop();
	b = stac.top();
	stac.pop();
	int ret[2] = { a,b };
	return ret;
}
void eval() {
	string str;
	stack<string> get;
	stack<int> number;
	string temp;
	getline(cin, str);
	stringstream ss(str);
	stringstream conv;
	while (ss >> temp) {
		get.push(temp);
	}
	while (!get.empty()) {
		int *temp;
		switch (get.top()[0])
		{
		case '*':
			int *temp;
			temp = get_two(number);
			number.push(temp[0] * temp[1]);
			get.pop();
			break;
		case '/':
			temp = get_two(number);
			number.push((temp[0] / temp[1]));
			get.pop();
			break;
		case '+':
			temp = get_two(number);
			number.push(temp[0] + temp[1]);
			get.pop();
			break;
		case '-':
			temp = get_two(number);
			number.push(temp[0] - temp[1]);
			get.pop();
			break;
		default:
			number.push(to_int(get.top()));
			get.pop();
			break;
		}
	}
	cout << number.top() << endl;
}
int main() {
	while (1) {
		eval();
	}
}