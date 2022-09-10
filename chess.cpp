#include <iostream>
#include <string.h>
using namespace std;



int move checker(string player_name,char playerAinputs[5], char playerBinputs[5],string character_name, string move_name, char chess_grid[5][5])
{
	if(move_name == "L")
	{	
		for(int i=0;i<5;i++)
		{	
			for(int j=0;j<5;j++)
				
				if(chess_grid[i][j] == player_name+"-"+character_name)
				{	
					if(chess_grid[i][j-1].contains("A")){
						cout<<"Invalid move, try again!";
						return -1;
					}

					else if(!playe.contains()){
						cout<<"invalid move, try again!";
						return -1;
					}
				}
		}
	}
	
		else if(move_name == "R")
		{	
			for(int i=0;i<5;i++)
			{	cout<<"\n";
				for(int j=0;j<5;j++)
					chess_grid[i][j];
			}
		}
		else if(move_name == "F")
		{	
			for(int i=0;i<5;i++)
			{	cout<<"\n";
				for(int j=0;j<5;j++)
					chess_grid[i][j];
			}
		}
		else if(move_name == "B")
		{	
			for(int i=0;i<5;i++)
			{	cout<<"\n";
				for(int j=0;j<5;j++)
					chess_grid[i][j];
			}
		}

		cout<<"Current Grid:"<<endl;
		for(int i=0;i<5;i++)
		{	cout<<"\n";
			for(int j=0;j<5;j++)
				chess_grid[i][j];
		}
	
}

void move_maker(string player_name,char playerAinputs[5], char playerBinputs[5],string character_name, string move_name, char chess_grid[5][5])
{
	if(move_name == "L")
	{	
		for(int i=0;i<5;i++)
		{	
			for(int j=0;j<5;j++)
				
				if(chess_grid[i][j] == player_name+"-"+character_name)
				{	
					chess_grid[i][j-1] = chess_grid[i][j];
					chess_grid[i][j] = "_";

					if(chess_grid[i][j-1] ) 
				}
		}
	}
	
		else if(move_name == "R")
		{	
			for(int i=0;i<5;i++)
			{	cout<<"\n";
				for(int j=0;j<5;j++)
					chess_grid[i][j];
			}
		}
		else if(move_name == "F")
		{	
			for(int i=0;i<5;i++)
			{	cout<<"\n";
				for(int j=0;j<5;j++)
					chess_grid[i][j];
			}
		}
		else if(move_name == "B")
		{	
			for(int i=0;i<5;i++)
			{	cout<<"\n";
				for(int j=0;j<5;j++)
					chess_grid[i][j];
			}
		}

		cout<<"Current Grid:"<<endl;
		for(int i=0;i<5;i++)
		{	cout<<"\n";
			for(int j=0;j<5;j++)
				chess_grid[i][j];
		}
}





int main()
{
	char ipA[5], ipB[5];
	string moves, character_name, move_name;

	int result; // whether the move is valid or not

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



	while(strlen(ipA) == 0 || strlen(ipB) == 0)
	{

			cout << "Player A's Move: ";
			// taking input characters
			for(int i=0;i<5;i++)
				cin >> moves;
			
			// fidning the entere move and chess piece
			int pos = moves.find(":");
			character_name = moves.substr(0,pos - 1);
			move_name = moves.substr(pos + 1);

			int result = move_checker("A",ipA,ipB,character_name,move_name,chess_grid);//to check for invalid moves
			
			while(result == -1)
			{
				cout << "Invalid Move, Try again!!"
				cout << "Player A's Move: ";
				for(int i=0;i<5;i++)
					cin >> moves;

				int pos = moves.find(":");
				character_name = moves.substr(0,pos - 1);
				move_name = moves.substr(pos + 1);

				result = move_checker("A",ipA,ipB,character_name,move_name,chess_grid);
			}
			

			move_maker("A",ipA,ipB,character_name,move_name,chess_grid); // to make the changes in grid and displaying the result 

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "Player B's Move: ";

			for(int i=0;i<5;i++)
				cin >> moves;

			int pos = moves.find(":");
			character_name = moves.substr(0,pos - 1);
			move_name = moves.substr(pos + 1);

			int result = move_checker("B",ipA,ipB,character_name,move_name,chess_grid);//to check for invalid moves
			
			while(result == -1)
			{
				cout << "Invalid Move, Try again!!"
				cout << "Player B's Move: ";
				for(int i=0;i<5;i++)
					cin >> moves;

				int pos = moves.find(":");
				character_name = moves.substr(0,pos - 1);
				move_name = moves.substr(pos + 1);

				result = move_checker("B",ipA,ipB,character_name,move_name,chess_grid);
			}

			move_maker("B",ipA,ipB,character_name,move_name,chess_grid); // to make the changes in grid and displaying the result
	}

	if(strlen(ipA) == 0)
		cout <<"B is the winner!!!";
	else
		cout <<"A is the winner!!!";
	return 0;
}
