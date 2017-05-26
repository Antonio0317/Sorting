#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

class Quick_sort {
private:
	string* input;
public:
	Quick_sort(int);
	~Quick_sort();
	void set_input(int index, string data);
	string get_input(int index);
	void swap(string* A, string* B);
	int partition(int left, int right);
	void sort(int left, int right);
};

Quick_sort::Quick_sort(int line) {
	input = new string[line+1];
}

Quick_sort::~Quick_sort() {
	delete[] input;
}

void Quick_sort::set_input(int index, string data) {
	input[index] = data;
}

string Quick_sort::get_input(int index) {
	return input[index];
}

void Quick_sort::swap(string* A, string* B) {
	string tmp = *A;
	*A = *B;
	*B = tmp;
}

int Quick_sort::partition(int left, int right) {
	int first = left;
	string pivot = input[first];

	left++;

	while(left <= right) {
		while(input[left].compare(pivot) <= 0 && left < right) {
			left++;
		}
		while(input[right].compare(pivot) > 0 && left <= right) {
			right--;
		}
		if(left < right) {
			swap(&input[left], &input[right]);
		}
		else 
			break;
	}
	swap(&input[first], &input[right]);
	return right;
}

void Quick_sort::sort(int left, int right) {
	if(left < right) {
		int index = partition(left, right);

		sort(left, index-1);
		sort(index+1, right);
	}
}

int main() {
	string buf, tmp;
	int line = 0;
	while (getline(cin, tmp)) {
		buf += tmp;
		buf += "\n";
		line++;
	}
	Quick_sort quick(line);
	buf= buf.substr(0, buf.length()-1);
	istringstream iss(buf);
	for(int i = 0; getline(iss, tmp); i++) {
		quick.set_input(i, tmp);
	}
	quick.sort(0, line-1);
	for (int i = 0; i<line; i++) {
		cout << quick.get_input(i) << endl;
	}
}
