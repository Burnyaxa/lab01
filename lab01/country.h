#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector <string> getCountries(int size);
void print(vector <string> countries, vector<int> points, int size);
void sortByScore(vector <string> &countries, vector<int> &points, int size);
vector <vector<int>> getVotes(int size);
void getFinalScore(vector <vector<int>> &votes, int size);
int getMaxIndex(vector <vector<int>> &votes, int size, int column);
vector<int> sumRow(vector <vector<int>> votes, int size);
