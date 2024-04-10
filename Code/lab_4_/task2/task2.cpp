//task 2
#include <iostream>
using namespace std;

void main()
{
	cout << "Welcome to the results of FIT-Olympiade!" << endl;
	int N;
	cout << "Enter the amount of winners: ";
	cin >> N;
	int* arr_of_winners = new int[N];
	cout << "All the scores: ";
	for (int i = 0; i < N; i++) {
		*(arr_of_winners + i) = rand() % 10 + 1;
		cout << *(arr_of_winners + i) << ' ';
	}
	cout << endl;
	//definine  maximal score
	int Max_score = *(arr_of_winners + 0);
	for (int i = 0; i < N; i++) {
		if (*(arr_of_winners + i) > Max_score) {
			Max_score = *(arr_of_winners + i);
		}
	}
	cout << "Maximal score: " << Max_score << endl;
	//bubble sort from maximal to minimal
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (*(arr_of_winners + j) < *(arr_of_winners + j + 1)) {
				int temp = *(arr_of_winners + j);
				*(arr_of_winners + j) = *(arr_of_winners + j + 1);
				*(arr_of_winners + j + 1) = temp;
			}
		}
	}
	cout << "Sorted version of winners: ";
	for (int i = 0; i < N; i++) {
		cout << *(arr_of_winners + i) << ' ';
	}
	cout << endl;
	for (int check = 0; check < N; check++) {
		if (*(arr_of_winners + check) == Max_score) {
			cout << "The first place goes to the participant number " << check+1 << " with " << *(arr_of_winners + check) << " score" << endl;
		}
		if (*(arr_of_winners + check) == Max_score - 1) {
			cout << "The second place goes to the participant number " << check+1 << " with " << *(arr_of_winners + check) << " points" << endl;
		}
		if (*(arr_of_winners + check) == Max_score - 2) {
			cout << "The third place goes to the participant number " << check+1 << " with " << *(arr_of_winners + check) << " points" << endl;
		}
	}
}