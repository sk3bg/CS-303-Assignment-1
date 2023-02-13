#include "FileArrayDataProcess.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int arr[10], length, index, value;
/*
*  read data (let’s say file that has 10 lines, and each line
contains 10 integers) from a file into an array.
*/

bool readFileToBuildArray()
{
	ifstream fp("Numbers.txt");

	if (!fp.is_open())
	{
		cout << "File Not Found";
		return false;
	}

	length = 0;

	while (fp >> arr[length])
	{
		length = length + 1;
	}

	fp.close();

	return true;
}
/*
* PrintArray function using to print the each element of the array.
*/
void printArray()
{
	cout << endl << "The elements are: ";

	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";

	cout << endl;
}
/*
* PrintNewArray function is using to print the each element after updating (adding/remove) the array 
*/
void printNewArray() {
	cout << endl << "New Array";
	printArray();

}
/*Check if a certain integer exists in the array if the number is present return the index where the
		number is present.*/
int searchElementInArray(int element)
{
	int i;

	for (i = length - 1; i >= 0; i--)
		if (arr[i] == element)
			return i;

	return i;
}
/*
* A function that can modify the value of an integer when called with the index of the integer in
  the array and return the new value and old value back to the user. The modfying function will throw an exception
  if function receives an invalid number format input.
*/
int modifyValueAtInex(int index)
{
		
	int inputValue, existingValue;
	try {
		cout << "Enter new value : ";
		cin >> inputValue;
	}
	catch (std::ios_base::failure& f) {
		cerr << "Invalid number format input\n";
		abort();
	}

	existingValue = arr[index];
	arr[index] = inputValue;
	return existingValue;
}
/*
* A function that adds a new integer to the end of the array
*/
void addNewElementAtEndOfArray()
{
	int inputValue;
	try {
		cout << endl << "Enter new element to be added at the end of Array: ";
		cin >> inputValue;
	}
	catch (std::ios_base::failure& f) {
		cerr << "Invalid number format input\n";
		abort();
	}

	arr[length] = inputValue;

	length = length + 1;

	cout << "Element Inserted";
}
/*
* A function which intakes an index of an array and replaces the value with either 0 or removes
  the integer altogether. The function will throw an exception
  if function receives an invalid number format input.
*/
void removeElementFromIndexLocation()
{
	int index;
	try {
		cout << endl << "Enter index of element to be removed: ";
		cin >> index;
	}
	catch (std::ios_base::failure& f) {
		cerr << "Invalid number format input\n";
		abort();
	}

	for (int i = index; i < length - 1; i++)
		arr[i] = arr[i + 1];

	length = length - 1;


}

int main()
{
	if (!readFileToBuildArray())
		return 0;

	printArray();
	try {

		/*Check if a certain integer exists in the array if the number is present return the index where the number is present.*/
		cout << "Enter the element to be searched: ";
		cin >> value;
	}
	catch (std::ios_base::failure& f) {
		cerr << "Invalid number format input\n";
		abort();
	}
	/*
	* The function check if a certain integer exists in the array if the number is present return the index where the
     number is present.
	*/
	index = searchElementInArray(value);

	if (index == -1)
		cout << "Element not found";

	else
		cout << value << " is present at index " << index;

	cout << endl << endl << "Enter the index of element to be modified: ";
	cin >> index;

	value = modifyValueAtInex(index);

	cout << value << " Value changed to " << arr[index];
	printNewArray();

	/*A function that adds a new integer to the end of the array*/
	addNewElementAtEndOfArray();
	printNewArray();

	/*A function which intakes an index of an array and replaces the value with either 0 or removes the integer altogether.*/
	removeElementFromIndexLocation();
	printNewArray();

	return 0;
}