#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstring>

int main()
{
	std::ifstream fin;
	std::ofstream fout;

	fin.open("A-input.in");
	fout.open("A-output.out");

	int T;
	fin >> T;
	for(int caseNumber = 1; caseNumber <= T; caseNumber++)
	{
		int N, M, output = 0;

		fin >> N >> M;

		std::set<std::string> dirSetsExist, dirSetsCreated;
		std::string line;
		for(int lineNum = 0; lineNum < N; lineNum++)
		{			
			fin >> line;
			line += "/";
			std::string currentDir = "";

			for(int characterIndex = 0; characterIndex < line.size(); characterIndex++)
			{
				char currentChar = line[characterIndex];

				if(currentChar == '/' && currentDir != "")
					dirSetsExist.insert(currentDir);

				currentDir += currentChar;
			}
		}

		for(int lineNum = 0; lineNum < M; lineNum++)
		{			
			fin >> line;
			line += "/";
			std::string currentDir = "";

			for(int characterIndex = 0; characterIndex < line.size(); characterIndex++)
			{
				char currentChar = line[characterIndex];

				if(currentChar == '/' && currentDir != "")
					dirSetsCreated.insert(currentDir);

				currentDir += currentChar;
			}
		}

		
		for(auto itcreate = dirSetsCreated.begin(); itcreate != dirSetsCreated.end(); itcreate++)
		{
			if(dirSetsExist.find(*itcreate) == dirSetsExist.end())
				output++;
		}
		for(auto iterator = dirSetsExist.begin(); iterator != dirSetsExist.end(); iterator++)
			std::cout << *iterator << std::endl;

		std::cout << std::endl;
		for(auto iterator = dirSetsCreated.begin(); iterator != dirSetsCreated.end(); iterator++)
			std::cout << *iterator << std::endl;
		

		std::cout << output << std::endl;



		
		fout << "Case #" << caseNumber << ": " << output << std::endl;
		//std::cout << std::endl;
	}

	fin.close();
	fout.close();
}