/*
 * Kovacs_630pm_CL5_ahf12.cpp
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


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define USER_PASSWORD 2468

//function for balance
void optionA(double array[]){
	printf("Checking Account Balance: %lf\nSavings Account Balance: %lf",array[0],array[1]);
	}
	
//deposit function --UNUSED
double optionB(double array[]){
	//printf("Checking Account Balance: %lf\nSavings Account Balance: %lf",array[0],array[1]);
	char depositSelection;
	double depositAmount;
	
	do{
		printf("\nWhich account do you want to deposit to?\na. checking account\nb.Savings Account\n");
		fflush(stdin);		
		scanf("%c",&depositSelection);
	}while(depositSelection!='a' && depositSelection!='b');
	
	if(depositSelection=='a'){
		//CA Deposit
		do{
			printf("\nEnter the emount you want to deposit: ");
			fflush(stdin);		
			scanf("%lf",&depositAmount);
		}while(depositAmount<=0);
		
		array[0] = array[0]+depositAmount;
		
		}else if(depositSelection=='b'){
			//SA Deposit
			}
			
		return array[0];
	
	}

int main(int argc, char **argv)
{
	//Out of loop variable definitions
	double myCash[2];
	FILE *inFilePt;
	FILE *outFilePt;
	int inFlag_EOF;
	//int outFlag_EOF;
	int inFileIndex=0;
	//int outFileIndex;
	int transactionCount=0;
	bool programRun = true;
	
	
	//------------------------------------------------------------------
	//Password Checker - 5 tries
	int password;
	int retryCount=0;
	do{
		printf("Enter Correct Password:");
		scanf("%d",&password);
		retryCount++;
		}while(password!=USER_PASSWORD && retryCount < 5);
	//Check if no of tries 5 and lock accoubt
	if(password!=USER_PASSWORD && retryCount < 5){
		printf("\n ACCOUNT LOCKED");
		programRun=false;
	}
	//------------------------------------------------------------------
	
	while(programRun==true){
		
		//--------------------------------------------------------------
		//Get data from file
		inFileIndex=0;
		inFilePt = fopen("balances.txt","r");
		for(inFlag_EOF = fscanf(inFilePt, "%lf", &myCash[inFileIndex]); 
		inFlag_EOF != EOF; 
		inFlag_EOF = fscanf(inFilePt, "%lf", &myCash[inFileIndex]))
		{
			//printf("%lf\t %d\n",myCash[inFileIndex],inFileIndex);
			inFileIndex++;
			}
		fclose(inFilePt);
		//--------------------------------------------------------------
		
		//--------------------------------------------------------------
		//Option selection error checking
		char optionSelection;
		do{
			printf("\nValid OPTIONS\na. Display Balance\nb. Deposit\nc. Withdrawal\nd. Transfer\n Enter your option: ");
			fflush(stdin);
			scanf("%c",&optionSelection);
			//printf("%c", selection);
		}while(optionSelection != 'd' && optionSelection != 'c' && optionSelection != 'b' && optionSelection != 'a');//need to check for capitalisastion
		//--------------------------------------------------------------
		
		//--------------------------------------------------------------
		//Option run
		switch(optionSelection){
			
			case 'a':
			//printf("\nCase A");
			optionA(myCash);
			break;
			
			case 'b':
			//printf("\nCase B");
			//optionB(myCash);
			//printf("Checking Account Balance: %lf\nSavings Account Balance: %lf",array[0],array[1]);
			char depositSelection;
			double depositAmount;
			
			do{
				printf("\nWhich account do you want to deposit to?\na. checking account\nb.Savings Account\n");
				fflush(stdin);		
				scanf("%c",&depositSelection);
			}while(depositSelection!='a' && depositSelection!='b');
			
			if(depositSelection=='a'){
				//CA Deposit
				do{
					printf("\nEnter the amount you want to deposit: ");
					fflush(stdin);		
					scanf("%lf",&depositAmount);
				}while(depositAmount<=0);
				
				myCash[0] = myCash[0]+depositAmount;
				
				}else if(depositSelection=='b'){
					//SA Deposit
					do{
						printf("\nEnter the amount you want to deposit: ");
						fflush(stdin);		
						scanf("%lf",&depositAmount);
					}while(depositAmount<=0);
					
					myCash[1] = (myCash[1]+depositAmount)*1.07;
				}
				printf("\nCurrent Account Balance: %lf \nSavings Account Balance: %lf",myCash[0],myCash[1]);
				break;
			
			case 'c':
			//printf("\nCase C");
			//optionC(myCash);
			char withdrawSelection;
			double withdrawAmount;
			do{
					printf("\nWhich account do you want to withdraw from?\na. checking account\nb.Savings Account\n");
					fflush(stdin);		
					scanf("%c",&withdrawSelection);
				}while(withdrawSelection!='a' && withdrawSelection!='b');
			//which account to withde=raw from
			switch (withdrawSelection){
				case 'a':
				do{
					printf("\nEnter the amount you want to withdraw: ");
					fflush(stdin);		
					scanf("%lf",&withdrawAmount);
					}while(withdrawAmount<=0 || withdrawAmount>=(myCash[0]));
					
				myCash[0] = (myCash[0]-withdrawAmount);
				printf("\nBalance: %lf",myCash[0]);
				break;
				
				case 'b':
				do{
					printf("\nEnter the amount you want to withdraw: ");
					fflush(stdin);		
					scanf("%lf",&withdrawAmount);
					}while(withdrawAmount<=0 || withdrawAmount>=(myCash[1]-2.00));
					
				myCash[1] = (myCash[1]-withdrawAmount-2.00);
				printf("\nBalance: %lf",myCash[1]);
				
				break;
				}
				
			break;
			
			case 'd':
			//printf("\nCase D");
			//optionD(myCash);
			char transferSelection;
			double transferAmount;
			do{
					printf("\nSelect Transfer option\na. checking account to savings account\nb.Savings Account to checking account\n");
					fflush(stdin);		
					scanf("%c",&transferSelection);
				}while(transferSelection!='a' && transferSelection!='b');
			//option a
			switch (transferSelection){
				case 'a':
				do{
					printf("\nEnter the amount you want to transfer to savings account: ");
					fflush(stdin);		
					scanf("%lf",&transferAmount);
					}while(transferAmount<=0 && transferAmount>=(myCash[0]));
					
				myCash[0] = (myCash[0]-transferAmount);
				myCash[1] = (myCash[1]+transferAmount);
				printf("\nCurrent Account Balance: %lf \nSavings Account Balance: %lf",myCash[0],myCash[1]);
				break;
				
				case 'b':
				do{
					printf("\nEnter the amount you want to transfer to checking account: ");
					fflush(stdin);		
					scanf("%lf",&transferAmount);
					}while(transferAmount<=0 && transferAmount>=(myCash[1]));
					
				myCash[1] = (myCash[1]-transferAmount);
				myCash[0] = (myCash[0]+transferAmount);
				printf("\nCurrent Account Balance: %lf \nSavings Account Balance: %lf",myCash[0],myCash[1]);				
				break;
				}
				
			break;
			
			}
		//--------------------------------------------------------------
		
		
		
		transactionCount++;
		if(transactionCount==10){
			printf("\nCongratulations you get $1,000,000 in chekcing account\nSavings acocount is now 0");
			myCash[0]=myCash[0]+1000000;
			myCash[1]=0;
			}
			
			
		//write balacnes to file
		outFilePt = fopen("balances.txt","w");
		fprintf(outFilePt,"%lf",myCash[0]);
		fprintf(outFilePt,"\n%lf",myCash[1]);
		fclose(outFilePt);		
		
		//ask user whther to perform another transaction
		char rerun;	
		do{
			printf("\nDo you want to perform another transaction?(y or n): ");
			fflush(stdin);
			scanf("%c",&rerun);
			//printf("%c", selection);
			}while(rerun != 'y' && rerun != 'n');//need to check for capitalisastion
		if(rerun=='y'){
			programRun=true;
			}else{
				programRun=false;
				}
		}	
		
	return 0;
}



