#include "file_methods.h"
#include "country.h"

vector <string> rF()//return file in vector <string>
{
	ifstream input("eurovision.csv");

	int size = getSize();
	string g;
	vector <string> G;
	for (int i = 0; i < size; i++)
	{
		string f;

		bool alpha = 0, digit = 0;
		while (!(alpha&&digit)) {
			input >> g;
			if (isalpha(g[1])) {
				f += g;
				f += " ";
				g = f;
				for (int i = 0; i < g.size(); i++)
				{
					if (isalpha(g[i])) { alpha = true; }
					if (isdigit(g[i])) { digit = true; }
					if (alpha&&digit) { break; }
				}
				f = g;

			}
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

	for (int i = 0; ((isalpha(line[i])) || (isspace(line[i]))); i++)

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
			{
				temp.erase(0, 1);
			}
		}
		else{ temp.erase(0, 1); }
	}
	return sum;
}

int getNum(int kx, int ky)
{
	int k = 0;
	vector <string> f = rF();;
	string temp = f[ky];
	while (!temp.empty())
	{
		if (isdigit(temp[0]))
		{
			if (k == kx)
			{
				int digit = stoi(temp);
				return digit;
			}
			while (isdigit(temp[0]))
			{
				temp.erase(0, 1);
			}
			k++;
		}
		else { temp.erase(0, 1); }
	}
	return NAN;
}

int getSize(){
	ifstream input("eurovision.csv");
	string countryCounter;
	input >> countryCounter;
	int size = stoi(countryCounter, 0);
	input.close();
	return size;
}


void getResultFile(vector <country> data, int size){
	ofstream out;
	out.open("results.csv");
	if (out.is_open()){
		for (int i = 0; i < size; i++){
			out << data[i].name << "," << data[i].score << endl;
		}
	}
	out.close();
}

vector <int> cmdInput(int argc, char*argv[])
{
	vector <int> ar;
	for (int i = 1; i < argc; i++)
	{
		ar.push_back(atoi(argv[i]));
	}
	return ar;
}

