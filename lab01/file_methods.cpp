vector <string> rF ()
{
	ifstream input("eurovision.csv");
	string g, countryCounter;
	vector <string> G;
	input >> countryCounter;
	int size = stoi(countryCounter, 0);
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
	for (int i= 0; ((isalpha(line[i]))||(isspace(line[i]))); i++)
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
