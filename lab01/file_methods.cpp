#include "file_methods.h"

vector <string> rF ()//return file in vector <string>
{
	ifstream input("eurovision.csv");
	int size = getSize();
	string g;
	vector <string> G;
	for (int i = 0; i < size; i++)
	{
		input >> g;
		G.push_back(g);
	}
	input.close();
	return G;
}

string rC(int num)//return Country,  from 0 to 19
{
	vector <string> f = rF();
	string Country;
	string line = f[num];
	for (int i = 0; isalpha(line[i]); i++)
	{
		Country = Country + line[i];
	}
	return Country;
}

int rSum(int num)//return Sum,  from 0 to 19
{
	int sum = 0;
	vector <string> f = rF();
	string temp = f[num];
	while (!temp.empty())
	{
		if (isdigit(temp[0]))
		{
			int digit = stoi(temp);
			sum += digit;
			while (isdigit(temp[0]))
			{ temp.erase(0, 1);}
		}
		else{ temp.erase(0, 1); }
	}
	return sum;
}

int getSize(){
	ifstream input("eurovision.csv");
	string countryCounter;
	input >> countryCounter;
	int size = stoi(countryCounter);
	input.close();
	return size;
}
