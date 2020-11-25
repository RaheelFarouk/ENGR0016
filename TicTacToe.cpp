/*
 * TicTacToe.cpp
 * 
 * Copyright 2020 Raheel Farouk <Raheel Farouk@ARFAROUK-DELL>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>


// prototpes
void displayMatrix(char []);
int getPosition(bool);
bool getWinner(int,int,int,char,char[]);
bool checkCompletion(char[]);

void displayMatrix(char array[]){
	printf("\n\t %c | %c | %c\n\t---|---|---\n\t %c | %c | %c\n\t---|---|---\n\t %c | %c | %c\n\t---|---|---", 
				array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8]);
	}


// function to get a matrix location. pass in true for user input as location and false for computer generated location value.
int getPosition(bool user){
	int location;
	if (user){
		do{
			printf("\nPlease enter location number from matrix: ");
			scanf("%d", &location);
		}while(location<1 || location>9);
		
	}else if(!user){
		location = ((rand()%9)+1);
		}
	return location-1;
	}
	
//use function to determine if game is draw or if there is a winner
bool getWinner(int a, int b, int c, char symbol, char array[]){
	bool returnVal;
	//cheching if row is  same
	if(array[a-1] == symbol && array[b-1] == symbol && array[c-1] == symbol){
		returnVal = true;
	}else{
		returnVal = false;
		}
	return returnVal;
}

//function to see if game is over anad if  its a draw
bool checkCompletion(char array[]){
	bool returnVal;
	
	if(array[0]!='1' && 
		array[1]!='2' && 
		array[2]!='3' && 
		array[3]!='4' && 
		array[4]!='5' && 
		array[5]!='6' && 
		array[6]!='7' && 
		array[7]!='8' && 
		array[8]!='9'){
			returnVal = true;
			}else{
				returnVal = false;
			}
	return returnVal;
	}


int main(int argc, char **argv)
{
	//Declaring variables for game
	char matrix[9] = {'1','2','3','4','5','6','7','8','9'};
	int position;
	bool notOver = true;
	//bool userPos, comPos; //variables to see if user or computer has won
	
	printf("\n\t %c | %c | %c\n\t---|---|---\n\t %c | %c | %c\n\t---|---|---\n\t %c | %c | %c\n\t---|---|---", 
				matrix[0], matrix[1], matrix[2], matrix[3], matrix[4], matrix[5], matrix[6], matrix[7], matrix[8]);
	
	printf("\n");			
	//while(true){printf("\n%d",(rand()%9)+1);}
	
	while(notOver){
		//get positon from user and check if that position is empty
		do{
			position = getPosition(true);
			if(matrix[position] == 'x' || matrix[position] == 'o'){
				printf("\nThat position is already taken try again");
			}
			}while(matrix[position] == 'x' || matrix[position] == 'o');
		matrix[position] = 'x';
		
		//get positon from computer and check if that position is empty
		do{
			position = getPosition(false);
			//printf("\nThat position is already taken tru again");
			}while(matrix[position] == 'x' || matrix[position] == 'o');
		matrix[position] = 'o';
		
		displayMatrix(matrix);
		
		//check if user has won
		if(getWinner(1,2,3,'x',matrix) ||	
			getWinner(4,5,6,'x',matrix) || 
			getWinner(7,8,9,'x',matrix) || 
			getWinner(1,5,9,'x',matrix) || 
			getWinner(3,5,7,'x',matrix) || 
			getWinner(1,4,7,'x',matrix) || 
			getWinner(2,5,8,'x',matrix) || 
			getWinner(3,6,9,'x',matrix)){
			//need to break and end 
			printf("\nYou won");
			notOver = false;
			
		}else if(getWinner(1,2,3,'o',matrix) ||	
			getWinner(4,5,6,'o',matrix) || 
			getWinner(7,8,9,'o',matrix) || 
			getWinner(1,5,9,'o',matrix) || 
			getWinner(3,5,7,'o',matrix) || 
			getWinner(1,4,7,'o',matrix) || 
			getWinner(2,5,8,'o',matrix) || 
			getWinner(3,6,9,'o',matrix)){
				//computer won break and end
				printf("\nyou lost");
				notOver = false;
		}else if(checkCompletion(matrix)){ 		//if condition to see if all spots are taken and if game is a draw;
			printf("\nGame drawed");
			//break;
			notOver = false;
			}
	}
		
	
	return 0;
}

