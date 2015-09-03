/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

// This program will convert integer number into Roman numeral from 1 to 4000
#include "stdafx.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

void outThousands(int num);
void outHundreds(int num);
void outTen(int num);
void outUnit(int num);

int main()
{
	int num;
	char x = 'y';

	cout << "Please enter an integer: ";
	cin >> num;

	if (num <= 0)
	{
		cout << "Please enter a different integer (no negative or decimal number): ";
		cin >> num;
	}

	cout << "--> ";
	outThousands(num);
	outHundreds(num);
	outTen(num);
	outUnit(num);

	cout << endl;

	do
	{
		cout << "Would you like to convert another integer (Y/N): ";
		cin >> x;
		if (x == 'y' || x == 'Y')
		{
			cout << "Please enter an integer: ";
			cin >> num;

			cout << "--> ";
			outThousands(num);
			outHundreds(num);
			outTen(num);
			outUnit(num);

			cout << endl;
		}

		if (x == 'n' || x == 'N')
		{
			return 0;
		}
	} while (x == 'y' || x == 'Y');

	return 0;
}

void outThousands(int num)
{
	int thousand = num / 1000;

	if (thousand > 0)
	{
		for (int i = 1; i <= thousand; i++)
			cout << "M";
	}
}

void outHundreds(int num)
{
	int hundred = (num % 1000) / 100;

	if (hundred > 0)
	{
		if (hundred <= 3)
		{
			for (int i = 1; i <= hundred; i++)
				cout << "C";
		}
		else if (hundred == 4)
			cout << "CD";
		else if (hundred >= 5 && hundred <= 8)
		{
			cout << "D";
			for (int i = 6; i <= hundred; i++)
				cout << "C";
		}
		else if (hundred == 9)
			cout << "CM";
	}
}

void outTen(int num)
{
	int ten = (num % 100) / 10;

	if (ten > 0)
	{
		if (ten <= 3)
		{
			for (int i = 1; i <= ten; i++)
				cout << "X";
		}
		else if (ten == 4)
			cout << "XL";
		else if (ten >= 5 && ten <= 8)
		{
			cout << "L";
			for (int i = 6; i <= ten; i++)
				cout << "X";
		}
		else if (ten == 9)
			cout << "XC";
	}
}

void outUnit(int num)
{
	int unit = (num % 10);

	if (unit > 0)
	{
		if (unit <= 3)
		{
			for (int i = 1; i <= unit; i++)
				cout << "I";
		}
		else if (unit == 4)
			cout << "IV";
		else if (unit >= 5 && unit <= 8)
		{
			cout << "V";
			for (int i = 6; i <= unit; i++)
				cout << "I";
		}
		else if (unit == 9)
			cout << "IX";
	}
}



