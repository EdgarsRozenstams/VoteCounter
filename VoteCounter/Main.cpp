//Name	:Edgars Rozenstams
//Code	:C00195570

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	std::ifstream inFile;

	inFile.open("candidates.txt", std::ios::in);
	//inFile >> numbers;//save .txt file numbers to array.
	inFile.close();

	return 0;
}