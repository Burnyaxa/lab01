#include "file_methods.h"

vector <string> getCountries(int size){
	vector <string> country;
	for (int i = 0; i < size; i++){
		country.push_back(rC(i));
	}
	return country;
}

vector <int> getPoints(int size){
	vector<int> points;
	for (int i = 0; i < size; i++){
		points.push_back(rSum(i));
	}
	return points;
}

void print(vector <string> countries, vector<int> points, int size){
	for (int i = 0; i < size; i++){
		cout << countries[i] << " " << points[i] << endl;
	}
	cout << endl;
}

void sortByScore(vector <string> &countries, vector<int> &points, int size){
	string tempC;
	int tempP;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (points[j] < points[j + 1]) {
				tempP = points[j];
				tempC = countries[j];
				points[j] = points[j + 1];
				countries[j] = countries[j + 1];
				points[j + 1] = tempP;
				countries[j + 1] = tempC;
			}
		}
	}
}