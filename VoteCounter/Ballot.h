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
	vector<Candidate> preferance; // a vector of candidates sorted in order of preferances (0 == preffered candidate)

	Ballot(){}

	Ballot(vector<int> &votes, vector<Candidate> &candidate)
	{
		setPreference(votes, candidate);
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
		return preferance[0];
	}


};

