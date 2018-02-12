//Name	:Edgars Rozenstams
//Code	:C00195570

#pragma once
#include <string>
#include <vector>
#include "Candidate.h"

using namespace std;
static int ID = 100;

class Ballot
{
public:
	// a vector of candidates sorted in order of preferances (0 == preffered candidate)
	vector<Candidate> preferance;

	//keeps track of the ballots preffered candidate, incremments whenever the preffered candidate gets knocked out
	int prefferedVote = 0; 
	int id = ID;

	Ballot(){}

	Ballot(vector<int> &votes, vector<Candidate> &candidate)
	{
		setPreference(votes, candidate);
		//assignVoters(candidate ,ID);
		ID++;
	}

	//sorts a vector of candidates in order of preferance,
	void setPreference(vector<int> &votes, vector<Candidate> &candidate)
	{
		for (int i = 0; i < votes.size(); i++)
		{
			preferance.push_back( candidate[votes[i]-1]); //push back the nth candidate to pref vector. (eg: #3412, i=2 > push back the second prefered candidate (4th candidate))
		}
	}

	Candidate getPreference()
	{
		return preferance[0];
	}

	// assigns the id of the ballot that voted for the candidate
	void assignVoters( vector<Candidate>& candidates, int ID)
	{
		Candidate preference = getPreference();
		//finds the preffered candidate and updates thevoter count.
		for (int i = 0; i < candidates.size(); i++)
		{
			if (preferance[0].getName() == candidates[i].getName())
			{
				candidates[i].incrementVoteCount();
				candidates[i].addVoter(ID);
			}
		}
	}

	//increment prefered candidate
	void incrementPreferedVote()
	{
		prefferedVote += 1;
	}
};

