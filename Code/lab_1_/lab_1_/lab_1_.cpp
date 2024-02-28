#include <iostream>
using namespace std;

//function prototype
void fibanacci(int);
int fibonacci_rec(int N);

void main()
{
	int N;
	cout << "Enter a number in a fibonacci chain: ";
	cin >> N;
	//using fuction
	char choise;
	do {
		cout << "1-Use cycle" << endl;
		cout << "2-Use recursion" << endl;
		cout << "3-Exit" << endl;
		cin >> choise;
		int choise_sw = choise - '0';
		switch (choise_sw) {
		case 1: fibanacci(N); break;
		case 2:
			unsigned int start_time = clock();
			cout << "Required number in fibonacci chain: " << fibonacci_rec(N) << endl;
			unsigned int end_time = clock();
			unsigned int time = end_time - start_time;
			cout << "Program is finished in " << time / 60 << " minutes " << time % 60 << " seconds" << endl; break;
		}

	} while (choise != '3');
}

void fibanacci(int N)
{
	//using cycle to count
	unsigned int start_time = clock();
	unsigned long long arr_fib[3];
	arr_fib[0] = 0;
	arr_fib[1] = 1;
	for (int i = 0; i < N-2; i++) {
		arr_fib[2] = arr_fib[0] + arr_fib[1];
		arr_fib[0] = arr_fib[1];
		arr_fib[1] = arr_fib[2];
	}
	//answer
	unsigned int end_time = clock();
	cout << "Required number in fibonacci chain: " << arr_fib[2] << endl;
	unsigned int time = end_time - start_time;
	cout << "Program is finished in " << time / 60 << " minutes " << time % 60 << " seconds" << endl;
}

//use recursion
int fibonacci_rec(int N)
{
	if (N > 49||N==0) {
		return -1;
	}
	if ( N == 2||N==3) {
		return 1;
	}
	if (N == 1) {
		return 0;
	}
	return fibonacci_rec(N - 1) + fibonacci_rec(N - 2);
}
