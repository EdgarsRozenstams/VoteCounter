//Name	:Edgars Rozenstams
//Code	:C00195570

#pragma once
#include <string>
#include <vector>
#include "Candidate.h"

using namespace std;

class Ballot
{
public:
	static int id;

	Ballot(){}

	Ballot(vector<int> & votes,vector<Candidate>  & candidate)
	{
		setPreference(votes, candidate);
	}

	void setPreference(vector<int> & votes, vector<Candidate> & candidate)
	{
		vector<Candidate> preferance; // a vector of candidates sorted in order of preferances (eg: 0 == preffered candidate)
		for (int i = 0; i < votes.max_size(); i++)
		{
			preferance.push_back(candidate[votes[i]]); //push back the nth candidate to pref vector. (eg: #3412, i=2 > push back the second prefered candidate (4th candidate))
		}
		preferance[1].inrementVoteCount();
	}
	string getPreference(vector<int> & v)
	{
		return "";
	}


};

