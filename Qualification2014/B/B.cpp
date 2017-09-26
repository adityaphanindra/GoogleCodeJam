#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");

	int T;
	fin >> T;
	fout << fixed;
	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
		double C, F, X;

		fin >> C >> F >> X;

		vector<double> cumsum;
		double previousOutput = INFINITY, currentSum = 0, output = 0;
		int k = 0;

		while(previousOutput > output) {
			double a = X / (F * (double)k + 2.0);
			if(k > 0) {
				double b = C / (F * (double)(k - 1) + 2.0);
				previousOutput = output;
				currentSum = b + cumsum[cumsum.size() - 1];
				output = a + currentSum;
			}
			else {
				output = a;
				currentSum = 0;
			}
			cumsum.push_back(currentSum);
			k++;
		}

		fout << "Case #" << caseNumber << ": " << setprecision(7) << previousOutput << endl;
	}

	fin.close();
	fout.close();
}