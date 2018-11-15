#include <iostream>
#include <sstream>
using namespace std;

class queue {
private:
	int _len = 0;
	int * _array;	
public:
	void push_front(int i) {
		if (_len) {
			int *temp = new int[_len + 1];
			temp[0] = i;
			memcpy(temp + 1, _array, (_len + 1) * 4);
			_array = new int[_len + 1];
			memcpy(_array, temp, (_len + 1) * 4);
			_len++;
		}
		else {
			_array = new int[1];
			_array[0] = i;
			_len++;
		}
	}
	void push_back(int i) {
		if (_len) {
			int * temp = new int[_len + 1];
			temp[_len] = i;
			memcpy(temp, _array, _len * 4);
			_array = new int[_len + 1];
			memcpy(_array, temp, 4 * (_len + 1));
			_len++;
		}
		else {
			_array = new int[1];
			_array[0] = i;
			_len++;
		}
	}
	int pop_front() {
		if (!_len) {
			cout << "No more to pop" << endl;
			return -1;
		}
		int num = _array[0];
		int *temp = new int[_len - 1];
		memcpy(temp, _array + 1, 4 * (_len - 1));
		_array = new int[_len - 1];
		memcpy(_array, temp, 4 * (_len - 1));
		_len--;
		return num;
	}
	int pop_back() {
		if (!_len) {
			cout << "No more to pop" << endl;
			return -1;
		}
		int num = _array[_len-1];
		_len--;
		return num;
	}
	void show() {
		for (int i = 0; i < _len; i++) {
			cout << _array[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	queue hw;
	for (int i = 0; i <= 50; i++) {
		int j;
		string str;
		string instr;
		getline(cin, str);
		stringstream ss(str);
		ss >> instr;
		if (instr == "push_front") {
			int temp;
			ss >> j;
			hw.push_front(j);
			continue;
		}
		if (instr == "push_back") {
			int temp;
			ss >> j;
			hw.push_back(j);
			continue;
		}
		if (instr == "pop_front") {
			hw.pop_front();
			continue;
		}
		if (instr == "pop_back") {
			hw.pop_back();
			continue;
		}
		if (instr == "show") {
			hw.show();
			continue;
		}
		cout << "invalid instruction" << endl;
	}
}
