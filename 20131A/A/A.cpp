#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	ifstream fin("A.in");
	ofstream fout("A.out");

	int T;

	fin >> T;
	fout << fixed;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
		double r, t, term = 0.0, sum = 0.0;

		fin >> r >> t;

		unsigned long k = 1;
		term = 2.0 * r + 1.0;
		sum = term;
		while(t >= sum) {
			term += (long double)4.0;
			sum += term;
			k++;
		}

		fout << "Case #" << caseNumber << ": " << k - 1 << endl;
	}

	fin.close();
	fout.close();
}