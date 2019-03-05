vector <string> rF ()
{
	ifstream input("eurovision.csv");
	string g, costyl;
	vector <string> G;
	input >> costyl;
	int size = stoi(costyl, 0);
	for (int i = 0; i < size; i++)
	{
		input >> g;
		G.push_back(g);
	}
	input.close();
	return G;
}
