// Ankita Tank
// CS341
// Homework 01 
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>
using std::string;
using std::ifstream;
using std::vector;
using std::stringstream;
using std::getline;
using std::stoi;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::copy;

class Number
{
public:
	int digit;
	string letter;

	Number(int d, string l)
		:digit(d), letter(l)
	{}
};


int occurence;
vector<int>length;
void showSubsets(vector<int> &vec);
int findSubset(vector<Number> &l, int length, vector<int> current, int sum);

int main()
{
	int sum;
	int scount = 0;
	int counter = -1;
	string lines;
	ifstream k("purple.txt");
	vector<Number> num;
	vector<int>curr;
	string numb;
	string alpha;

	while (!k.eof())
	{
		getline(k, lines);
		stringstream cc(lines);
		getline(cc, numb, ' ');
		getline(cc, alpha, '\n');
		counter++;
		Number B(stoi(numb), alpha);
		num.push_back(B);
	}

	cout << "Enter The Sum That You want to Compute : ";
	cin >> sum;
	cout << endl;
	cout << "The Subsets formed are : ";
	int NumberOfSubsets = findSubset(num, counter, curr, sum);
	cout << endl << endl;
	cout << "The total number of subsets formed by the input file are : " << NumberOfSubsets << endl;
	k.close();

	sort(length.begin(), length.end(),
		[](int A1, int A2) {
		if (A1 < A2)
			return true;
		else
			return false;
	}
	);

	sort(curr.begin(), curr.end());
	curr.erase(unique(curr.begin(), curr.end()), curr.end());

	cout << endl;
	cout << "The Smallest Possible Subset is of Length : " << length.at(1) << endl << endl;
}

void showSubsets(vector<int> &vec)
{
	length.push_back(vec.size());
	cout << "{ ";

	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << " ";

	cout << "} ";
}

int findSubset(vector<Number> &l, int length, vector<int> current, int sum)
{
	if (sum == 0)
	{
		occurence++;
		showSubsets(current);
		return occurence;
	}

	if (length == 0) return occurence;

	if (l.at(length - 1).digit <= sum)
	{
		findSubset(l, length - 1, current, sum);
		current.push_back(l.at(length - 1).digit);
		findSubset(l, length - 1, current, sum - (l.at(length - 1).digit));
	}
	else
		findSubset(l, length - 1, current, sum);

	return occurence;
}