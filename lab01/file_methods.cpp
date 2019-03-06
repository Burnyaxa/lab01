<<<<<<< HEAD
#include "file_methods.h"

vector <string> rF ()//return file in vector <string>
{
	ifstream input("eurovision.csv");
	int size = getSize();
	string g;
	vector <string> G;
=======
vector <string> rF ()
{
	ifstream input("eurovision.csv");
	string g, countryCounter;
	vector <string> G;
	input >> countryCounter;
	int size = stoi(countryCounter, 0);
>>>>>>> dev2
	for (int i = 0; i < size; i++)
	{
		string f;
		bool alpha = 0, digit = 0;
		while (!(alpha&&digit)) {
			input >> g;

			f += g;
			f += " ";
			g = f;
			for (int i = 0; i < g.size(); i++)
			{
				if (isalpha(g[i])) { alpha = true;}
				if (isdigit(g[i])) { digit = true; }
				if (alpha&&digit) { break; }
			}
			f = g;

		}
		G.push_back(g);
	}
	input.close();
	return G;
}

string rC(int num)
{
	vector <string> f = rF();
	string Country;
	string line = f[num];
<<<<<<< HEAD
	for (int i = 0; isalpha(line[i]); i++)
=======
	for (int i= 0; ((isalpha(line[i]))||(isspace(line[i]))); i++)
>>>>>>> dev2
	{
		Country = Country + line[i];
	}

	return Country;
}

int rSum(int num)
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
