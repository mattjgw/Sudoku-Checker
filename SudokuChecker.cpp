/*
 * SudokuChecker.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: Matthew Wright
 *  Last Modified: April 11, 2017
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

const int SUM = 45;
const int HEIGHT = 9;
const int WIDTH = 9;

void checkRows(int sudoku[][WIDTH], bool &correct);
void checkColumns(int sudoku[][WIDTH], bool &correct);
void checkBoxes(int sudoku[][WIDTH], bool &correct);

int main()
{
	ifstream input;
	input.open("Sudoku.txt");
	int sudoku[HEIGHT][WIDTH];
	bool correct = true;

	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			input>>sudoku[i][j];
		}
	}

	//checkRows(sudoku, correct);
	if(correct)
	{
		checkColumns(sudoku, correct);
		if(correct)
		{
			checkBoxes(sudoku, correct);
			if(correct)
			{
				cout<<"That is a correct sudoku solution";
				return 0;
			}
		}
	}
	cout<<"That is an incorrect sudoku solution";
	return 0;

}

void checkRows(int sudoku[][WIDTH], bool &correct)
{
	for(int i = 0; i < 9; i++)
	{
		int check[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		for(int j = 0; j < 9; j++)
		{

			for(int k = 0; k < 9; k++)
			{
				if(sudoku[i][j] == check[k])
				{
					check[k] = 0;
				}
			}
		}
		for(int k = 0; k < 9; k++)
		{
			if(check[k] != 0)
			{
				correct = false;
			}
		}
	}
	return;
}

void checkColumns(int sudoku[][WIDTH], bool &correct)
{
	for(int i = 0; i < 9; i++)
		{
			int check[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
			for(int j = 0; j < 9; j++)
			{

				for(int k = 0; k < 9; k++)
				{
					if(sudoku[j][i] == check[k])
					{
						check[k] = 0;
					}
				}
			}
			for(int k = 0; k < 9; k++)
			{
				if(check[k] != 0)
				{
					correct = false;
				}
			}
		}
		return;
}

void checkBoxes(int sudoku[][WIDTH], bool &correct)
{
	int sum = 0;
	for(int i = 0; i < 9; i += 3)
	{
		for(int j = 0; j < 9; j += 3)
		{
			for(int k = 0; k <= 2; k++)
			{
				int check[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				for(int l = 0; l <=2; l++)
				{
					for(int m = 0; m < 9; m++)
					{
						if(sudoku[i+k][j+l] == check[m])
						{
							check[k] = 0;
						}
					}
				}
				for(int m = 0; m < 9; m++)
				{
					if(check[k] != 0)
					{
						correct = false;
					}
				}
			}
		}
	}
	return;
}


