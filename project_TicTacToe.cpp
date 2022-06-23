




















#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char table_values[9]={'1','2','3','4','5','6','7','8','9'};

void print_table();
int select_mode();
bool check_winner();
void player_vs_player();
void player_vs_computer();

int main()
{
    int mode;
    cout<<"Welcome to Tic Tac Toe"<<endl<<endl;
    mode=select_mode();
    if(mode==1)
    {
        player_vs_player();
    }
    else
    {
        player_vs_computer();
    }
}

void player_vs_player()
{
    int i;
    int turn_choice;
    char marker;
    bool winner_decided=false;
    string player_1,player_2,current_player;

    string error;
    getline(cin,error); // calling this function in main somehow skips first getline command so i created this one to skip that error
    //creating pvp ------------------------------------------
    cout<<"Enter your name Player 1(X): "; // char X for player 1
    getline(cin,player_1);
    cout<<endl;

    cout<<"Enter your name Player 2(O): "; // char O for player 2
    getline(cin,player_2);
    cout<<endl;


    for(i=1;i<=9;i++) //loop run 9 because there are total 9 turns in tic tac toe
    {
        print_table();

        if(i%2!=0) // odd number for player 1
        {
            current_player=player_1;
            marker='X';
        }
        else
        {
            current_player=player_2;
            marker='O';
        }

        cout<<current_player<<"'s turn ("<<marker<<") . Choose a number from table: ";
        cin>>turn_choice;
        turn_choice=turn_choice-1; // decrementing because array is from 0 to 8

        if(cin.fail()) //i-- decrements the value of i in loop so program asks for a number again in case of invalid input
        {
            cin.clear();
            cin.ignore();
            cout<<"Invalid input."<<endl;
            i--;
            continue;
        }
        else if(turn_choice<0 || turn_choice>8)
        {
            cout<<"Invalid input."<<endl;
            i--;
            continue;
        }
        else if(table_values[turn_choice]=='X' || table_values[turn_choice]=='O')
        {
            cout<<"Invalid input."<<endl;
            i--;
            continue;
        }
        else
        {
            table_values[turn_choice]=marker;
            cout<<"Nice move!"<<endl;
        }

        if(i>4)
        {
            winner_decided=check_winner();
            if(winner_decided==true)
            {   print_table();
                cout<<endl<<"Congratulations "<< current_player<<"! You won the game!"<<endl;
                break;
            }
        }

    }

    if(winner_decided==false)
    {   print_table();
        cout<<"It's a draw";
    }
}

void player_vs_computer()
{
   int i;
    int turn_choice;
    char marker;
    bool winner_decided=false;
    string player_1;

    string error;
    getline(cin,error); // avoiding error generating
    cout<<"Enter your name (X): "; // char X for player 1
    getline(cin,player_1);
    cout<<endl;

    for(i=1;i<=9;i++)
    {



        if(i%2!=0) // odd number for player 1
        {
            print_table();

            marker='X';
            cout<<"Your turn "<<player_1<<" ("<<marker<<") . Choose a number from table: ";
            cin>>turn_choice;

        }
        else
        {

            marker='O';
            srand(time(0));
            turn_choice=rand()%8+1; //going to generate a number between 1-9
        }

        turn_choice=turn_choice-1; // decrementing because array is from 0 to 8

        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            if(i%2!=0)
            {cout<<"Invalid input."<<endl;}
            i--;
            continue;
        }
        else if(turn_choice<0 || turn_choice>8)
        {
            if(i%2!=0)
            {cout<<"Invalid input."<<endl;}
            i--;
            continue;
        }
        else if(table_values[turn_choice]=='X' || table_values[turn_choice]=='O')
        {
            if(i%2!=0)
            {cout<<"Invalid input."<<endl;}
            i--;
            continue;
        }
        else
        {
            table_values[turn_choice]=marker;

        }

        if(i>4)
        {
            winner_decided=check_winner();
            if(winner_decided==true)
            {   print_table();
                if(i%2!=0)
                {cout<<endl<<"Congratulations "<< player_1<<"! You won the game!"<<endl;}
                else
                {
                    cout<<"Computer won the game. Better luck next time "<<player_1<<endl;
                }
                break;
            }
        }

    }

    if(winner_decided==false)
    {   print_table();
        cout<<"It's a draw";
    }
}

void print_table()
{

    cout<<endl<<" "<<table_values[0]<<" | "<<table_values[1]<<" | "<<table_values[2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<table_values[3]<<" | "<<table_values[4]<<" | "<<table_values[5]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<table_values[6]<<" | "<<table_values[7]<<" | "<<table_values[8]<<endl<<endl;

}

int select_mode()
{
    int choice=0;
    do{
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
    cout<<"Game has the following two modes" <<endl<<endl;;
    cout<<"Press 1 for player vs player"<<endl;
    cout<<"Press 2 to play against computer"<<endl<<endl;
    cout<<"Choose your mode: ";
    cin>>choice;
    if(choice!=1 && choice !=2)
    {
        cout<<"Invalid option "<<endl<<endl;
    }



    }while(choice!=1 && choice !=2); // choice is limited to 1 and 2 only
    cout<<endl;
    return choice;
}

bool check_winner()
{
    bool decision_of_winner;

    if(table_values[0]==table_values[1] && table_values[1]==table_values[2]) ////this and following 2 are for horizontal check
    {
        decision_of_winner=true;
    }
    else if(table_values[3]==table_values[4] && table_values[4]==table_values[5])
    {
        decision_of_winner=true;
    }
    else if(table_values[6]==table_values[7] && table_values[7]==table_values[8])
    {
        decision_of_winner=true;
    }
    else if(table_values[0]==table_values[3] && table_values[3]==table_values[6]) //this and following 2 are for vertical check
    {
        decision_of_winner=true;
    }
    else if(table_values[1]==table_values[4] && table_values[4]==table_values[7])
    {
        decision_of_winner=true;
    }
    else if(table_values[2]==table_values[5] && table_values[5]==table_values[8])
    {
        decision_of_winner=true;
    }
    else if(table_values[0]==table_values[4] && table_values[4]==table_values[8]) // this and the next one is for diagonal check
    {
        decision_of_winner=true;
    }
    else if(table_values[2]==table_values[4] && table_values[4]==table_values[6]) // this and the next one is for diagonal check
    {
        decision_of_winner=true;
    }
    else //all winning possibilities have been checked
    {
        decision_of_winner=false;
    }
    return decision_of_winner;
}
