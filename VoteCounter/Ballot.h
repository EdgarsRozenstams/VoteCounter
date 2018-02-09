//Name	:Edgars Rozenstams
//Code	:C00195570

#pragma once
#include <string>
#include <vector>
#include "Candidate.h"

using namespace std;
static int ID = 0;

class Ballot
{
public:
	vector<Candidate> preferance; // a vector of candidates sorted in order of preferances (0 == preffered candidate)
	int prefferedVote = 0; //keeps track of the ballots preffered candidate, incremments whenever the preffered candidate gets knocked out
	int id = ID;

	Ballot(){}

	Ballot(vector<int> &votes, vector<Candidate> &candidate)
	{
		setPreference(votes, candidate);
		assignVoters(preferance, ID);
		ID++;
	}

	//sorts preferances into a vector of candidates in order of preferance,
	void setPreference(vector<int> &votes, vector<Candidate> &candidate)
	{
		for (int i = 0; i < votes.size(); i++)
		{
			preferance.push_back(candidate[votes[i]-1]); //push back the nth candidate to pref vector. (eg: #3412, i=2 > push back the second prefered candidate (4th candidate))
		}
	}

	Candidate getPreference()
	{
		return preferance[prefferedVote];
	}

	// assigns the id of the ballot that voted for the candidate
	void assignVoters(vector<Candidate>& preferance, int ID)
	{
		preferance[prefferedVote].addVoter(ID);
	}

};

