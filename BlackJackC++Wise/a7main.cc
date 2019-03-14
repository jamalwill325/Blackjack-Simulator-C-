#include<cstdlib> //needed for srand call below
#include<ctime> //needed for time(0) call below
#include "a7.h" //needed for the functions you write in the required .h file

using namespace std;


   int main()
{
    int user_score, computer_score; //scores for user, computer
    char again, ucont, ccont;
    //again - play again variable
    //ucont - continue prompting user for desire of more cards
    //ccont - continue drawing cards for computer until either >= 17, or bust
    int seed = time(0); //necessary for truly random numbers
    srand(seed);
    
    
    cout<<"Welcome to JWORLD's Casino for Blackjack"<<endl;
    
      do{
         initialize(user_score, ucont, computer_score, ccont);
         //initialize draws two cards for each the user and computer
         ucont = scoreUpdate(user_score, computer_score);
          
         //prompt the user for another card via scoreUpdate after initial
      	//two-card draw
          while (ucont != 'n'){
              hit(user_score, ucont, computer_score, ccont);
              //draws remaining cards; calls scoreUpdate after each card drawn for the user,
              //until the user either busts or doesn't want another card
              ucont = scoreUpdate(user_score, computer_score);
          }
          if (ucont == 'n') {
              ccont = 'y';
              hit(user_score, ucont, computer_score, ccont);
              
          }
         
         displayResult(user_score, computer_score);
         //once done, call displayResult to declare a winner or tie
         playAgain(again);
         //prompt the user to play again
      }while(again != 'n');
      
      return 0;
   }
