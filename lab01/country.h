#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector <string> getCountries(int size);
vector <int> getPoints(int size);
void print(vector <string> countries, vector<int> points, int size);
void sortByScore(vector <string> &countries, vector<int> &points, int size);
void getFinalScore(vector <int> &points, int size);
