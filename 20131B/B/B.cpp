#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;
int main() {
	ifstream fin("B.in");
	ofstream fout("B.out");

	int T;

	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
		
		fout << "Case #" << caseNumber << ": " << minOperations << endl;
	}

	fin.close();
	fout.close();
}