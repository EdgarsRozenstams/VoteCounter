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
Candidate getLoser(vector<Candidate>& candidates);
void deleteCandidate(vector<Candidate>& candiates, Candidate loser);

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

	while (candidates.size() > 1)
	{
		addVotes(ballots, candidates);
		printCandidates(candidates);
		deleteCandidate(candidates, getLoser(candidates));
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

Candidate getLoser(vector<Candidate>& candidates)
{
	int voteCount = candidates[0].getVotes();
	vector<Candidate> losers;
	Candidate lowest = candidates[0];

	for (int i = 0 ;i < candidates.size(); i++)
	{
		if (candidates[i].getVotes() < lowest.getVotes() )
		{
			lowest = candidates[i];
		}
	}
	//for now just set the first lowest as the looser
	return lowest;
}

void deleteCandidate(vector<Candidate>& candiates, Candidate loser)
{
	//loser.reasignVotes();
	for (int i = 0; i < candiates.size(); i++) ///doesnt delete object : look into.
	{
		if (candiates[i].getName() == loser.getName()) // TODO: find out why i get vector out of bounds erro
		{
			//sets the knocked out candidate object to NULL
			Candidate *empty = &candiates[i];
			empty = NULL; 
		}
	}
}

