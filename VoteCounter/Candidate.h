//Name	:Edgars Rozenstams
//Code	:C00195570

#pragma once
#include <string>
#include <list>

using namespace std;

class Candidate
{
private:
		list <int> voters;//holds all the allots that voted for this candidate/
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
		void addVoter(int id)
		{
			voters.push_back(id);
		}
		/*void reasignVotes();
		{
			for (int i =0 ;i < voters.size(); i++) //goes through all ballot which voted for this candidate
			{
				//voters[i];
				cout << "hi";
			}
		}*/
};
