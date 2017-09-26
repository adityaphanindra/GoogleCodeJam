#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const int NUM_ROW = 4;
const int NUM_COL = 4;

const string BAD = "Bad magician!";
const string CHEAT = "Volunteer cheated!";

int main() {
	ifstream fin("A-small-attempt1.in");
	ofstream fout("A-small-attempt1.out");

	int T;
	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {

		int first = 0, second = 0;
		vector<int> firstRow(NUM_COL), secondRow(NUM_COL);

		fin >> first;
		for(int row = 0; row < NUM_ROW; row++) {
			for(int col = 0; col < NUM_COL; col++) {
				int cardNum;
				fin >> cardNum;
				if(row == first-1)
					firstRow.push_back(cardNum);
			}
		}

		fin >> second;
		int numMatches = 0;
		int matchedCard = 0;

		for(int row = 0; row < NUM_ROW; row++) {
			for(int col = 0; col < NUM_COL; col++) {
				int cardNum;
				fin >> cardNum;
				if(row == second-1) {
					if(find(firstRow.begin(), firstRow.end(), cardNum) != firstRow.end()) {
						numMatches++;
						matchedCard = cardNum;
					}
				}
			}
		}

		if(numMatches == 0) {
			fout << "Case #" << caseNumber << ": " << CHEAT << endl;
		} else if(numMatches == 1) {
			fout << "Case #" << caseNumber << ": " << matchedCard << endl;
		} else {
			fout << "Case #" << caseNumber << ": " << BAD << endl;
		}
	}

	fin.close();
	fout.close();
}