#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	ifstream fin("B.in");
	ofstream fout("B.out");

	int T;

	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
		

		fout << "Case #" << caseNumber << ": " << k - 1 << endl;
	}

	fin.close();
	fout.close();
}