/*
Sudoku Solver
Alex Heindel
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

int file_input(int num_array[][9], ifstream& fin);
void manual_input(int num_array[][9]);
void output_array(int array[][9]);

int main()
{
	int num_array[9][9] = { 0 };
	char input_choice;
	int error_check;
	bool input_loop = true;
	ifstream fin;
	
	cout << "Do you want manual input or file input (M or F): ";

	cin >> input_choice;

	input_choice = tolower(input_choice);
	while (input_loop)
	{
		if (input_choice == 'f')
		{
			//FIXME: Add args
			error_check = file_input(num_array, fin);
			input_loop = false;

			if (error_check == 1)
			{
				return 1;
			}
		}
		else if (input_choice == 'm')
		{
			//FIXME: add args
			manual_input(num_array);
			input_loop = false;
		}
		else
		{
			cout << "Invalid option, manual or file input (M or F): ";
			cin >> input_choice;
		}
	}
	
	output_array(num_array);

	return 0;
}

int file_input(int num_array[][9], ifstream& fin)
{
	char filename[31];
	int temp_array[9];

	cout << "Input filename of txt file with puzzle: ";
	//cin >> filename;

	fin.open("Sudoku1.txt");
	

	//Test if file opens
    //return 1 if file did not open
	if (!fin.is_open())
	{
		cout << "\nFile did not open" << endl;
		fin.close();

		return 1;
	}

	fin.close();
	return 0;
}

void manual_input(int num_array[][9])
{
	int i;
	int j;
	int temp_input;

	cout << "Enter all values of the puzzle (put 0 for numbers that need to be "
		"solved)" << endl;

	for (i = 0; i < 9; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			cout << i+1 << "x" << j+1 << ": ";
			cin >> temp_input;

			num_array[i][j] = temp_input;
		}
	}

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
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	return;
}