#include "file_methods.h"
#include "country.h"

vector <string> getCountries(int size){
	vector <string> country;
	for (int i = 0; i < size; i++){
		country.push_back(rC(i));
	}
	return country;
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

vector <vector<int>> getVotes(int size){
	vector <vector <int>> votes;
	vector <int> temp;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			temp.push_back(getNum(j, i));
		}
		votes.push_back(temp);
		temp.clear();
	}
	return votes;
}



void getFinalScore(vector <vector<int>> &votes, int size){
	for (int i = 0; i < size; i++){
		int score = 12;
		for (int count = 1; count <= 10; count++){
			votes[getMaxIndex(votes, size, i)][i] = score;
			if (count < 3) score -= 2;
			else score--;
		}
		for (int j = 0; j < size; j++){
			if (votes[j][i] > 12) votes[j][i] = 0;
		}
	}
}

int getMaxIndex(vector <vector<int>> &votes, int size, int column){
	int index = 0;
	int max = votes[0][column];
	for (int i = 1; i < size; i++){
		if (max < votes[i][column]){
			max = votes[i][column];
			index = i;
		}
	}
	return index;
}

vector<int> sumRow(vector <vector<int>> votes, int size){
	int sum = 0;
	vector<int> sumR;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			sum += votes[i][j];
		}
		sumR.push_back(sum);
		sum = 0;
	}
	return sumR;
}



