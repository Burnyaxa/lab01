#include "file_methods.h"
#include "country.h"

void main(){
	int size = getSize();
	vector<string> countries = getCountries(size);
	vector<int> points = getPoints(size);
	sortByScore(countries, points, size);
	print(countries, points, size);
	getFinalScore(points, 10);
	cout << "Final score : " << endl;
	print(countries, points, 10);
	getResultFile(countries,points, 10);
	system("pause");
}