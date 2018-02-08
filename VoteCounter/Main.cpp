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
void addVotes(vector<Ballot> ballots, vector<Candidate>& candidate);
void printCandidates(vector<Candidate> candidates);

int main()
{
	vector<Candidate> candidates;//vector of candidates
	vector<Ballot> ballots;
	vector<int> candidatePref;

	ifstream inFile;
	inFile.open("candidates.txt", std::ios::in);
	string line;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			if (line[0] != '#')	//candidates dont start with the # symbol
			{
				string name = getCandidateName(line);
				string party = getCandidateParty(line);

				candidates.push_back(Candidate(name, party));

				cout << line << endl;
			}
			else if (line[0] == '#')	//ballot votes start with the # character
			{
				candidatePref.clear();
				line = line.substr(1); //removes the '#'
				for (int i = 0; i < line.length();i++) //goes through preferance list
				{
					candidatePref.push_back(line[i]-'0');
				}

				ballots.push_back(Ballot(candidatePref, candidates));
			}
		}
		inFile.close();
	}
	addVotes(ballots, candidates);
	printCandidates(candidates);

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
	party = line.substr(pos+1);
	return party;
}

void addVotes(vector<Ballot> ballots, vector<Candidate>& candidates) 
{
	int prefCandidate = 0;
	for (int i = 0; i < ballots.size(); i++)
	{
		for (int x = 0; x < candidates.size();x++)
		{
			if (candidates[x].getName() == ballots[i].getPreference().getName())
			{
				candidates[x].incrementVoteCount();
			}
		}		
	}
}

void printCandidates(vector<Candidate> candidates)
{
	cout << "--------candidates--------" << endl;
	for (int i = 0; i < candidates.size(); i++)
	{
		cout << candidates[i].getName() << " " << candidates[i].getVotes() << endl;
	}

}