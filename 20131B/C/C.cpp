#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

string input;

struct node {
	string dictWord;
	int lastPos;
};

bool checkWord(string word, int & lastPos, int currentIndex, int & numChanges) {
	numChanges = 0;
	if(word.size() + currentIndex > input.size())
		return false;
	int lastIndex = word.size() + currentIndex - 1; 

	for(int index = currentIndex, windex = 0; index <= lastIndex; index++, windex++) {
		if(word[windex] != input[index]) {
			if(index - lastPos <= 4) {
				return false;
			} else {
				lastPos = index;
				numChanges++;
			}
		}
	}

	return true;
}

int main() {

	ifstream fin("C.in");
	ofstream fout("C.out");

	int T;

	fin >> T;

	ifstream fdict("dict.txt");
	vector<string> dictionary;

	while(!fdict.eof()) {
		fdict >> word;
		if(word.size() == 0)
			break;
		dictionary.push_back(word);
	}
	fdict.close();	

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {

		fin >> input;

		int output = 0;
		map<int, vector<node>> stackMatrix;
		int lastPos = 0;

		for(int index = 0; index <= input.size(); index++) {
			vector<node> stack;
			stackMatrix.insert(make_pair(index, stack));
		}
		for(int index = 0; index <= input.size(); index++) {
			
		}

		fout << "Case #" << caseNumber << ": " << output;
	}
	fin.close();
	fout.close();
}
