#include "file_methods.h"
#include "country.h"

void main(){
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