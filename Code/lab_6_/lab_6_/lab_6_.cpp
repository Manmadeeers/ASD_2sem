#include <iostream>
#include <string>
using namespace std;
#define TABLE_SIZE 20
struct Node {
	long long tel_number;//a key
	string FIO;//a vlue
	struct Node* next;//pointer to the next element
};
Node* hashmap[TABLE_SIZE];//allocate memory for a hashmap
//prototypes
long long HashFunction(long long key);
void add_elements(long long key, string value, Node* hashmap[]);
void print_map(Node* hashmap[]);
void delete_by_key(long long key);
bool search(long long key);


void main()
{
	for (int i = 0; i < TABLE_SIZE; i++) {//initialize all the elements of a hashmap with nulls
		hashmap[i] = NULL;
	}
	char choise;//variable to be converted to interger for furhter usage
	do {
		//choise of variants
		cout << "0 - Print a hashmap" << endl;
		cout << "1-Enter new" << endl;
		cout << "2-Delete existing" << endl;
		cout << "3-Search" << endl;
		cout << "4-Exit" << endl;
		cin >> choise;
		while (!(choise >= '1' || choise <= '4')) {//input check
			cout << "Incorrect input! Try again: ";
			cin >> choise;
		}
		int choise_sw = choise - '0';//convert char to integer
		switch (choise_sw) {

		case 0: print_map(hashmap);
			break;

		case 1:
			int amount;
			cout << "How many elements would you like to add to the hashmap? ";
			cin >> amount;
			for (int i = 0; i < amount; i++) {
				cout << "Adding element number " << i + 1 << " :" << endl;
				string temp_key;
				cout << "Enter the phone number(12 digits max): ";
				cin.ignore(cin.rdbuf()->in_avail());//clear the buffer to avoid crashes
				getline(cin, temp_key);//get the string
				int check_length = temp_key.length();//get the length of an inputed string
				while (check_length > 12 || check_length < 10) {
					cout << "Incorrect input! Try again: ";
					getline(cin, temp_key);
					check_length = temp_key.length();
				}
				//convert string to integer
				long long key = stoll(temp_key);
				//now get the value for a pair
				string value;
				cout << "Enter FIO: ";
				cin.ignore(cin.rdbuf()->in_avail());//clear the buffer to avoid crashes
				getline(cin, value);
				int check_value_length = value.length();//get the length of an inputed string
				bool flag = true;
				while (flag == true) {
					for (int j = 0; j < check_value_length; j++) {//loop to check all the digits of a string
						if (!(value[j] >= 'a' || value[j] <= 'Z')) {//if it's not a letter
							cout << "Incorrect input! Try again: ";
							getline(cin, value);
							break;
						}
					}
					flag = false;
					
				}
				add_elements(key, value, hashmap);
			}
			break;

		case 2: 
			system("cls");//clearing console
			cout << "Deletion by phone number:" << endl;
			long long value_to_delete;
			cout << "Enter the phone number you want to delete: ";
			cin >> value_to_delete;
			delete_by_key(value_to_delete);
			break;

		case 3: 
			system("cls");
			long long search_key;
			cout << "Enter a phone number to search if it's present in a hsahmap: ";
			cin >> search_key;
			bool search_result = search(search_key);
			if (search_result == true) {
				cout << "There is such an element in a hashmap!" << endl;
			}
			else {
				cout << "There are no such elements in a hashmap!" << endl;
			}
			break;

		}

	} while (choise != '4');//loop exit condition

}

long long HashFunction(long long key)//hashfunction
{
	return key % TABLE_SIZE;
}

void add_elements(long long key, string value, Node* hashmap[])//function to add  new elements into a hashmap
{
	long long index = HashFunction(key);//calculate an index of an element in a hashmap
	Node* newNode = new Node;//memory for a new node
	//allocating info to transfer in ti the hashmap further
	newNode->tel_number = key;
	newNode->FIO = value;
	newNode->next = nullptr;
	if (!hashmap[index]) {//if there are no elements with such index in a hashmap yet
		hashmap[index] = newNode;

	}
	else {//if there are
		Node** temp = &hashmap[index];
		while (*temp) {//check untill a free place is found
			temp = &(*temp)->next;
		}
		*temp = newNode;
	}

}
void print_map(Node*hashmap[])//function to peint the hashmap
{
	cout << "Hashmap:" << endl;
	for (int i = 0; i < TABLE_SIZE; i++) {//loop to go through all the array of single linked lists
		Node* current = hashmap[i];
		bool nulls_present = false;//flag to check present nulls in a link
		if (current == NULL) {//if an element met in NULL
			cout << "NULL" << endl;
			nulls_present = true;//raise the flag
		}
		while (current!=nullptr&&nulls_present==false) {//loop execution condition
			cout << "Key: " << current->tel_number << "<--->" << "Value: " << current->FIO << "||";
			if (current->next != nullptr) {
				current = current->next;
			}
			else {
				break;
				cout << endl;
			}
		}
		cout << endl;
	}
}
void delete_by_key(long long key)//function to delete elements by key (phone number in this case
{
	long long index = HashFunction(key);//get an index of a required element in a hashmap
	Node** temp = &hashmap[index];
	Node* prev = nullptr;
	if (*temp == nullptr) {
		cout << "There are no elements with such index!" << endl;
		return;
	}
	while (*temp) {//untill there are elements
		if ((*temp)->tel_number == key) {//if an element is found
			if (prev) {//and if there is a previous one
				prev->next = (*temp)->next;//set the next previos to the current one
			}
			else {//if in is at a start of a single linked list
				hashmap[index] = (*temp)->next;//set to null
			}
			delete* temp;//free memory
			cout << "A piece of information was succsessfuly deleted!" << endl;
			return;//end
		}
		prev = *temp;//iteration process
		temp = &(*temp)->next;
	}
}

bool search(long long key)//function to search elements by phone number
{
	int index = HashFunction(key);//calculate an index using hash function
	Node* current = hashmap[index];//get a list with such index from a hashmap
	while (current) {//loop to check the whole single linked list with such index
		if (current->tel_number == key) {
			return true;
		}
		current = current->next;//loop iteration
	}
	return false;
}