//Name	:Edgars Rozenstams
//Code	:C00195570

#pragma once
#include <string>
#include <vector>

using namespace std;

class Candidate
{
public:
	vector <int> voterIDs;//holds all the allots that voted for this candidate/
	int voteCounter = 0;
	string candidateName;
	string candidateParty;

	Candidate() {}	//default constructor

	Candidate(string name, string party)
	{
		setName(name);
		setParty(party);
	}

	void setName(string name)
	{
		candidateName = name;
	}

	string getName()
	{
		return candidateName;
	}

	void setParty(string party)
	{
		candidateParty = party;
	}

	string getParty()
	{
		return candidateParty;
	}

	void incrementVoteCount()
	{
		voteCounter += 1;
	}
	//returns the number of votes a candidate has
	int getVotes()
	{
		return voteCounter;
	}
	//adds the id of the balot which voted for this candidata
	void addVoter(int id)
	{
		voterIDs.push_back(id);
	}

};

