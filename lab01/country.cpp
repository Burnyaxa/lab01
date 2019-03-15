#include "file_methods.h"
#include "country.h"

void print(vector <country> data, int size){
	for (int i = 0; i < size; i++){
		cout << data[i].name << " " << data[i].score << endl;
	}
	cout << endl;
}

void sortByScore(vector <country> &data,int size){
	string tempC;
	int tempP;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (data[j].score < data[j + 1].score) {
				tempP = data[j].score;
				tempC = data[j].name;
				data[j].score =data[j + 1].score;
				data[j].name = data[j + 1].name;
				data[j + 1].score = tempP;
				data[j + 1].name = tempC;
			}
		}
	}
}


void getVotesRating(vector <country> &data, int size, vector <int> rate){
	for (int i = 0; i < size; i++){
		for (int v = 0; v < rate.size(); v++){
			data[getMaxIndex(data, size, i)].votes[i] = rate[v];
		}
		for (int j = 0; j < size; j++){
			if (data[j].votes[i] > rate[0]) data[j].votes[i] = 0;
		}
	}
}

int getMaxIndex(vector <country> data, int size, int column){
	int index = 0;
	int max = 0;
	for (int i = 0; i < size; i++){
		if (max < data[i].votes[column]){
			max = data[i].votes[column];
			index = i;
		}
	}
	return index;
}

void getScore(vector <country> &data, int size){
	int sum;
	for (int i = 0; i < size; i++){
		sum = 0;
		for (int j = 0; j < size; j++){
			sum += data[i].votes[j];
		}
		data[i].score = sum;
	}
}

void getCountries(vector <country> &data, int size){
	int *votes = new int[size];
	string name;
	for (int i = 0; i < size; i++){
		name = rC(i);
		for (int j = 0; j < size; j++){
			votes[j] = getNum(j, i);
		}
		data.push_back(country(name, votes, size));
	}
}

void sortVector(vector <int> &rate){
	int temp;
	for (int i = 0; i < rate.size() - 1; i++){
		for (int j = 0; j < rate.size() - i - 1; j++){
			if (rate[j] < rate[j + 1]){
				temp = rate[j];
				rate[j] = rate[j + 1];
				rate[j + 1] = temp;
			}
		}
	}
}




