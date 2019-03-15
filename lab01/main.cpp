#include "file_methods.h"
#include "country.h"

void main(){
	int size = getSize();
	
	vector <country> dataBase;
	getCountries(dataBase, size);
	getVotesRating(dataBase, size);
	getScore(dataBase, size);
	sortByScore(dataBase, size);
	print(dataBase, size);
	getResultFile(dataBase, 10);
	system("pause");
}