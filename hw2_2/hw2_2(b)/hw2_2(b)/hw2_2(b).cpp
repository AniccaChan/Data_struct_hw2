#include <iostream>
#include <sstream>
#include <deque>
#include <set>
using namespace std;
stringstream read() {
	string temp;
	stringstream ss;
	getline(cin, temp);
	ss.str(temp);
	return ss;
}

void prefix() {
	deque<string> Prefix;
	deque<string> pus;
	deque<string> pus_i;
	string temp;
	stringstream ss = read();
	set<char> sym;
	sym.insert({ '*', '/', '+', '-' });
	while (ss >> temp) {
		if (sym.count(temp[0])) {
			if ((temp == "*" or temp == "/") && (Prefix.front() == "+" or Prefix.front() == "-")) {
				pus.push_back(temp);
				pus.push_back(Prefix.back());
				Prefix.pop_back();
				ss >> temp;
				pus.push_back(temp);
				Prefix.push_back("flag");
				continue;
			}
			Prefix.push_front(temp);
		}
		else
			if (temp[0] == '(') {
				Prefix.push_back("flag");
				while (ss >> temp && temp[0]!=')') {
					if (sym.count(temp[0])) {
						if ((temp == "*" or temp == "/") && (pus.front() == "+" or pus.front() == "-")) {
							pus_i.push_back(temp);
							pus_i.push_back(pus.back());
							pus.pop_back();
							ss >> temp;
							pus_i.push_back(temp);
							pus.push_back("flag");
							continue;
						}
						pus.push_front(temp);
					}
					else
					{
						pus.push_back(temp);
					}
				}
			}else
		{
			Prefix.push_back(temp);
		}
	}
	while (!Prefix.empty()) {
		{
			if (Prefix.front() == "flag") {
				for (int i = 0; i < 3; i++) {
					if (pus.front() == "flag") {
						for (int i = 0; i < 3; i++) {
							cout << pus_i.front() + " ";
							pus_i.pop_front();
						}
						continue;
					}
					cout << pus.front() + " ";
					pus.pop_front();
				}
				Prefix.pop_front();
				continue;
			}
			cout << Prefix.front() + " ";
			Prefix.pop_front();
		}
	}
	
}
int main()
{
	while (1) {
		prefix();
	}

}
