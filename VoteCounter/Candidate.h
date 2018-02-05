#pragma once
#include <string>
#include <list>

//setName, getName, setParty and getParty

class Candidate
{
private:
	std::list <int> voters;//holds ids of voters for reuse when knocked out.
	int voteCounter = 0;
public:
		std::string candidateName;
		std::string candidateParty;
		
		Candidate(){}	//default constructor

		Candidate(std::string name,std::string party)
		{
			setName(name);
			setParty(party);
		}

		void setName(std::string name)
		{
			candidateName = name;
		}
	
		std::string getName()
		{
			return candidateName;
		}

		void setParty(std::string party)
		{
			candidateParty = party;
		}

		std::string getParty()
		{
			return candidateParty;
		}

};
