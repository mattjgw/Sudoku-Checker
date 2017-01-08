/*
 * SudokuChecker.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: Matthew Wright
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

	checkRows(sudoku, correct);
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
	int sum = 0;

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			sum += sudoku[i][j];
		}

		if(sum == SUM)
		{
			sum = 0;
		}

		else
		{
			correct = false;
			return;
		}
	}
	return;
}

void checkColumns(int sudoku[][WIDTH], bool &correct)
{
	int sum = 0;
	int j = 0;
	for(int i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			sum += sudoku[j][i];
		}

		if(sum == SUM)
		{
			sum = 0;
		}

		else
		{
			correct = false;
			return;
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
				for(int l = 0; l <=2; l++)
				{
					sum += sudoku[i + k][j + l];
				}
			}
			if(sum == SUM)
					{
						sum = 0;
					}

			else
			{
				correct = false;
				return;
			}
		}
	}
	return;
}


