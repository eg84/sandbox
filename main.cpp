/**************************************************************
 * AUTHOR			: Evan Grumling
 * PROJECT #4		: parallel Arrays
 * CLASS			: CSC5
 * SECTION			: Tues 6PM - 9:10PM
 **************************************************************/
#include "myheader.h"

int main() {
	const int SIZE = 30;		//size of arrays
	string name[SIZE];			//Array for Names
	int id[SIZE];				//Array for Id numbers
	float balance[SIZE];		//Array for account balances
	string searchNames[SIZE];	//array for names to be searched
	float searchBalances[SIZE];
	int records = 0;			//Number of records in file
	string inputfileName;		//Name of input File
	string outputFileName;		//name of output file
	ifstream inFile;
	string searchInput;			// search array loop
	int search;					//Stores results of searchFunction
	int count = 0;				//LCV for while loop
	int sCount = 0;				//incrimenter for searchNames array
	float balanceTotal = 0;
	float balanceAverage;		//holds average of all balances searched for

//get input file name
	cout << "What input file would you like to use? ";
	getline(cin, inputfileName);

//get output file name
	cout << "What output file would you like to use? ";
	getline(cin, outputFileName);

//open file
	inFile.open(inputfileName.c_str());

//call function to load arrays from
	LoadArraysFromFile(inFile,  name, id, balance, records, SIZE);

//close input file
	inFile.close();

//Get search name for search function
	cout << "Who do you want to search for (enter done to exit) : ";
	getline(cin, searchInput);

//open output file
	ofstream OFile(outputFileName.c_str());

//call function to display header in output file
	outputHeaderToFile(OFile);

//while loop calls search function, if a record is found
	while(searchInput != "done" && count < records)
	{
	//Call SearchFunction

		search = SearchFunction(searchInput, records, name, SIZE);

		if(search >= 0)
		{
			cout << "Found.\n" << endl;

			//add name to searched names array
			//searchNames[sCount]= searchInput;

			//add balance to searched balances array
			searchBalances[sCount] = balance[search];

			//write information to file
			OFile << left << setw(9) << id[search] << setw(25);
			OFile << name[search] << setw(1);
			OFile << "$" << right << setw(10)
					<< balance[search] << endl;

			//increment sCount
			sCount++;
		}
		//if error code -1 returned, tell user name not found
		else if(search == -1)
			cout << searchInput << " was not found.\n" << endl;

		//if it gets to this point something really messed up
		else
			cout << "Something went horribly wrong!" << endl;

		count++;

		//Get search name for search function
		cout << "Who do you want to search for (enter done to exit) : ";
		getline(cin, searchInput);
	}

//Average balances of searched balances array
	for(int i = 0; i < sCount; i++)
	{
		balanceTotal = searchBalances[i];
	}
	balanceAverage = balanceTotal / sCount;

//write average balance to file
	OFile << '\n' << setw(29) << "Average Balance Due:" << setw(8) << "$  " << balanceAverage << endl;

//output farewell message to screen
	cout << "Thank you for using my program." << endl;

//Close the output file
	OFile.close();
	return 0;
}





