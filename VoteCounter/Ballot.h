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

	Ballot(vector<int> & preferance, vector<Candidate> & candidate) //i could send the list of candidates and the list of votes for one balllot.
	{
		setPreference(preferance, candidate);
	}

	void setPreference(vector<int> & v, vector<Candidate> & candidate)
	{

	}
	string getPreference(vector<int> & v)
	{
		return "";
	}



};

