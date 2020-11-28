
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
/*Ok boys this is the code that will run the game
 * Try to see if you can make a function of the actual game and just set it 
 * in the for loops. Also feel free to add more options to the switch case
 * just remember to update the random int generator accordingly*/ 
 //Also Raheel can you see if there is a way to make the random in generator more random
 
 //Delete those comments prior to submission
 
 /*Important note for grading
  * This game gives the illusion of choice.
  * It makes the user feel they are making the decisions 
  * but really the computer is*/

int main(){
	
	int a;
	int d;
	int i;
	int gd;
	int np;
	
	//vars declared
	//---------------------------------------------------------------------------------------
	
	printf("Would you like to play the game? (1=Y/2=N): ");
	scanf("%d",&a);
	//Asking user if they would like to play
	//---------------------------------------------------------------------------------------
	
	while(a!=1 && a!=2)
	{
		printf("\nGotta make my job hard don't ya?");
		printf("\nWould you like to play the game? (1=Y/2=N): ");
		scanf("%d",&a);}
	//Error Check
	//---------------------------------------------------------------------------------------
		
	
	while(a==1){
		
		printf("\nWould you like a description of the game and difficulties?\n(1)Yes (2)No\nYour entry: ");
		scanf("%d",&gd);
		//Asking if they want to hear a description
	//---------------------------------------------------------------------------------------
		
		while(gd!=1 && gd!=2)
	{
		printf("\nGotta make my job hard don't ya? All ya gotta do is hit 1 or 2");
		printf("\nWould you like a description of the game and difficulties?\n(1)Yes (2)No\nYour entry: ");
		scanf("%d",&gd);}
	//Error Check
	//---------------------------------------------------------------------------------------
	
	if(gd==1){
		printf("\n\nThis game is a simple adventure game where you will explore making descions at different crossroads.");
		printf("\nYour goal is to collect items useful to fighting an enemy at the end.");
		printf("\nYou will not be offered the option to go back and must continue forward.");
		printf("\n\nDifficulties: \nEasy: You will have 10 turns before facing the boss to collect useful tools for the fight.");
		printf("\nMedium: You will have 7 turns before facing the boss to collect useful tools for the fight.");
		printf("\nHard: You will have 4 turns before facing the boss to collect useful tools for the fight.");
		printf("\nYou Will Fail: You will have 2 turns before facing the boss to collect useful tools for the fight. \nYou have very little chance of collecting tools and you are very likely to fail.\nIt is a game of chance at this point. \nWill you take the gamble? ");
		
		
	}
	//Description
	//---------------------------------------------------------------------------------------
		
		//Difficulty selection
		printf("\nWhich difficulty would you like to play on? (1)Easy (2)Medium (3)Hard (4)You Will Fail: ");
		scanf("%d",&d);
	//---------------------------------------------------------------------------------------
		
		//Error check
		
		while(d<1 || d>4)
		{
			printf("\nNice try, you must choose a difficulty");
			printf("\nWhich difficulty would you like to play on? (1)Easy (2)Medium (3)Hard (4)You Will Fail: ");
			scanf("%d",&d);
		}
	//---------------------------------------------------------------------------------------
	
	//Vars that must be in the loop as to reset them if the player chooses to go again
	int fc; //false choice
	int tool=0;
	int gld=0; 
	//---------------------------------------------------------------------------------------
		
		printf("\nWelcome to the game. To start you will have no items and will start a a random crossroad.\n");
		
		switch(d){
			case 1: //Easy
				for(i=0;i<10;i++){
				np=(rand()%7);
				
				//possible outcomes, some may repeat
				switch(np){
					case 0: 
						printf("\nAt this crossroad there is nothing of note.");
						break;
					case 1:
						printf("\nAt this crossroad you have found 2 pieces of gold.");
						gld=gld+2;
						break;
					case 2:
						printf("\nAt this crossroad you find nothing but notice that it is cold and dark in this area.");
						break;
					case 3:
						printf("\nAlong your way you enter a small town, the blacksmith gives you a sword and sheild for protection.");
						printf("\nYou leave the town and arrive at the next crossroad.");
						tool=1;
						break;
					case 4: 
						printf("\nYou come to the crossroad and discover a small chest.");
						printf("\nYou open it and find 20 gold pieces.");
						gld=gld+20;
						break;
					case 5:
						printf("\nAt this crossroad you notice it looks like the place has been scorched.");
						printf("\nYou find a note on the ground and go to pick it up, but it disintegrates in your hand");
						break;
					case 6:
						printf("\nAs you approach the crossroad you notice a few odd shapes.");
						printf("\nOnce you arrive to the crossroad you notice it is a party of fallen adventures.");
						printf("\nThe area around them is covered in burn marks. \nYou decide to press forward.");
						break;
					
				}	
	//---------------------------------------------------------------------------------------
					
				//false choice	
				printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
				scanf("%d",&fc);
	//---------------------------------------------------------------------------------------
		
				//error check
				while(fc<1 || fc>3){
					printf("\nCowardice is not the way of the adventurer. You must continue!");
					printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
					scanf("%d",&fc);
				}
	//---------------------------------------------------------------------------------------		
				
				}
				break;
				
	//---------------------------------------------------------------------------------------
			case 2: //Medium
				for(i=0;i<7;i++){
					np=(rand()%7);
				
				//possible outcomes, some may repeat
				switch(np){
					case 0: 
						printf("\nAt this crossroad there is nothing of note.");
						break;
					case 1:
						printf("\nAt this crossroad you have found 2 pieces of gold.");
						gld=gld+2;
						break;
					case 2:
						printf("\nAt this crossroad you find nothing but notice that it is cold and dark in this area.");
						break;
					case 3:
						printf("\nAlong your way you enter a small town, the blacksmith gives you a sword and sheild for protection.");
						printf("\nYou leave the town and arrive at the next crossroad.");
						tool=1;
						break;
					case 4: 
						printf("\nYou come to the crossroad and discover a small chest.");
						printf("\nYou open it and find 20 gold pieces.");
						gld=gld+20;
						break;
					case 5:
						printf("\nAt this crossroad you notice it looks like the place has been scorched.");
						printf("\nYou find a note on the ground and go to pick it up, but it disintegrates in your hand");
						break;
					case 6:
						printf("\nAs you approach the crossroad you notice a few odd shapes.");
						printf("\nOnce you arrive to the crossroad you notice it is a party of fallen adventures.");
						printf("\nThe area around them is covered in burn marks. \nYou decide to press forward.");
						break;
					
				}	
	//---------------------------------------------------------------------------------------
					
				//false choice	
				printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
				scanf("%d",&fc);
	//---------------------------------------------------------------------------------------
		
				//error check
				while(fc<1 || fc>3){
					printf("\nCowardice is not the way of the adventurer. You must continue!");
					printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
					scanf("%d",&fc);
				}
	//---------------------------------------------------------------------------------------		
					
				}
				break;
				
	//---------------------------------------------------------------------------------------
			case 3:  //Hard
				
				for(i=0;i<4;i++){
					np=(rand()%7);
				
				//possible outcomes, some may repeat
				switch(np){
					case 0: 
						printf("\nAt this crossroad there is nothing of note.");
						break;
					case 1:
						printf("\nAt this crossroad you have found 2 pieces of gold.");
						gld=gld+2;
						break;
					case 2:
						printf("\nAt this crossroad you find nothing but notice that it is cold and dark in this area.");
						break;
					case 3:
						printf("\nAlong your way you enter a small town, the blacksmith gives you a sword and sheild for protection.");
						printf("\nYou leave the town and arrive at the next crossroad.");
						tool=1;
						break;
					case 4: 
						printf("\nYou come to the crossroad and discover a small chest.");
						printf("\nYou open it and find 20 gold pieces.");
						gld=gld+20;
						break;
					case 5:
						printf("\nAt this crossroad you notice it looks like the place has been scorched.");
						printf("\nYou find a note on the ground and go to pick it up, but it disintegrates in your hand");
						break;
					case 6:
						printf("\nAs you approach the crossroad you notice a few odd shapes.");
						printf("\nOnce you arrive to the crossroad you notice it is a party of fallen adventures.");
						printf("\nThe area around them is covered in burn marks. \nYou decide to press forward.");
						break;
					
				}	
	//---------------------------------------------------------------------------------------
					
				//false choice	
				printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
				scanf("%d",&fc);
	//---------------------------------------------------------------------------------------
		
				//error check
				while(fc<1 || fc>3){
					printf("\nCowardice is not the way of the adventurer. You must continue!");
					printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
					scanf("%d",&fc);
				}
	//---------------------------------------------------------------------------------------		
					
				}
				break;
				
	//---------------------------------------------------------------------------------------
			case 4: //You Will Fail
				for(i=0;i<2;i++){
					
					np=(rand()%7);
				
				//possible outcomes, some may repeat
				switch(np){
					case 0: 
						printf("\nAt this crossroad there is nothing of note.");
						break;
					case 1:
						printf("\nAt this crossroad you have found 2 pieces of gold.");
						gld=gld+2;
						break;
					case 2:
						printf("\nAt this crossroad you find nothing but notice that it is cold and dark in this area.");
						break;
					case 3:
						printf("\nAlong your way you enter a small town, the blacksmith gives you a sword and sheild for protection.");
						printf("\nYou leave the town and arrive at the next crossroad.");
						tool=1;
						break;
					case 4: 
						printf("\nYou come to the crossroad and discover a small chest.");
						printf("\nYou open it and find 20 gold pieces.");
						gld=gld+20;
						break;
					case 5:
						printf("\nAt this crossroad you notice it looks like the place has been scorched.");
						printf("\nYou find a note on the ground and go to pick it up, but it disintegrates in your hand");
						break;
					case 6:
						printf("\nAs you approach the crossroad you notice a few odd shapes.");
						printf("\nOnce you arrive to the crossroad you notice it is a party of fallen adventures.");
						printf("\nThe area around them is covered in burn marks. \nYou decide to press forward.");
						break;
					
				}	
	//---------------------------------------------------------------------------------------
					
				//false choice	
				printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
				scanf("%d",&fc);
	//---------------------------------------------------------------------------------------
		
				//error check
				while(fc<1 || fc>3){
					printf("\nCowardice is not the way of the adventurer. You must continue!");
					printf("\nWhich direction will you go? \n(1)Left (2)Straight (3)Right\nYour choice: ");
					scanf("%d",&fc);
				}
	//---------------------------------------------------------------------------------------		
					
				}
				break;
			}
	//---------------------------------------------------------------------------------------
	
	//Boss fight
	//If armed
	if(tool==1){
		printf("\n\nYou here a thundering roar and move towards it.");
		printf("\nFor protection you draw your sword and shield and approach with caution.");
		printf("\nYou come to a burnt clearing to see a massive crimson dragon sitting there.");
		printf("\nYou step on a twig and the dragon immediately locks eyes with you, then takes off.");
		printf("\nIt swoops back down spitting fire at you.");
		printf("\nYou raise your shield to protect you from the flames.");
		printf("\nJust as the dragon goes over your head you lash out with your sword.");
		printf("\nYou turn around just as the dragon falls to the ground with a loud thump.");
		printf("\nYou approach the dragon and find that you have slayed the beast.");
		printf("\nNearby you find its cave and inside is a large chest.");
		printf("\nYou open it to find 200 gold pieces inside.");
		gld=gld+200;
		printf("\n\nCongratulations!! \nYou slayed the dragon and collected %dpieces of gold.",gld);
		printf("\nWell done");
	}
	//---------------------------------------------------------------------------------------
	
	//if unarmed
		if(tool==0){
		printf("\n\nYou here a thundering roar and move towards it.");
		printf("\nYou come to a burnt clearing to see a massive crimson dragon sitting there.");
		printf("\nYou step on a twig and the dragon immediately locks eyes with you, then takes off.");
		printf("\nIt swoops back down spitting fire at you.");
		printf("\nUnfortunatley you have no protection and are burned to a crisp.");
		printf("\nYou lose all items and the dragon enjoys BBQ Adventurer for dinner.");
		printf("\n\nYou lost");
		}
	
	//Play again?		
			printf("\nWould you like to play again? 1=Y 2=N\nYour entry: ");
			scanf("%d",&a);
	//---------------------------------------------------------------------------------------		
			
	//Error Check		
			while(a!=1 && a!=2)
			{
				printf("\nReally? Thought I wouldn't check ya at the end too? Guess again *insert maniacal laugh*");
				printf("\nWould you like to play again? 1=Y 2=N\nYour entry: ");
				scanf("%d",&a);}
	
	//---------------------------------------------------------------------------------------
		
			
		}
	
	return 0;
	
}