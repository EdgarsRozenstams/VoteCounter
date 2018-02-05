#pragma once
#include <string>
using namespace std;

class Ballot
{
public:
	static int id;


	Ballot(){}

	Ballot(int pref, string candidate) //i could send the list of candidates and the list of votes for one balllot.
	{
		setPreference(pref, candidate);
	}

	void setPreference(int pref, string candidate)
	{

	}
	string getPreference(int pref)
	{
		return "";
	}



};

