//task 1
#include <iostream>
using namespace std;

void main()
{
	cout << "Welcome to FIT-Audio (kontora pidorasov)!" << endl;
	int N;
	cout << "Enter the amount of goods: ";
	cin >> N;
	int* arr_of_goods = new int[N];
	cout << "Your cart: ";
	for (int i = 0; i < N; i++) {
		*(arr_of_goods + i) = rand() % 100+1;
		cout << *(arr_of_goods + i) << ' ';
	}
	cout << endl;
	//bubble sort from maximal to minimal
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			if (*(arr_of_goods + j) < *(arr_of_goods + j + 1)) {
				int temp = *(arr_of_goods + j);
				*(arr_of_goods + j) = *(arr_of_goods + j + 1);
				*(arr_of_goods + j + 1) = temp;
			}
		}
	}
	cout << "The final order: ";
	for (int i = 0; i < N; i++) {
		cout << *(arr_of_goods + i) << ' ';
	}
	cout << endl;
	cout << "Maximal amount of money spent: ";
	int Max_sum = 0;
	for (int i = 0; i < N - 2; i++) {
		Max_sum += *(arr_of_goods + i);
	}
	cout << Max_sum << endl;
}