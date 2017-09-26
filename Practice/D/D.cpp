#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("A.in");
	ofstream fout("A.out");

	int T;
	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++)
	{
		int output = 0;
		
		fout << "Case #" << caseNumber << ": " << output << endl;
	}

	fin.close();
	fout.close();
}