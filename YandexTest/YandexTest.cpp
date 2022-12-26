#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

struct person
{
	string name, familyName, fatherName;
	int day, month, year;
	string symbols;
	string code;
};

int main()
{
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int count;
	int position;
	string input;
	cin >> count;
	person* users = new person[count];
	for (int n = 0; n < count; n++)
	{
		cin >> input;
		position = 0;
		for (int i = 0; i < input.length();)
		{
			string substr;
			while (input[i] != ',')
			{
				substr.append(1, input[i]);
				if (!(users[n].symbols.find(input[i]) < users[n].symbols.length()) && !isdigit(input[i]))
				{
					users[n].symbols.append(1, input[i]);
				}
				if (i == input.length())
				{
					break;
				}
				i++;
			}
			i++;
			switch (position)
			{
			case 0:
				users[n].familyName = substr;
				break;
			case 1:
				users[n].name = substr;
				break;
			case 2:
				users[n].fatherName = substr;
				break;
			case 3:
				users[n].day = stoi(substr);
				break;
			case 4:
				users[n].month = stoi(substr);
				break;
			case 5:
				users[n].year = stoi(substr);
				break;
			}
			position++;
		}
		int letterPosition = letters.find(tolower(users[n].familyName[0])) + 1;
		int code = users[n].symbols.size() - 1 + (users[n].day/10 + users[n].day%10 + users[n].month%10 + users[n].month/10) * 64 + letterPosition * 256;
		stringstream ss;
		ss << hex << code;
		users[n].code = ss.str();
		if (users[n].code.size() <= 3)
		{
			while (users[n].code.size() < 3)
			{
				users[n].code = "0" + users[n].code;
			} 
		}
		else
		{
			users[n].code = users[n].code.substr(users[n].code.size() - 3);
		}
		for (int i = 0; i < users[n].code.size(); i++)
		{
			if (!isdigit(users[n].code[i]))
			{
				users[n].code[i] = toupper(users[n].code[i]);
			}
		}
	}
	for (int n = 0; n < sizeof(users); n++)
	{
		cout << users[n].code << " ";
	}
	return 0;
}
