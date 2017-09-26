#include <iostream>
#include <fstream>
#include <deque>

typedef unsigned int uint;
int main()
{
	std::ifstream fin;
	fin.open("B-large-practice.in");

	std::ofstream fout;
	fout.open("B-large-practice.out");

	uint N;
	fin >> N;
	fin.get();
	for(uint i = 0; i < N; i++)
	{
		std::deque<std::string> reverse;
		std::string word;
		while(1)
		{
			char input;
			fin.get(input);
			if(input == ' ')
			{
				reverse.push_front(word);
				word.clear();
			}
			else if(input == '\n')
			{
				reverse.push_front(word);
				word.clear();
				fout << "Case #" << i + 1 << ":";
				for(uint j = 0; j < reverse.size(); j++)
				{
					fout << " " << reverse[j];
				}
				fout << std::endl;
				break;
			}
			else
			{
				word += input;
			}
				
		}
	}

	fin.close();
	fout.close();
}