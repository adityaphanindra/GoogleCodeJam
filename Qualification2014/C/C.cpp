#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	ifstream fin("C.in");
	ofstream fout("C.out");

	int T;
	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {

		fout << "Case #" << caseNumber << ": " << previousOutput << endl;
	}

	fin.close();
	fout.close();
}