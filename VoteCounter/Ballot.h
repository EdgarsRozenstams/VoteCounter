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

	vector<Candidate> preferance;	//A vector of candidates sorted in order of preferances (0 == preffered candidate)
	int prefferedVote = 0;			//keeps track of the ballots preffered candidate, incremments whenever the preffered candidate gets knocked out
	int id = ID;					//The Ballots ID

	Ballot() {}

	Ballot(vector<int> &votes, vector<Candidate> &candidate)
	{
		setPreference(votes, candidate);
		assignVoters(candidate, ID); // assign initial votes.
		ID++;
	}

	//sorts a vector of candidates in order of preferance,
	void setPreference(vector<int> &votes, vector<Candidate> &candidate)
	{
		for (int i = 0; i < votes.size(); i++)
		{
			preferance.push_back(candidate[votes[i] - 1]); //push back the nth candidate to pref vector. (eg: #3412, i=2 > push back the second prefered candidate (4th candidate))
		}
	}

	//returnd Prefered candidate from this ballot
	Candidate getPreference()
	{
		return preferance[prefferedVote];
	}

	// assigns the id of the ballot that voted for the candidate
	void assignVoters(vector<Candidate>& candidates, int Id)
	{
		Candidate preference = getPreference();
		//finds the preffered candidate and updates their voter count and voter id's.
		for (int i = 0; i < candidates.size(); i++)
		{
			if (preferance[prefferedVote].getName() == candidates[i].getName())
			{
				candidates[i].incrementVoteCount();
				candidates[i].addVoter(this->id);
			}
		}
	}

	//increment prefered candidate
	void incrementPreferedVote()
	{
		this->preferance.erase(preferance.begin()); //by deleting the preffered candidate the second most prefered is not at [0]
	}

	//deletes the knocked out candidates from the preffered list so they dont get the votes anymore.
	void deleteCandidate(Candidate loser)
	{
		for (int i = 0; i < this->preferance.size(); i++)
		{
			if (preferance[i].getName() == loser.getName())
			{
				preferance.erase(preferance.begin() + i);
			}
		}
	}
};

