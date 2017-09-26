#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;

#define repeat(start, end) for(int i = start; i <= end; i++)

double newMote(double dk, double da) {
	return (dk + 1.0) * da - dk * (dk + 1.0) / 2.0;
}

bool check(int k, long a, long b) {
	double dk = k, da = a, db = b;
	return (db < newMote(dk, da));
}

int main() {
	ifstream fin("A-large-practice.in");
	ofstream fout("A-large-practice.out");

	int T;

	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
		long A, N;
		fin >> A >> N;

		vector<long> motes;

		repeat(1, N) {
			long mote;
			fin >> mote;
			motes.push_back(mote);
		}

		sort(motes.begin(), motes.end());

		int operations = 0;
		long mote = A;
		int i = 0;
		int minOperations = INT_MAX;
		bool done = false;

		while(i < motes.size()) {
			//cout << caseNumber << " " << operations << " " << minOperations << " " << mote << " " << motes[i] << endl;
			if(mote == 1) {
				operations = motes.size() - i;
				break;
			}
			if(mote > motes[i]) {
				mote += motes[i];
				i++;
				continue;
			} else {
				int alt = operations + motes.size() - i;
				if(alt < minOperations) {
					minOperations = alt;
				}
				while(mote <= motes[i]) {
					mote += mote - 1;
					operations++;
				}
				mote += motes[i];
				i++;
			}
		}

		if(minOperations == INT_MAX) {
			minOperations = operations;
		}

		if(operations < minOperations) {
			minOperations = operations;
		}

		fout << "Case #" << caseNumber << ": " << minOperations << endl;
	}

	fin.close();
	fout.close();
}