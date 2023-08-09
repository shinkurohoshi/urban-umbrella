#include <iostream>
#include <ctime>

using std::cout; using std::endl; using std::cin;

char PlayerChoice();
char OpponentChoice();
void getChoice(char choice);
void PlayResults(char player, char opponent);


int main(){
    char player;
    char opponent;
    char playAgain;

    do{
    player = PlayerChoice();
    cout<< "Player Choice:";
    getChoice(player);

    opponent = OpponentChoice();
    cout<< "\nOpponent's Choice:";
    getChoice(opponent);
   
    cout<< "\nResults: ";
    PlayResults(player, opponent);

    cout<< "\nDo you want to continue?: (y/n)"<< endl;
    cin>> playAgain;
    }while(playAgain != 'n');
    

    return 0;
}

char PlayerChoice(){
    char player;

    do{
    cout<<"\n******************************"<<endl;
    cout<<"\nEnter your action (Rock =r, Paper = p, Scissors = s)"<<endl;
    cout<<"\n******************************"<<endl;
    cin>>player;

    }while(player != 'r' && player != 'p' && player != 's');
    
    return player;
}
char OpponentChoice(){
    srand(time(NULL));
    int comp = rand() % 3 + 1;

    switch (comp)
    {
    case 1: return 'r'; 
    case 2: return 'p'; 
    case 3: return 's';
    }
    return comp;
}
void getChoice(char choice){
    switch (choice)
    {
    case 'r':cout<< " Rock"; break;
    case 'p':cout<< " Paper"; break;
    case 's':cout<< " Scissors"; break;
    }

}
void PlayResults(char player, char opponent){
    switch (player)
    {
    case 'r': if (opponent=='r'){cout<< "You are tied";}
              else if (opponent=='p'){cout<< "You lost";}
              else {cout<< "You won";}
              break;
    case 'p': if (opponent=='r'){cout<< "You won";}
              else if (opponent=='p'){cout<< "You are tied";}
              else {cout<< "You lost";}
              break;
    case 's': if (opponent=='r'){cout<< "You lost";}
              else if (opponent=='p'){cout<< "You won";}
              else {cout<< "You are tied";}
              break;
  
    }
}