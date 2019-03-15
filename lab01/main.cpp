#include "file_methods.h"
#include "country.h"

/*
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
*/

int main(int argc, char* argv[])
{
	vector <int> rate = cmdInput(argc, argv);
	if (!rate.size()) rate = { 12, 10, 8, 7, 6, 5, 4, 3, 2, 1 };
	else sortVector(rate);
	int size = getSize();
	vector <country> dataBase;
	getCountries(dataBase, size);
	getVotesRating(dataBase, size, rate);
	getScore(dataBase, size);
	sortByScore(dataBase, size);
	print(dataBase, size);
	getResultFile(dataBase, 10);
	system("pause");

	return 0;
}
