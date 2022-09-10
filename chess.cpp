#include <iostream>
#include <string.h>
using namespace std;

int move_checker(string player_name,char playerAinputs[5], char playerBinputs[5],string character_name, string move_name, char chess_grid[5][5])
{
	for(int i=0;i<5;i++)
	{	
		for(int j=0;j<5;j++)
		{	
			if(chess_grid[i][j] == player_name+"-"+character_name)
			{	
				// Valid player check
				if(!playerAinputs.contains(character_name) || !playerBinputs.contains(character_name) ){
					return -1;
				}
				// Valid move check
				else if(move_name != "L" && move_name != "B" && move_name != "F" && move_name != "R"){
					return -1;
				}

				// boundary check
				else if(i+1 > 5 || j+1 > 5 || i-1 < 0 || j-1 < 0){
					return -1;
				}
				
				if(player_name == "A")
				{
					
					// friendly fire check
					if(chess_grid[i][j-1].contains("A")){
						return -1;
					}
					else if(chess_grid[i][j+1].contains("A")){
						return -1;
					}
					else if(chess_grid[i+1][j].contains("A")){
						return -1;
					}
					else if(chess_grid[i-1][j].contains("A")){
						return -1;
					}
				}
				else if(player_name == "B")
				{
					
					// friendly fire check
					if(chess_grid[i][j-1].contains("B")){
						return -1;
					}
					else if(chess_grid[i][j+1].contains("B")){
						return -1;
					}
					else if(chess_grid[i+1][j].contains("B")){
						return -1;
					}
					else if(chess_grid[i-1][j].contains("B")){
						return -1;
					}
				}
			}
		}
	}
}

void move_maker(string player_name,char playerAinputs[5], char playerBinputs[5],string character_name, string move_name, char chess_grid[5][5], int counter)
{
	for(int i=0;i<5;i++)
	{	
		for(int j=0;j<5;j++)
		{
			if(chess_grid[i][j] == player_name+"-"+character_name)
			{	
				
				if(move_name == "L")
				{
					if(player_name=="A")
					{
						if(chess_grid[i][j-1].contains("B"))
							playerBinputs[counter] = '\0';  // making random inputs of player B as NULL, to keep track of how many players are left. 

						chess_grid[i][j-1] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}

					else if(player_name=="B")
					{
						if(chess_grid[i][j+1].contains("A"))
							playerAinputs[counter] = '\0';   // making random inputs of player A as NULL, to keep track of how many players are left. 
							
						chess_grid[i][j+1] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}
					
				}
				else if(move_name == "R")
				{
					if(player_name=="A")
					{
						if(chess_grid[i][j+1].contains("B"))
							playerBinputs[counter] = '\0';  

						chess_grid[i][j+1] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}

					else if(player_name=="B")
					{
						if(chess_grid[i][j-1].contains("A"))
							playerAinputs[counter] = '\0';  
							
						chess_grid[i][j-1] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}
				}
				else if(move_name == "F")
				{
					if(player_name=="A")
					{
						if(chess_grid[i-1][j].contains("B"))
							playerBinputs[counter] = '\0';  

						chess_grid[i-1][j] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}

					else if(player_name=="B")
					{
						if(chess_grid[i+1][j].contains("A"))
							playerAinputs[counter] = '\0';  
							
						chess_grid[i+1][j] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}
				}
				else if(move_name == "B")
				{
					if(player_name=="A")
					{
						if(chess_grid[i+1][j].contains("B"))
							playerBinputs[counter] = '\0';  

						chess_grid[i+1][j] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}

					else if(player_name=="B")
					{
						if(chess_grid[i-1][j].contains("A"))
							playerAinputs[counter] = '\0';  
							
						chess_grid[i-1][j] = chess_grid[i][j];
						chess_grid[i][j] = "_";
					}  
				}
			}
		}
	}

	cout<<"Current Grid:"<<endl;
		for(int i=0;i<5;i++)
		{	cout<<"\n";
			for(int j=0;j<5;j++)
				cout<< chess_grid[i][j] << " ";
		}
}





int main()
{
	char ipA[5], ipB[5];
	string moves, character_name, move_name;

	int result, pos, counterA = 0, counterB = 0; // for personal refernce to keep track of deleted elements; // whether the move is valid or not

	string chess_grid[5][5];

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
		chess_grid[4][i] = "A"+"-"+ipA[i];
	

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
		chess_grid[0][i] = "B"+"-"+ipB[i];
	

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
			pos = moves.find(":");
			character_name = moves.substr(0,pos - 1);
			move_name = moves.substr(pos + 1);

			result = move_checker("A",ipA,ipB,character_name,move_name,chess_grid);//to check for invalid moves
			
			while(result == -1)
			{
				cout << "Invalid Move, Try again!!";
				cout << "Player A's Move: ";
				for(int i=0;i<5;i++)
					cin >> moves;

				pos = moves.find(":");
				character_name = moves.substr(0,pos - 1);
				move_name = moves.substr(pos + 1);

				result = move_checker("A",ipA,ipB,character_name,move_name,chess_grid);
			}
			
			counterA++;
			move_maker("A",ipA,ipB,character_name,move_name,chess_grid,counterA); // to make the changes in grid and displaying the result 


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "Player B's Move: ";

			for(int i=0;i<5;i++)
				cin >> moves;

			pos = moves.find(":");
			character_name = moves.substr(0,pos - 1);
			move_name = moves.substr(pos + 1);

			result = move_checker("B",ipA,ipB,character_name,move_name,chess_grid);//to check for invalid moves
			
			while(result == -1)
			{
				cout << "Invalid Move, Try again!!";
				cout << "Player B's Move: ";
				for(int i=0;i<5;i++)
					cin >> moves;

				pos = moves.find(":");
				character_name = moves.substr(0,pos - 1);
				move_name = moves.substr(pos + 1);

				result = move_checker("B",ipA,ipB,character_name,move_name,chess_grid);
			}
			counterB++;
			move_maker("B",ipA,ipB,character_name,move_name,chess_grid,counterB); // to make the changes in grid and displaying the result
	}

	if(strlen(ipA) == 0)
		cout <<"B is the winner!!!";
	else
		cout <<"A is the winner!!!";
	return 0;
}
