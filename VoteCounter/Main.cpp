//Name	:Edgars Rozenstams
//Code	:C00195570

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "Candidate.h"
using namespace std;

string getCandidateName(string line);
string getCandidateParty(string line);


int main()
{
	vector<Candidate> candidates;//vector of candidates
	ifstream inFile;
	inFile.open("candidates.txt",std::ios::in);
	string line;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			string name = getCandidateName(line);
			string party = getCandidateParty(line);

			candidates.push_back(Candidate(name, party));

			cout << line << endl;
		}
		inFile.close();
	}

	cout << "--------candidates--------" << endl;

	for (int i = 0; i < candidates.size(); i++)
	{
		cout << candidates[i].getName() << endl;
	}


	system("pause");
	return 0;
}


string getCandidateName(string line)
{
	size_t pos = line.find("-");
	string name = line.substr(0,pos);
	return name;
}

string getCandidateParty(string line)
{
	size_t pos = line.find("-");
	string party = line.substr(pos);
	return party;
}
