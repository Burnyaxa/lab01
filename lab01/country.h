#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct country{
	int *votes;
	int score;
	string name;

	country(string name, int *votes, int size){
		this->votes = new int[size];
		this->name = name;
		for (int i = 0; i < size; i++){
			this->votes[i] = votes[i];
		}
	}
};

void getCountries(vector <country> &data, int size);
void print(vector <country> data, int size);
void sortByScore(vector <country> &data, int size);
void getVotesRating(vector <country> &data, int size, vector <int> rate);
int getMaxIndex(vector<country> data, int size, int column);
void getScore(vector <country> &data, int size);
void sortVector(vector <int> &rate);

