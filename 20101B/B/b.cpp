#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


class Chicken
{
public:
	int position;
	int velocity;
	int finalPosition;
	bool reaches;
public:
	Chicken() : reaches(false)
	{
	}
};

int main()
{
	std::ifstream fin;
	std::ofstream fout;

	fin.open("B-small-input.in");
	fout.open("B-output.out");

	int T;
	fin >> T;

	int output = 0;
	for(int caseNumber = 1; caseNumber <= T; caseNumber++)
	{
		int N, K, B, T;

		fin >> N >> K >> B >> T;

		std::vector<Chicken> chicken;

		for(int posNum = 0; posNum < N; posNum++)
		{
			int position;
			fin >> position;
			Chicken newChicken;
			newChicken.position = position;
			chicken.push_back(newChicken);
		}

		for(int velNum = 0; velNum < N; velNum++)
		{
			int velocity;
			fin >> velocity;
			chicken[velNum].velocity = velocity;

			int finalPosition = chicken[velNum].position + T * velocity;
			chicken[velNum].finalPosition = finalPosition;
		}

		int countReached = 0;
		for(int chickenNumber = chicken.size() - 1; chickenNumber >= 0; chickenNumber--)
		{
			if(chicken[chickenNumber].finalPosition < B)
			{
			}
			else
			{
				chicken[chickenNumber].reaches = true;
				countReached++;

				if(countReached == K)
					break;
			}
		}

		if(countReached < K)
			fout << "Case #" << caseNumber << ": " << "IMPOSSIBLE" << std::endl;
		else
		{
			output = 0;
			for(int i = 0; i < chicken.size(); i++)
			{
				for(int j = i+1; j < chicken.size() && chicken[i].reaches; j++)
				{
					double crossingTime = (double)(chicken[j].position - chicken[i].position)/(double)(chicken[i].velocity - chicken[j].velocity);

					if(crossingTime >= 0 && crossingTime < T && !chicken[j].reaches)
					{
						output++;
						std::cout << crossingTime << " " << chicken[i].position << " " << chicken[j].position << std::endl;
					}
				}
			}

			fout << "Case #" << caseNumber << ": " << output << std::endl;
		}
	}
}