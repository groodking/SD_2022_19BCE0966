#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ipA[5], ipB[5];
	char moves[];

	char *token = strtok(str, "-");

	char chess_grid[5][5];

	// initialize the game board
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			chess_grid[i][j] = "_";


	cout << "Player A Input: ";
	// taking input characters
	for(int i=0;i<5;i++)
		cin >> ipA[i];
	
	// inserting characters in grid
	for(int i=0;i<5;i++)
		chess_grid[4][i] = "A-"+ipA[i];
	

	// Displaying the current board
	cout<<"Current Grid:"<<endl;
	for(int i=0;i<5;i++)
	{	cout<<"\n";
		for(int j=0;j<5;j++)
			chess_grid[i][j];
	}


	cout << "Player B Input: " <<"\n";
	
	// taking input characters
	for(int i=0;i<5;i++)
		cin >> ipB[i];
	
	// inserting characters in grid
	for(int i=0;i<5;i++)
		chess_grid[0][i] = "B-"+ipB[i];
	

	// Displaying the current board
	cout<<"Current Grid:"<<endl;
	for(int i=0;i<5;i++)
	{	cout<<"\n";
		for(int j=0;j<5;j++)
			chess_grid[i][j];
	}



	while(strlen(ipA) == 0 || strlen(ipB) == 0){
		
		cout << "Player A Input: ";
		// taking input characters
		for(int i=0;i<5;i++)
			cin >> moves;

		cout << "Player B Input: ";
		// taking input characters
		for(int i=0;i<5;i++)
			cin >> moves;
		

	}
	return 0;
}
