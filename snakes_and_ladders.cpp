#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




int main()


{ 
   int ladders_bottom[8] = {2,57,7,21,77,40,80,66};
   int ladders_top[8] = {15,93,18,31,90,67,99,89};

   int snake_head[8] = {14,19,27,58,63,79,98,92};
   int snake_tail[8] = {3,1,5,10,20,33,22,35};

   int numberOfPlayers;

   string players[10];
   
   int players_pos[10]={0,0,0,0,0,0,0,0,0,0};

   cout << "\n\nEnter number of players: ";
   cin >> numberOfPlayers;

   for(int i=0; i<numberOfPlayers; i++)
   {   
       cout << "Enter player "<< i+1 << "'s" <<" name: ";
       cin >> players[i];
   }

   //cout << players[0];
   //cout << " " << numbers[9];

   int i=0;
   int x=0;
   int p=0;
   int sum;
   string abc;
   srand(time(0));

   while(x!=-1)
   {
   
       while(p!=-1)
       {   
           if(i==numberOfPlayers)
           {
               i=0;
           }

           cout << "\n" <<players[i] <<" 's turn enter 'r' to roll the dice: ";
           cin >> abc;
           if(abc=="r") 
                { 
                     
                    p = -1; 
                     
                }
            
           else{
                 cout <<"Invalid input\n";
           }
       }

       p = 0; // for the upper loop to work in the next iteration
       int dice = (1+rand()%6);      
       cout << "\nDice rolls and shows: " << dice;
       
       // 

      if (players_pos[i]+dice<=100)
      {
          cout << "\nSo now... " << players[i] << " moves to " << players_pos[i]+dice;
          players_pos[i] = players_pos[i]+dice;
      } 

      else if (players_pos[i]+dice>100)
      {
          cout << "\nNo increment for " << players[i];
      }
       

       for(int j=0; j<8; j++)
       {
           if(players_pos[i]==ladders_bottom[j])
           {
               cout << ", finds a ladder their and climbs to " << ladders_top[j];
               players_pos[i] = ladders_top[j];
               break;
           }

           else if(players_pos[i]==snake_head[j])
           {
               cout << ", a snake bites them their and they reach " << snake_tail[j];
               players_pos[i] = snake_tail[j];
               break;
           }

           else{
               break;
           }
       }
       // updates 
       cout << "\n\nupdates:\n";

       for(int k=0; k<numberOfPlayers; k++)
       {
            cout << players[k] <<" is at " << players_pos[k] << endl;
            if(players_pos[k]==100)
            {
                cout << players[k] << " wins !!!";
                x = -1;
                break;
            }
       }
       
       i++; // for players name change
       
       


   }



    cout <<"\n\nProgram exits master loop. Game over. come back soon :)\n";

    return 0;
}