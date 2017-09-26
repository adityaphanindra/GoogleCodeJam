#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string findCode(int count) {
	switch(count) {
		case 1: return "";
		case 2: return " double";
		case 3: return " triple";
		case 4: return " quadruple";
		case 5: return " quintuple";
		case 6: return " sextuple";
		case 7: return " septuple";
		case 8: return " octuple";
		case 9: return " nonuple";
		case 10: return " decuple";
		default: return "";
	};
}

string num2text(char input) {
	switch(input) {
		case '1': return "one";
		case '2': return "two";
		case '3': return "three";
		case '4': return "four";
		case '5': return "five";
		case '6': return "six";
		case '7': return "seven";
		case '8': return "eight";
		case '9': return "nine";
		case '0': return "zero";
	};
}

int str2num(string input) {
	int output;
	istringstream iss;
	iss.str(input);
	iss >> output;
	return output;
}

vector<int> split(string input, char delimiter) {
	vector<int> tokens;
	string split = "";
	for(int i = 0; i < input.size(); i++) {
		if(input[i] == delimiter) {			
			tokens.push_back(str2num(split));
			split = "";
		} else {
			split += input[i];
		}
	}
	if(split != "") {
		tokens.push_back(str2num(split));
	}
	return tokens;
}

int main() {
	ifstream fin("A-large-practice.in");
	ofstream fout("A.out");

	int T;

	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
		string number, code, output;
		fin >> number >> code;

		vector<int> tokens = split(code, '-');
		int startIndex = 0;
		for(int digits : tokens) {
			string split = number.substr(startIndex, digits);
			int i = 0;
			char current = split[0];
			int count = 0;
			for(; i < digits; i++) {		

				if(split[i] != current) {
					output += findCode(count) + " " + num2text(current);
					current = split[i];
					count = 1;
				}
				else
					count++;
			}
			if(count > 0) {
				output += findCode(count) + " " + num2text(current);
			}
			startIndex += digits;
		}

		fout << "Case #" << caseNumber << ":" << output << endl;
	}

	fin.close();
	fout.close();

}