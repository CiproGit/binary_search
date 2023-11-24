#include <iostream>

using namespace std;

bool binary_search(vector<int> vector, int number, unsigned long long from, unsigned long long to) {
	if (from == to) {
		if (number == vector.at(from)) return true;
		else return false;
	}

	unsigned long long middle = from + (to - from + 1) / 2;

	if (number == vector.at(middle)) return true;
	if (number < vector.at(middle)) return binary_search(vector, number, from, middle - 1);
	else return binary_search(vector, number, middle, to);
}

bool is_there(vector<int> vector, int number) {
	unsigned long long size = vector.size();
	if (size == 0) return false;

	return binary_search(vector, number, 0, size - 1);
}

int main(void) {
	cout << "***********************\n";
	cout << "*    BINARY SEARCH    *\n";
	cout << "***********************\n" << endl;

	cout << "Input vector: ";
	vector<int> v = {2, 4, 4, 5, 7, 8, 11, 16, 25, 200};
	for (int i : v) {
		cout << i << " ";
	}

	cout << "\nSearching for number 5...\n" << endl;

	if (is_there(v, 5)) cout << "5 found!\n";
	else cout << "5 not found\n";

	cout << "\nEnd" << endl;
	return EXIT_SUCCESS;
}
