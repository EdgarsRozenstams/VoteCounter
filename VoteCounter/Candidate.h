//Name	:Edgars Rozenstams
//Code	:C00195570

#pragma once
#include <string>
#include <list>

using namespace std;

class Candidate
{
private:
		list <int> voters;//holds ids of voters for reuse when knocked out.
		//int voteCounter = 0;
public:	
		int voteCounter = 0;
		string candidateName;
		string candidateParty;
		
		Candidate(){}	//default constructor

		Candidate(string name,string party)
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
			voteCounter++;
		}

		int getVotes() 
		{
			return voteCounter;
		}


};
