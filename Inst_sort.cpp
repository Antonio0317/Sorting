#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <time.h>

using namespace std;

class Insertion_sort {
	private:
		string* input;
	public:
		Insertion_sort();
		~Insertion_sort();
		void set_input(int index, string data);
		string get_input(int index);
		void sort(int len);
};

Insertion_sort::Insertion_sort() {
	input = new string[5000000];
}

Insertion_sort::~Insertion_sort() {
	delete[] input;
}

void Insertion_sort::set_input(int index, string data) {
	input[index] = data;
}

string Insertion_sort::get_input(int index) {
	return input[index];
}

void Insertion_sort::sort(int len) {
	string buf = "";
	for(int i = 1; i<len; i++) {
		if(input[i-1].compare(input[i]) <= 0) {
			continue;
		}
		buf = input[i];
		for(int j = 0; j<i; j++) {
			if(input[j].compare(buf) > 0) {
				string tmp = input[j];
				for(int k = 0; k < i-j; k++) {
					input[j] = input[j+1+k];
					input[j+1+k] = tmp;
					tmp = input[j];
				}
				input[j] = buf;
				break;
			}
		}
	}
}

int main () {
	clock_t start, end;
	start = clock();
	Insertion_sort inst;
	string buf;
	int line = 0;
	for(int i = 0; getline(cin, buf); i++) {
		inst.set_input(line, buf);
		line++;
	}
	inst.sort(line);
	end = clock();
	for(int i = 0; i<line; i++) {
		cout << inst.get_input(i) << endl;
	}
	cout << (double)(end-start)/CLOCKS_PER_SEC << endl;
}
