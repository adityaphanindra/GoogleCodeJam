#include <iostream>
#include <fstream>
#include <vector>

typedef unsigned int uint;
int main()
{
	std::ifstream fin;
	fin.open("A-large-practice.in");

	std::ofstream fout;
	fout.open("A-large-output.out");

	uint N;

	fin >> N;
	uint MAX_P = 1000;	
	
	for(uint i = 0; i < N; i++)
	{
		int bucket[MAX_P+1];
		for(uint j = 0; j <= MAX_P; j++)
		{
			bucket[j] = -1;
		}
		int C;
		uint I;

		fin >> C >> I;
		std::cout << "I = " << I << std::endl << std::endl;
		bool found = false;
		for(uint j = 0; j < I; j++)
		{
			uint item;
			fin >> item;
			if(found)
				continue;
			uint index1 = j + 1, index0 = 0;

			int diff = C - item;
			std::cout << item << std::endl;
			if(diff > 0 && diff <= MAX_P)
			{
				if(bucket[diff] != -1)
				{
					index0 = bucket[diff] + 1;
					fout << "Case #" << i + 1 << ": " << index0 << " " << index1 << std::endl;
					found = true;
					continue;
				}
				bucket[item] = j;
			}

		}
	}
}