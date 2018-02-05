#pragma once
#include <string>
#include <list>

//setName, getName, setParty and getParty

class Candidate
{
private:
	std::list <int> voters;
	int voteCounter;
public:
		std::string name;
		std::string party;

		void setName()
		{
			//read in from file or sent in from cpp file which read it from a file
		}
	
		std::string getName()
		{
			return name;
		}

		void setParty()
		{
			//read in from file or sent in from cpp file which read it from a file
		}

		std::string getParty()
		{
			return party;
		}




};
