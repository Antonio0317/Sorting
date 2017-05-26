#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <time.h>

using namespace std;

class Merge_sort {
private:
	string* input;
public:
	Merge_sort(int);
	~Merge_sort();
	void set_input(int index, string data);
	string get_input(int index);
	void merge(int low, int mid, int high);
	void sort(int low, int high);
};

Merge_sort::Merge_sort(int line) {
	input = new string[line+1];
}

Merge_sort::~Merge_sort() {
	delete[] input;
}

void Merge_sort::set_input(int index, string data) {
	input[index] = data;
}

string Merge_sort::get_input(int index) {
	return input[index];
}

void Merge_sort::merge(int low, int mid, int high) {
	int i = low;
	int j = mid+1;
	int k = low;
	string* buffer = new string[high+1];
	while (i <= mid && j <= high) {
		if (input[i].compare(input[j]) < 0) {
			buffer[k] = input[i];
			i++;
		}
		else {
			buffer[k] = input[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int l = 0; l<= high -j; l++) {
			buffer[k+l] = input[j+l];
		}
	}
	else {
		for(int l = 0; l<=mid-i; l++) {
			buffer[k+l] = input[i+l];
		}
	}
	for(int l = 0; l<=high-low; l++) {
		input[low+l] = buffer[low+l];
	}
	delete[] buffer;
}

void Merge_sort::sort(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		sort(low, mid);
		sort(mid+1, high);
		merge(low, mid, high);
	}
}

int main() {
	clock_t start, end;
	start=clock();
	string buf, tmp;
	int line = 0;
	while (getline(cin, tmp)) {
		buf += tmp;
		buf += "\n";
		line++;
	}
	Merge_sort merge(line);
	buf= buf.substr(0, buf.length()-1);
	istringstream iss(buf);
	for(int i = 0; getline(iss, tmp); i++) {
		merge.set_input(i, tmp);
	}
	merge.sort(0, line-1);
	end =clock();
	for (int i = 0; i<line; i++) {
		cout << merge.get_input(i) << endl;
	}
	cout << (double)(end-start)/CLOCKS_PER_SEC << endl;		
}
