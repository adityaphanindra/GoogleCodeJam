#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>


int main()
{
	std::ifstream fin("A-large-practice.in");
	std::ofstream fout("A-small.out");

	int T;
	fin >> T;
	for(int i = 1; i <= T; i++)
	{
		int n;
		fin >> n;
		std::vector<int> firstList, secondList;
		for(int j = 0; j < n; j++)
		{
			int number;
			fin >> number;
			firstList.push_back(number);
		}

		for(int j = 0; j < n; j++)
		{
			int number;
			fin >> number;
			secondList.push_back(number);
		}

		std::sort(firstList.begin(), firstList.end());
		std::sort(secondList.begin(), secondList.end());

		long double sum = 0;

		for(int j = 0; j < n; j++)
		{
			sum += firstList[j] * secondList[n-j-1];
		}

		fout << "Case #" << i << ": ";
		fout.precision(20);
		fout << sum << std::endl;
	}
}