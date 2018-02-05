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
		std::string name;
		std::string party;

		void setName(std::string name)
		{
			//read in from file or sent in from cpp file which read it from a file
		}
	
		std::string getName()
		{
			return name;
		}

		void setParty(std::string party)
		{
			//read in from file or sent in from cpp file which read it from a file
		}

		std::string getParty()
		{
			return party;
		}

};
