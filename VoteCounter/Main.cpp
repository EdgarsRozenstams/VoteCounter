//Name	:Edgars Rozenstams
//Code	:C00195570

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "Candidate.h"
#include "Ballot.h"
using namespace std;

string getCandidateName(string line);
string getCandidateParty(string line);

int main()
{
	vector<Candidate> candidates;//vector of candidates
	vector<int> candidatePref;
	vector<Ballot> ballots;
	ifstream inFile;
	inFile.open("candidates.txt",std::ios::in);
	string line;
	vector<int> candidatePref;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			if (line[0] != '#')//candidates dont start with the # symbol
			{
				string name = getCandidateName(line);
				string party = getCandidateParty(line);

				candidates.push_back(Candidate(name, party));

				cout << line << endl;
			}
			else if (line[0] == '#')//ballot votes start with the # character
			{
				line.erase(0);
				for (int i = 0; i < line.length();i++)
				{
					candidatePref.push_back((int)line[i]);
				}
				ballots.push_back(Ballot(candidatePref, candidates));
			}
		}
		inFile.close();
	}

	cout << "--------candidates--------" << endl;

	for (size_t i = 0; i < candidates.size(); i++)	//i is assigned to size_t since its being compared to a nother size_t
	{
		cout << candidates[i].getName()<< " for " << candidates[i].getParty() << endl;
	}
	system("pause");
	return 0;
}


string getCandidateName(string line)
{
	string name;
	size_t pos = line.find('-');
	name = line.substr(0,pos);
	return name;
}

string getCandidateParty(string line)
{
	string party;
	size_t pos = line.find('-');
	party = line.substr(pos);
	return party;
}
