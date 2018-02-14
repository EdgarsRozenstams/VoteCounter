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
Candidate getLoser(vector<Candidate>& candidates);
void printCandidates(vector<Candidate> candidates);
void deleteCandidate(vector<Candidate>& candiates, Candidate loser , vector<Ballot>& ballots);
void reAsignVote(vector<Candidate>& candiates, Candidate loser, vector<Ballot>& ballots);
int noOfCandidate = 0;

int main()
{
	vector<Candidate> candidates;//vector of candidates
	vector<Ballot> ballots;
	vector<int> candidatePref;
	vector<Candidate> eliminated;


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

				candidates.push_back(Candidate(name, party)); //Adds candidate to vector of candidates
				noOfCandidate++;

				cout << line << endl;
			}
			else if (line[0] == '#')	//ballot votes start with the # character ([#23145] means that the preffered candidate is #2 followed by 3 etc..)
			{
				candidatePref.clear();
				line = line.substr(1); //removes the '#'
				for (int i = 0; i < line.length(); i++) 
				{
					candidatePref.push_back(line[i] - '0');//saved the preference list of the ballot and chaged teh characters to int's.
				}

				ballots.push_back(Ballot(candidatePref, candidates));//crreates ballot obj
			}
		}
		inFile.close(); //closes the read in file
	}

	while (noOfCandidate > 1)
	{
		printCandidates(candidates);
		reAsignVote(candidates, getLoser(candidates), ballots); //reasign losing candidates votes
		deleteCandidate(candidates, getLoser(candidates), ballots);
	}	

	cout << "\n***************************************************************" << endl;
	cout << "THE WINNER IS [ " << candidates[0].getName() << " ] WITH THE [ " << candidates[0].getParty() << " ] PARTY " << endl;

	system("pause");
	return 0;
}

string getCandidateName(string line)
{
	string name;
	size_t pos = line.find('-');
	name = line.substr(0, pos);
	return name;
}

string getCandidateParty(string line)
{
	string party;
	size_t pos = line.find('-');
	party = line.substr(pos + 1);
	return party;
}

void printCandidates(vector<Candidate> candidates)
{
	cout << "\n--------candidates--------" << endl;
	for (int i = 0; i < candidates.size(); i++)
	{
		cout << candidates[i].getName() << " " << candidates[i].getVotes() << endl;
	}
}
//Returns candidate with least amount of votes
Candidate getLoser(vector<Candidate>& candidates)
{
	int voteCount = candidates[0].getVotes(); //initialize first candiate as lowest votes
	Candidate lowest = candidates[0];		  //initialize first candiate as loser

	for (int i = 0; i < candidates.size(); i++)
	{
		if (candidates[i].getVotes() < lowest.getVotes())
		{
			lowest = candidates[i];
		}
	}
	return lowest;
}
//Deletes the losing candidate from local candidate Vector and from ballots.
void deleteCandidate(vector<Candidate>& candiates, Candidate loser, vector<Ballot>& ballots)
{
	for (int i = 0; i < candiates.size(); i++)
	{
		if (candiates[i].getName() == loser.getName())
		{
			candiates.erase(candiates.begin() + i);
			noOfCandidate -= 1;
		}
	}
	for (int x = 0; x < ballots.size(); x++)
	{
		ballots[x].deleteCandidate(loser);
	}	
}
//Reasigns loosing candidates votes
void reAsignVote(vector<Candidate>& candiates, Candidate loser, vector<Ballot>& ballots)
{
	int candId;
	for (int i = 0; i < candiates.size(); i++) //goes through candidates
	{
		if (candiates[i].getName() == loser.getName()) //if candidate matches loser
		{
			for (int v = 0; v < candiates[i].voterIDs.size(); v++)//goes through ballots that voted for this candidate
			{
				candId = candiates[i].voterIDs[v];		 //current ballot id
				for (int a = 0; a < ballots.size(); a++) //checks id against ballot id's
				{
					if (candId == ballots[a].id)
					{	
						ballots[a].incrementPreferedVote();
						ballots[a].assignVoters(candiates, candId);
					}
				}
			}
		}
	}
}