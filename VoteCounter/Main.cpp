//Name	:Edgars Rozenstams
//Code	:C00195570

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inFile;

	inFile.open("candidates.txt", std::ios::in);
	
	string line;
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			cout << line << endl;
		}
		inFile.close();
	}
	system("pause");
	return 0;
}