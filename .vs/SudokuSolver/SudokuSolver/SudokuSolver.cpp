/*
Sudoku Solver
Alex Heindel
*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int file_input();
void manual_input();
void output_array(int array[][9]);

int main()
{
	int num_array[9][9] = { 0 };
	char input_choice;
	int error_check;
	bool input_loop = true;
	
	cout << "Do you want manual input or file input (M or F): ";

	cin >> input_choice;

	input_choice = tolower(input_choice);
	while (input_loop)
	{
		if (input_choice == 'f')
		{
			//FIXME: Add args
			error_check = file_input();
			input_loop = false;
		}
		else if (input_choice == 'm')
		{
			//FIXME: add args
			manual_input();
			input_loop = false;
		}
		else
		{
			cout << "Invalid option, manual or file input (M or F): ";
			cin >> input_choice;
		}
	}
	cout << "Out" << endl;

	output_array(num_array);

	return 0;
}

int file_input()
{
	//return 1 if files do not open
	return 0;
}

void manual_input()
{

	return;
}


void output_array(int array[][9])
{
	int i;
	int j;

	for (i = 0; i < 9; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			//FIXME: change to output in file
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	return;
}