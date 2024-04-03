#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void quickSort(vector<int>array, int low, int high)
{
	int i = low;
	int j = high;
	int ot = array[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (array[i] < ot)
			i++;
		while (array[j] > ot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort(array, low, j);
	if (i < high)
		quickSort(array, i, high);
}

void main()
{
	int N;
	cout << "Enter the amount of elements: ";
	cin >> N;
	vector<int>A(N);
	vector<int>B(N);
	vector<int>C(N);
	vector<int>D(N);
	vector<int>E(N);
	cout << "Original array: ";
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 100 + 1;
		cout << A[i] << ' ';
	}
	cout << endl;
	B = A;
	C = A;
	D = A;
	E = A;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 2; j++) {
			if (B[j] > B[j + 1]) {
				swap(B[j], B[j + 1]);
			}
		}
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	cout << "Sorted version of array B(by bubble sort): ";
	for (int i = 0; i < N; i++) {
		cout << B[i] << ' ';
	}
	cout << endl;
	cout << "Processing time: " << duration.count() << " nanoseconds" << endl;
	auto start1 = std::chrono::high_resolution_clock::now();
	int i, key, j;
	for (i = 1; i < N; i++) {
		key = C[i];
		j = i - 1;
		while (j >= 0 && C[j] > key) {
			C[j + 1] = C[j];
			j = j - 1;
		}
		C[j + 1] = key;
	}
	auto stop1 = std::chrono::high_resolution_clock::now();
	auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1);
	cout << "Sorted version of array C(by insertion sort): ";
	for (int i = 0; i < N; i++) {
		cout << C[i] << ' ';
	}
	cout << endl;
	cout << "Processing time: " << duration1.count()<<" nanoseconds" << endl;
	auto start2 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		int min, buf;
		min = i;

		for (int j = i + 1; j < N; j++)
			min = (D[j] < D[min]) ? j : min;

		if (i != min) {
			buf = D[i];
			D[i] = D[min];
			D[min] = buf;
		}
	}
	auto stop2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop2 - start2);
	cout << "Sorted version of array D(by selection sort): ";
	for (int i = 0; i < N; i++) {
		cout << D[i] << ' ';
	}
	cout << endl;
	cout << "Processing time: " << duration2.count() << " nanoseconds" << endl;	
	auto start3 = std::chrono::high_resolution_clock::now();
	quickSort(E, 0, N);
	auto stop3 = std::chrono::high_resolution_clock::now();
	auto duration3 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop3 - start3);
	cout << "Sorted version of array E(by quick sort): ";
	for (int i = 0; i < N; i++) {
		cout << E[i] << ' ';
	}
	cout << endl;
	cout << "Processing time: " << duration3.count() << " nanoseconds" << endl;
}
