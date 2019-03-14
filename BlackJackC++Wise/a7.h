// Jamal Williams 
#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;


void initialize (int& userValue, char& userArg, int& computerValue, char& computerArg)
{
    int range1, range2, result1, result2;
    range1 = 11 - 1 + 1;
    range2 = 11 - 1 + 1;
    result1 = rand() % range1;
    result2 = rand() % range2;
    result1 += 1; // card value for user
    result2 += 1; // card value for computer
    cout<<"Dealing 2 Cards.."<<endl;
    cout<<"You have recieved a "<<result1<<endl;
    cout<<"The computer has recieved a "<<result2<<endl;
    userValue = result1 + 0; //total score of user
    computerValue = result2 + 0; //total score of computer
    result1 = rand() % range1; //next card for user
    result2 = rand() % range2; //next card for computer
    cout<<"You have recieved a "<<result1<<endl;
    cout<<"The computer has recieved a "<<result2<<endl;
    cout<<"____________________________"<<endl;
    userValue += result1; //add on to the total score
    computerValue += result2; //add on to the total score
    if (computerValue > 17)
    {
        computerArg = 'n';
    }
    userArg = 'y';
    computerArg = 'y';
}


char scoreUpdate(int userValue, int computerValue)
{
    char anotherCard;
    cout<<"Your score: "<<userValue<<endl;
    cout<<"Computer's score: "<<computerValue<<endl;
    cout<<"Would you like to hit? (y or n) "<<endl;
    cin>>anotherCard;
    return anotherCard;
}


void hit (int& userValue, char userHit, int& computerValue, char computerArg)
{
    int range1, range2, result1, result2;
    int count1 = 0;
    int count = 0;
    range1 = 11 - 1 + 1;
    range2 = 11 - 1 + 1;
    result1 = rand() % range1;
    result2 = rand() % range2;
    result1 += 1;
    result2 += 1;
    
    
    
    //IF user wants to hit
    if ((userHit != 'n'))
    {
        count++;
        cout<<"Hit Count:"<<count<<endl;  //number of times user ask for another card
        
        result1 = rand() % range1; //generate another card
        userValue += result1; //add to the total score
        cout<<"You have recieved a "<<result1<<endl;
        //cout<<"Your score: "<<userValue<<endl;
        if ((userValue > 21) || (userValue == 21))
        {
            //count > 3; //escape the loop
            userHit = 'n'; //escape the loop
            
        } 
    } else if (computerArg == 'y') //If user doesn't Hit, Draw computer card.
        {
            while (computerArg != 'n') {
                count1++; //number of times computer ask for another card
                cout<<"Hit CCount:"<<count1<<endl;  //number of times user ask for another card
                result2 = rand() % range2; //generate another card
                computerValue += result2; //add to the total score
                cout<<"The computer have recieved a "<<result1<<endl;
                cout<<"Computer score: "<<computerValue<<endl;
                if (computerValue > 17)
                {
                computerArg = 'n'; //escape the loop
                    
                }
                else if (computerValue >= 21) //Computer Bust
                {
                    computerArg = 'n';
                }
                cout<<"Computer Done Hitting"<<endl;
            }
        }
    
    
//end of hit func
}

void displayResult(int userValue, int computerValue)
{
    if (userValue == computerValue){
        cout<<"Draw"<<endl;
    }
    else if ((userValue > computerValue) && (userValue <= 21)){
        cout<<"You win"<<endl;
        cout<<"Final scores"<<endl;
        cout<<"You - "<<userValue<<endl;
        cout<<"Computer - "<<computerValue<<endl;
    }
    else if ((computerValue > userValue) && (computerValue <= 21))
    {
        cout<<"Computer win"<<endl;
        cout<<"Final scores"<<endl;
        cout<<"You - "<<userValue<<endl;
        cout<<"Computer - "<<computerValue<<endl;
    }
    else if ((userValue > computerValue) && (userValue > 21)){
        cout<<"Computer win"<<endl;
        cout<<"Final scores"<<endl;
        cout<<"You - "<<userValue<<endl;
        cout<<"Computer - "<<computerValue<<endl;
    }
if ((userValue > 21) && (computerValue > 21))
{
	cout<<"draw"<<endl;
    if (userValue > 21)
        {
            cout<<"You have busted."<<endl;
            cout<<"Computer win"<<endl;
            cout<<"Final scores"<<endl;
            cout<<"You - "<<userValue<<endl;
            cout<<"Computer - "<<computerValue<<endl;
        }
    if (computerValue > 21)
        {
            cout<<"The computer has busted."<<endl;
            cout<<"You win"<<endl;
            cout<<"Final scores"<<endl;
            cout<<"You - "<<userValue<<endl;
            cout<<"Computer - "<<computerValue<<endl;
        }
}
//end of display result
}

void playAgain(char& anotherGame)
{
cout<<"Would you like to play again?";
cin>>anotherGame;
}























