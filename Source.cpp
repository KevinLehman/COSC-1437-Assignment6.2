/*
Kevin Lehman  - 1463553
Tarrant County College - COSC 1437- Fall 2017
Assignment 2 - Week 6
*/

#include <iostream>
#include <string>

using namespace std;

void nameFormat(string);
const int max = 20;

int main()
{

	char loop = 'Y';
	string unformName;

	while (loop != 'X')
	{
		cout << "Enter a first and last name to be formatted." << endl;
		getline(cin, unformName);
		nameFormat(unformName);
		cout << "Press Y if you would like to enter another name or X to exit." << endl;
		cin >> loop;
		if (loop == 'x')
		{
			loop = toupper(loop);
		}
		cin.ignore();
	}
	system("PAUSE");
	return 0;
}

void nameFormat(string unformName)
{
	int space;
	int length = unformName.size();
	char firstName[max];
	char lastName[max];
	string formattedName;

	space = unformName.find(' ');

	for (int idx = 0; idx < space; idx++)
	{
		if (idx == 0)
		{
			firstName[idx] = toupper(unformName[idx]);
		}
		if (idx > 0)
		{
			firstName[idx] = tolower(unformName[idx]);
		}
	}
	formattedName.append(firstName);
	formattedName.resize(space);
	formattedName.append(1, ' ');

	for (int idx = 0; idx < (length - space); idx++)
	{
		if (idx == 0)
		{
			lastName[idx] = toupper(unformName[(space + 1) + idx]);
		}
		if (idx > 0)
		{
			if (ispunct(unformName[(space + 1) + idx]))
			{
				lastName[idx] = unformName[(space + 1) + idx];
				lastName[idx + 1] = toupper(unformName[(space + 1) + (idx + 1)]);
				idx++;
			}
			else
			{
				lastName[idx] = tolower(unformName[(space + 1) + idx]);
			}

		}

	}
	if (lastName[0] == 'M' && lastName[1] == 'a' && lastName[2] == 'c')
	{

		lastName[3] = toupper(lastName[3]);
	}
	if (lastName[0] == 'M' && lastName[1] == 'c')
	{
		lastName[2] = toupper(lastName[2]);
	}
	formattedName.append(lastName);
	formattedName.resize(length);

	cout << "Your properly formatted name is " << formattedName << "." << endl;
}