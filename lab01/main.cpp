#include "file_methods.h"
#include "country.h"

// [3,6,7,8]
// struct Country {name, int[]}

void main(int argc, char* argv[])
{
	int size = getSize();
	vector <string> countries = getCountries(size);
	vector <vector<int>> votes = getVotes(size);
	getFinalScore(votes, size);
	vector<int> result = sumRow(votes, size);
	sortByScore(countries, result, size);
	print(countries, result, size);
	getResultFile(countries, result, 10);
	system("pause");
}
